#include "ft_cub.h"

void	ft_set_tex_ns(t_all *all)
{
	all->no.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_no, \
	&all->no.img_width, &all->no.img_height);
	if (!all->no.img)
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->no.img_addr = mlx_get_data_addr(all->no.img, &all->no.bpp, \
	&all->no.llength, &all->no.end);
	all->so.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_so, \
	&all->so.img_width, &all->so.img_height);
	if (!all->so.img)
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->so.img_addr = mlx_get_data_addr(all->so.img, &all->so.bpp, \
	&all->so.llength, &all->so.end);
}

void	ft_set_tex_we(t_all *all)
{
	all->ea.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_ea, \
	&all->ea.img_width, &all->ea.img_height);
	if (!all->ea.img)
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->ea.img_addr = mlx_get_data_addr(all->ea.img, &all->ea.bpp, \
	&all->ea.llength, &all->ea.end);
	all->we.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_we, \
	&all->we.img_width, &all->we.img_height);
	if (!all->we.img)
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->we.img_addr = mlx_get_data_addr(all->we.img, &all->we.bpp, \
	&all->we.llength, &all->we.end);
}

void	ft_set_tex_sp(t_all *all)
{
	all->sp.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_sprite, \
	&all->sp.img_width, &all->sp.img_height);
	if (!all->sp.img)
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->sp.img_addr = mlx_get_data_addr(all->sp.img, &all->sp.bpp, \
	&all->sp.llength, &all->sp.end);
}
