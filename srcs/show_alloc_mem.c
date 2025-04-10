#include "../include/malloc.h"

static size_t print_block_of_heap(block_memory_t *block)
{
    char  *addr_start;
    char  *addr_end;
    size_t total;

    total = 0;
    addr_start = NULL;
    addr_end = NULL;
    while (block)
    {
        addr_start = (char *)BLOCK_SHIFT(block);
        addr_end = addr_start + block->len;
        if (!block->freed)
        {
            ft_itoa_base((size_t)addr_start, 16,9, true);
            ft_putstr(" - ");
            ft_itoa_base((size_t)addr_end, 16,9, true);
            ft_putstr(" : ");
            ft_itoa_base(block->len, 10, 0, false);
            ft_putstr(" octets\n");
            total += block->len;
        }
        block = block->next;
    }
    return (total);
}

static void print_heap(char *name, page_memory_t *heap)
{
    ft_putstr(name);
    ft_putstr(" : ");
    ft_itoa_base((size_t)heap, 16,9, true);
    ft_putstr("\n");
}

void    show_alloc_mem(void)
{
    page_memory_t *first_heap;
    page_memory_t *last_heap;
    size_t total;

    total = 0;
    first_heap = g_page_memory;
    last_heap = get_heap_last(first_heap);
    while (last_heap)
    {
        if (last_heap->type == TINY)
            print_heap("TINY", last_heap);
        else if (last_heap->type == SMALL)
            print_heap("SMALL", last_heap);
        else if (last_heap->type == LARGE)
            print_heap("LARGE", last_heap);
        if (last_heap->block_count)
            total += print_block_of_heap((block_memory_t *)HEAP_SHIFT(last_heap));
        last_heap = last_heap->prev;
    }
}