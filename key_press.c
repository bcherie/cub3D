#include "ft_cub.h"

void	key_press_ws(int key, t_all *all)
{
	if (key == W)
	{
		if (all->map->map_m[(int)(all->player->y + all->player->dir_y * \
		0.5)][(int)(all->player->x)] != '1')
			all->player->y += all->player->dir_y * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x + \
		all->player->dir_x * 0.5)] != '1')
			all->player->x += all->player->dir_x * 0.5;
	}
	if (key == S)
	{
		if (all->map->map_m[(int)(all->player->y - all->player->dir_y * \
		0.5)][(int)(all->player->x)] != '1')
			all->player->y -= all->player->dir_y * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x - \
		all->player->dir_x * 0.5)] != '1')
			all->player->x -= all->player->dir_x * 0.5;
	}
}

void	key_press_rl(int key, t_all *all)
{
	if (key == D)
	{
		if (all->map->map_m[(int)(all->player->y - all->player->dir_x * \
		0.5)][(int)(all->player->x)] != '1')
			all->player->y -= all->player->dir_x * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x - \
		all->player->plane_x * 0.5)] != '1')
			all->player->x += all->player->plane_x * 0.5;
	}
	if (key == A)
	{
		if (all->map->map_m[(int)(all->player->y + all->player->dir_x * \
		0.5)][(int)(all->player->x)] != '1')
			all->player->y += all->player->dir_x * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x + \
		all->player->dir_y * 0.5)] != '1')
			all->player->x -= all->player->dir_y * 0.5;
	}
}

void	key_press_ror_r(int key, t_all *all)
{
	if (key == ARROW_R)
	{
		all->dir_x_old = all->player->dir_x;
		all->player->dir_x = all->player->dir_x * cos(all->rorate) - \
		all->player->dir_y * sin(all->rorate);
		all->player->dir_y = all->dir_x_old * sin(all->rorate) + \
		all->player->dir_y * cos(all->rorate);
		all->plane_x_old = all->player->plane_x;
		all->player->plane_x = all->player->plane_x * cos(all->rorate) - \
		all->player->plane_y * sin(all->rorate);
		all->player->plane_y = all->plane_x_old * sin(all->rorate) + \
		all->player->plane_y * cos(all->rorate);
	}
}

void	key_press_ror_l(int key, t_all *all)
{
	if (key == ARROW_L)
	{
		all->dir_x_old = all->player->dir_x;
		all->player->dir_x = all->player->dir_x * cos(-all->rorate) - \
		all->player->dir_y * sin(-all->rorate);
		all->player->dir_y = all->dir_x_old * sin(-all->rorate) + \
		all->player->dir_y * cos(-all->rorate);
		all->plane_x_old = all->player->plane_x;
		all->player->plane_x = all->player->plane_x * cos(-all->rorate) - \
		all->player->plane_y * sin(-all->rorate);
		all->player->plane_y = all->plane_x_old * sin(-all->rorate) + \
		all->player->plane_y * cos(-all->rorate);
	}
}

int	keypress(int key, t_all *all)
{
	all->rorate = 0.05;
	all->moveSpeed = 0.08;
	key_press_ws(key, all);
	key_press_rl(key, all);
	key_press_ror_r(key, all);
	key_press_ror_l(key, all);
	if (key == ESC)
		exit(0);
	ft_cast_ray(all);
	return (0);
}
