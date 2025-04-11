#include "../includes/malloc.h"

void            *page_shift(void *start)
{
    return (void *)((char *)start + sizeof(page_memory_t));
}

void            *block_shift(void *start)
{
    return (void *)((char *)start + sizeof(block_memory_t));
}

rlim_t          get_system_limit(void)
{
    struct  rlimit rpl;

    if (getrlimit(RLIMIT_DATA, &rpl) < 0)
        return (-1);
    return (rpl.rlim_max);
}