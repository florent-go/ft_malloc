#include "../includes/malloc.h"

int test_malloc_new_page()
{
	int 	nb_malloc = 2000;
	char	*(s1[nb_malloc]);
	int		i;
	int 	j;

	i = -1;
	while (++i < nb_malloc)
	{
		if (!(s1[i] = malloc(100)))
			return (0);
		j = -1;
		while (++j < 100)
			s1[i][j] = 'a' + j % 26;
		s1[i][j] = '\0';
		if (ft_strlen(s1[i]) != (size_t)100)
		{
			printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (0);
		}
	}
}

int main()
{
	void *ptr;
	// ptr = malloc(20);
    test_malloc_new_page();
    show_alloc_mem();
    return 0;
}