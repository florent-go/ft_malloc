#include "../includes/malloc.h"

static size_t print_block_of_page(block_memory_t *block)
{
    char  *addr_start;
    char  *addr_end;
    size_t total;

    total = 0;
    addr_start = NULL;
    addr_end = NULL;
    while (block)
    {
        addr_start = (char *)block_shift(block);
        addr_end = addr_start + block->len;
        if (!block->is_free)
        {
            ft_putstr("\t");
            ft_itoa_base((size_t)addr_start, 16,9);
            ft_putstr(" - ");
            ft_itoa_base((size_t)addr_end, 16,9);
            ft_putstr(" : ");
            ft_itoa_base(block->len, 10, 0);
            ft_putstr(" octets\n");
            total += block->len;
        }
        block = block->next;
    }
    return (total);
}

static void print_page(char *name, page_memory_t *page)
{
    ft_putstr(name);
    ft_putstr(" : ");
    ft_itoa_base((size_t)page, 16,9);
    ft_putstr("\n");
}

static void print_page_type(page_memory_t *page, display_memory_t *display)
{
    if (page->type == TINY) {
        print_page("TINY", page);
        display->total_page_tiny += 1;
    }
    else if (page->type == SMALL) {
        print_page("SMALL", page);
        display->total_page_small += 1;
    }
    else if (page->type == LARGE) {
        print_page("LARGE", page);
        display->total_page_large += 1;
    }
}

static void print_number_of_blocks_in_page(page_memory_t *last_page)
{
    ft_putstr("Number of blocks in page : ");
    ft_itoa_base((size_t)last_page->block_count, 10,0);
    ft_putstr("\n");
}

static void print_display(display_memory_t *display)
{
    ft_putstr("Total size use : ");
    ft_itoa_base(display->total_size, 10,0);
    ft_putstr("\nTotal block use :");
    ft_itoa_base(display->total_block, 10,0);
    ft_putstr("\nTotal tiny page : ");
    ft_itoa_base(display->total_page_tiny, 10,0);
    ft_putstr("\nTotal small page : ");
    ft_itoa_base(display->total_page_small, 10,0);
    ft_putstr("\nTotal large page : ");
    ft_itoa_base(display->total_page_large, 10,0);
    ft_putstr("\n");
}

void    show_alloc_mem(void)
{
    pthread_mutex_lock(&g_mutex);
    display_memory_t    *display;
    page_memory_t       *last_page;

    display = (display_memory_t *)mmap(NULL, sizeof(display_memory_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0);
    last_page = get_last_page(g_page_memory);
    while (last_page)
    {
        print_page_type(last_page, display);
        if (last_page->block_count)
        {
            display->total_size += print_block_of_page((block_memory_t *)page_shift(last_page));
            print_number_of_blocks_in_page(last_page);
            display->total_block += last_page->block_count;
        }
        last_page = last_page->prev;
    }
    print_display(display);
    pthread_mutex_unlock(&g_mutex);
}