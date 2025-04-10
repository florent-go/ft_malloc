#include "../include/malloc.h"

void setup_block(block_memory_t *block, size_t size)
{
    block->prev = NULL;
    block->next = NULL;
    block->len = size;
    block->freed = false;
}

void *Add_Empty_Block(page_memory_t *heap, size_t size)
{
    block_memory_t *new_block;
    block_memory_t *last_block;

    new_block = (block_memory_t *)HEAP_SHIFT(heap);
    last_block = NULL;

    setup_block(new_block, size);
    heap->block_count++;
    heap->free_len -= (new_block->len + sizeof(block_memory_t));

    return ((void *)BLOCK_SHIFT(new_block));
}

void find_available_block(size_t size, page_memory_t **res_heap, block_memory_t **res_block)
{
    page_memory_t *heap;
    block_memory_t *block;
    t_zoneMemoireType group;

    heap = g_page_memory;
    group = get_heap_group(size);

    while (heap)
    {
        block = (block_memory_t *)HEAP_SHIFT(heap);
        while (heap->type == group && block)
        {
            if (block->freed && (block->len >= size + sizeof(block_memory_t)))
            {
                *res_heap = heap;
                *res_block = block;
                return ;
            }
            block = block->next;
        }
        heap = heap->next;
    }
    *res_heap = NULL;
    *res_block = NULL;
}

static void divide_block(block_memory_t *block, size_t size, page_memory_t *heap)
{
    block_memory_t *free_block;

    free_block = BLOCK_SHIFT(block) + size;
    setup_block(free_block, block->next - free_block);
    free_block->freed = true;
    free_block->prev = block;
    free_block->next = block->next;
    heap->block_count++;
    block->next = free_block;
    block->len = size;
    block->freed = false;
}

block_memory_t *try_fill_block(size_t size)
{
    block_memory_t *block;
    page_memory_t *heap;

    find_available_block(size, &heap, &block);
    if (block && heap)
    {
        divide_block(block, size, heap);
        return block;
    }
    return NULL;
}