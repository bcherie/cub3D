#include "ft_cub.h"

void	sp_wh(t_all *all)
{
	all->spritescreen_x = (int)((all->map->width / 2) \
	* (1 + all->transfx / all->transfy));
	all->sp_heigth = (int)fabs((all->map->hight / all->transfy) / 1);
	all->dr_starty = -all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
	if (all->dr_starty < 0)
		all->dr_starty = 0;
	all->dr_drendy = all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
	if (all->dr_drendy >= all->map->hight)
		all->dr_drendy = all->map->hight - 1;
	all->sp_width = (int)fabs((all->map->hight / all->transfy) / 1);
	all->dr_startx = -all->sp_width / 2 + all->spritescreen_x;
	if (all->dr_startx < 0)
		all->dr_startx = 0;
	all->dr_drendx = all->sp_width / 2 + all->spritescreen_x;
	if (all->dr_drendx >= all->map->width)
		all->dr_drendx = all->map->width - 1;
}

void	sp_all_mem(t_all *all)
{
	all->sprites = (t_sprites *)malloc(sizeof(t_sprites) * all->num_sp);
	all->sprites->order = 0;
	all->mass_sp = ft_calloc((all->num_sp + 1), sizeof(double *));
	while (all->sprites->order < all->num_sp)
	{
		all->mass_sp[all->sprites->order] = ft_calloc(2, sizeof(double));
		if (!all->mass_sp[all->sprites->order])
			printf("Error\nError allocate memory");
		all->sprites->order++;
	}
}

void	ft_coord_sprite(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	sp_all_mem(all);
	all->sprites->order = 0;
	while (all->map->map_m[i])
	{
		j = 0;
		while (all->map->map_m[i][j])
		{
			if (all->map->map_m[i][j] == '2')
			{
				all->mass_sp[all->sprites->order][0] = j + 0.5;
				all->mass_sp[all->sprites->order][1] = i + 0.5;
				all->sprites->order++;
			}
			j++;
		}
		i++;
	}
}

void	calc_dr_sp(t_all *all, int *tmp_order, int x)
{
	all->sp_x = all->mass_sp[tmp_order[all->sprites->order]][0] \
	- all->player->x;
	all->sp_y = all->mass_sp[tmp_order[all->sprites->order]][1] \
	- all->player->y;
	all->invd = 1.0 / (all->player->plane_x * all->player->dir_y \
	- all->player->dir_x * all->player->plane_y);
	all->transfx = all->invd * (all->player->dir_y * all->sp_x \
	- all->player->dir_x * all->sp_y);
	all->transfy = all->invd * (-all->player->plane_y \
	* all->sp_x + all->player->plane_x * all->sp_y);
	all->spritescreen_x = (int)((all->map->width / 2) \
	* (1 + all->transfx / all->transfy));
	all->mvscreen = 0;
	sp_wh(all);
	x = all->dr_startx;
	draw_sp(all, x);
}

int	sprite(t_all *all, int x)
{
	int		*tmp_order;
	double	*dist;

	ft_coord_sprite(all);
	tmp_order = malloc(sizeof(int) * all->num_sp);
	dist = malloc(sizeof(double) * all->num_sp);
	if (!tmp_order || !dist)
		return (-1);
	all->sprites->order = 0;
	while (all->sprites->order < all->num_sp)
	{
		tmp_order[all->sprites->order] = all->sprites->order;
		dist[all->sprites->order] = sqrt(pow(all->player->x - all->mass_sp[all->sprites->order][0], 2) \
		+ pow(all->player->y - all->mass_sp[all->sprites->order][1], 2));
		all->sprites->order++;
	}
	sprite_sort(tmp_order, dist, all->num_sp);
	all->sprites->order = 0;
	while (all->sprites->order < all->num_sp)
	{
		calc_dr_sp(all, tmp_order, x);
		all->sprites->order++;
	}
	return (0);
}
