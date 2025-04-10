#include "../include/malloc.h"

t_zoneMemoireType get_heap_group(size_t size)
{
    if (size <= (size_t)TINY_BLOCK_SIZE)
        return (TINY);
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
        return (SMALL);
    return (LARGE);
}

page_memory_t *get_heap_last(page_memory_t *heap)
{
    if (!heap)
        return (NULL);
    while(heap->next)
        heap = heap->next;
    return (heap);
}

size_t get_heap_size(size_t size)
{
    t_zoneMemoireType group;

    group = get_heap_group(size);
    if (group == TINY)
        return ((size_t)TINY_HEAP_ALLOCATION_SIZE);
    else if (group == SMALL)
        return ((size_t)SMALL_HEAP_ALLOCATION_SIZE);
    return (size + sizeof(page_memory_t) + sizeof(block_memory_t));
}

static rlim_t get_system_limit(void)
{
    struct  rlimit rpl;

    if (getrlimit(RLIMIT_DATA, &rpl) < 0)
        return (-1);
    return (rpl.rlim_max);
}

page_memory_t *create_heap(t_zoneMemoireType group, size_t block_size)
{
    size_t heap_size;
    page_memory_t *heap;

    heap_size = get_heap_size(block_size);
    if (heap_size > get_system_limit())
        return (NULL);
    heap = (page_memory_t *)mmap(NULL, heap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0);
    if (heap == MAP_FAILED)
        return (NULL);
    ft_bzero(heap, sizeof(heap));
    heap->type = group;
    heap->total_len = heap_size;
    heap->free_len = heap_size - sizeof(page_memory_t);
    return (heap);
}

page_memory_t *get_available_heap(page_memory_t *start, t_zoneMemoireType group, size_t require_size)
{
    page_memory_t *heap_el;

    heap_el = (page_memory_t *)start;
    while (heap_el)
    {
        if ((heap_el->type == group) && (heap_el->free_len >= require_size))
            return (heap_el);
        heap_el = heap_el->next;
    }
    return (NULL);
}

page_memory_t *get_heap_of_block(const size_t size)
{
    page_memory_t       *default_heap;
    t_zoneMemoireType   heap_group;
    page_memory_t       *heap;

    default_heap = g_page_memory;
    heap_group = get_heap_group(size);
    heap = get_available_heap(default_heap, heap_group, size + sizeof(block_memory_t));

    if (heap == NULL)
    {
        if (!(heap = create_heap(heap_group, size)))
            return (NULL);
        heap->next = default_heap;
        if (heap->next)
            heap->next->prev = heap;
        g_page_memory = heap;
    }
    return (heap);
}