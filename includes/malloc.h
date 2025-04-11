#ifndef MALLOC_H
# define MALLOC_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/resource.h>
#include <pthread.h>
#include <sys/mman.h>
#include "../libft/includes/libft.h"

# define TINY_PAGE_SIZE (4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_PAGE_SIZE / 128)
# define SMALL_PAGE_SIZE (16 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_PAGE_SIZE / 128)

typedef enum e_zoneMemoireType
{
    TINY,
    SMALL,
    LARGE,
} t_zoneMemoireType;

typedef struct display_memory
{
    size_t      total_block;
    size_t      total_size;
    size_t      total_page_tiny;
    size_t      total_page_small;
    size_t      total_page_large;    
} display_memory_t;

typedef struct block_memory
{
    size_t              len;
	struct block_memory	*prev;
	struct block_memory	*next;
	bool			    is_free;
} block_memory_t;

typedef struct page_memory
{
    struct page_memory *next;
    struct page_memory *prev;
    size_t              total_len;
    size_t              free_len;
    size_t              block_count;
    t_zoneMemoireType   type;
} page_memory_t;

extern page_memory_t        *g_page_memory;
extern pthread_mutex_t		g_mutex;


// =========================== Main Function ===================

void                    *malloc(size_t size);
void                    *start_malloc(size_t size);

void                    free(void *ptr);
void                    start_free(void *ptr);

// =========================== Block Section ===================
void                    init_block(block_memory_t *block, size_t size);

block_memory_t          *try_fill_block(size_t size);
void                    divide_block(block_memory_t *block, size_t size, page_memory_t *heap);

void                    find_available_block(size_t size, page_memory_t **res_heap, block_memory_t **res_block);
block_memory_t          *get_last_block(block_memory_t *block);
void                    find_block_of_ptr(void *ptr, page_memory_t **res_page, block_memory_t **res_block, page_memory_t *page);

block_memory_t          *merge_block(page_memory_t *page, block_memory_t *block);

void                    remove_block(page_memory_t *page, block_memory_t *block);

// =========================== Page Section ===================
t_zoneMemoireType       get_page_type(size_t size);
page_memory_t           *get_page_with_block_size(const size_t size);
page_memory_t           *get_page_free(page_memory_t *start, t_zoneMemoireType group, size_t require_size);
size_t                  get_page_size(size_t size);
page_memory_t           *get_last_page(page_memory_t *page);

page_memory_t           *create_page(t_zoneMemoireType type, size_t block_size);

void                    *add_empty_block(page_memory_t *page, size_t size);

// =========================== Utils ===================
void                    *page_shift(void *start);
void                    *block_shift(void *start);
rlim_t                  get_system_limit(void);

page_memory_t *get_heap_last(page_memory_t *heap);

void    show_alloc_mem(void);

#endif 