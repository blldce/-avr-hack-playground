

#include "stdlib_private.h"

short check_mem_type_init();
void *create_new_space(size_t);
void *walk_in_list(size_t);

extern char *__malloc_heap_start = &__heap_start;
extern char *__malloc_heap_end = &__heap_end;

extern char *__brkval; // end of .data section

struct memory_type *head_mem_ptr = ((void *)0);

struct memory_type
{
    size_t mem_size;
    short inuse;
    struct memory_type *next_mem_ptr;
};

void *
malloc(size_t size)
{
    if (check_mem_type_init())
        return walk_in_list(size);
    return create_new_space(size);
}

void *
create_new_space(size_t size)
{
    if (__brkval == 0)
        __brkval = __malloc_heap_start;
    // check pre-process
    size_t remains_heap = __malloc_heap_end - __brkval;
    if ((__malloc_heap_end <= __brkval) || (remains_heap <= size) || (*__malloc_heap_end <= (size + *__brkval)))
    {
        // Memory exhausted or no memory left or over request memory from remains SRAM.
        // no diff error returns, just nullptr
        return ((void *)0);
    }

    struct memory_type *curr_mem_addr = (struct memory_type *)__brkval;
    curr_mem_addr->mem_size = size;
    curr_mem_addr->inuse = 1;

    if (head_mem_ptr) // has data
    {
        curr_mem_addr->next_mem_ptr = head_mem_ptr;
    }
    else // 0
    {
        curr_mem_addr->next_mem_ptr = ((void *)0); // NULL
    }

    head_mem_ptr = curr_mem_addr;
    __brkval += size + sizeof(size_t) + sizeof(short);

    return (void *)curr_mem_addr;
}

void *
walk_in_list(size_t size)
{
    struct memory_type *walk_mem_ptr;
    // look for freed memory_type with fit size, so we dont need to create new space.
    for (walk_mem_ptr = head_mem_ptr; walk_mem_ptr != ((void *)0); walk_mem_ptr = walk_mem_ptr->next_mem_ptr)
    {
        if (!walk_mem_ptr->inuse && walk_mem_ptr->mem_size >= size)
        { // found it, update mem_type with used and return it.

            size_t remaining_size = walk_mem_ptr->mem_size - size;
            struct memory_type *baby_mem_addr = (struct memory_type *)(walk_mem_ptr + remaining_size);
            baby_mem_addr->mem_size = remaining_size;
            baby_mem_addr->inuse = 0;
            baby_mem_addr->next_mem_ptr = walk_mem_ptr;
            // OK TOO : baby_mem_addr->next_mem_ptr = walk_mem_ptr->next_mem_ptr;
            // OK TOO : walk_mem_ptr->next_mem_ptr = baby_mem_addr;
            if (walk_mem_ptr = head_mem_ptr)
            {
                head_mem_ptr = baby_mem_addr;
            }

            walk_mem_ptr->mem_size = size;
            walk_mem_ptr->inuse = 1;
            return (void *)walk_mem_ptr;
        }
    }
    // not found, create new space
    return create_new_space(size);
}

short check_mem_type_init()
{
    if (head_mem_ptr != ((void *)0)) // non-null
        return 1;
    return 0;
}

short free_mem(void *addr)
{
    /* ISO C says free(NULL) must be a no-op */
    if (addr == 0)
        return 0;
    struct memory_type *walk_mem_ptr;
    for (walk_mem_ptr = head_mem_ptr; walk_mem_ptr != ((void *)0); walk_mem_ptr = walk_mem_ptr->next_mem_ptr)
    {
        if (walk_mem_ptr == (struct memory_type *)addr)
        { // found it, update memory type & combine next memory type if that also freed
            // no need to update __brkval, we ll walk in list.
            walk_mem_ptr->inuse = 0;
            if (walk_mem_ptr->next_mem_ptr != ((void *)0) && walk_mem_ptr->next_mem_ptr->inuse == 0)
            {
                size_t combined_size = walk_mem_ptr->mem_size + walk_mem_ptr->next_mem_ptr->mem_size;
                walk_mem_ptr->mem_size = combined_size;
                walk_mem_ptr->next_mem_ptr = walk_mem_ptr->next_mem_ptr->next_mem_ptr;
            }
            return 1;
        }
    }
    return 0;
}