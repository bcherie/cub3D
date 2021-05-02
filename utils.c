#include "ft_cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_exit(t_all *all)
{
	close (all->fd);
	exit (0);
}

int	ft_exit_malloc(void)
{
	printf("Error\nMalloc error");
	exit(0);
}

int	malloc_alloc(t_all *all)
{
	all->zbuff = malloc(sizeof(double) * all->map->width);
	if (!all->zbuff)
		return (-1);
	return (0);
}
