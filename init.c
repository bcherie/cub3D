#include "ft_cub.h"

void ft_init(t_map_p *map)
{
	map->width = 0;
	map->hight = 0;
	map->path_no = NULL;
	map->path_so = NULL;
	map->path_we = NULL;
	map->path_ea = NULL;
	map->path_sprite = NULL;
	map->floor = 0;
	map->ceil = 0;
	map->next = NULL;
	map->R = 0;
	map->B = 0;
	map->G = 0;
	map->C_R = 0;
	map->C_G = 0;
	map->C_B = 0;
	map->map_m = NULL;
}

void ft_init_w(t_window *win)
{
	//win->win = NULL;
	win->mlx = NULL;
	win->mlx_w = NULL;
	win->img = 0;
    win->addr = NULL;
    win->bits_per_pixel = 0;
    win->line_length = 0;
    win->endian = 0;
}

void ft_init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
}

void ft_init_scale(t_scale *mashtab)
{
	mashtab->one = 0;
	mashtab->two = 0;
}