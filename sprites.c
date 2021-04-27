#include "ft_cub.h"

void sp_wh(t_all *all)
{
    all->spritescreen_x = (int)((all->map->width / 2) * (1 + all->transfx / all->transfy));
    all->sp_heigth = (int)fabs((all->map->hight / all->transfy) / 1);
    //calculate lowest and highest pixel to fill in current stripe
    all->dr_starty = -all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
    if(all->dr_starty < 0)
        all->dr_starty = 0;
    all->dr_drendy = all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
    if(all->dr_drendy >= all->map->hight)
        all->dr_drendy = all->map->hight - 1;

    //calculate width of the sprite
    all->sp_width = (int)fabs((all->map->hight / all->transfy) / 1);
    all->dr_startx = -all->sp_width / 2 + all->spritescreen_x;
    if(all->dr_startx < 0)
        all->dr_startx = 0;
    all->dr_drendx = all->sp_width / 2 + all->spritescreen_x;
    if(all->dr_drendx >= all->map->width)
        all->dr_drendx = all->map->width - 1;

}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void sprite_sort(int *order, double *dist, int amount)
{
	t_pair	*sprite;
    int i;

    i = 0;
	sprite = (t_pair*)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		sprite[i].first = dist[i];
		sprite[i].second = order[i];
        i++;
	}
	sort_order(sprite, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprite[amount - i - 1].first;
		order[i] = sprite[amount - i - 1].second;
	}
	free(sprite);

}

void ft_coord_sprite(t_all *all)
{
	int i;
	int j;

	i = 0;
    all->sprites = (t_sprites *)malloc(sizeof(t_sprites) * all->num_sp);
	all->sprites->order = 0;
    //ft_bzero(all->sprites, sizeof(t_sprites));
    all->mass_sp = ft_calloc((all->num_sp + 1), sizeof(double *));
	while (all->sprites->order < all->num_sp)
	{
        if (!(all->mass_sp[all->sprites->order] = ft_calloc(2, sizeof(double))))
			printf("ОШИБКА\n");
		all->sprites->order++;
	}

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

void		sprite(t_all *all, int x)
{
	int i;
	i = 0;

	ft_coord_sprite(all);
	int *tmp_order;
	double  *dist;
	tmp_order = malloc(sizeof(int) * all->num_sp);
	dist = malloc(sizeof(double) * all->num_sp);
	all->sprites->order = 0;
	while (all->sprites->order < all->num_sp)
	{
		tmp_order[all->sprites->order] = all->sprites->order;
		dist[all->sprites->order] = sqrt(pow(all->player->x - all->mass_sp[all->sprites->order][0], 2) + pow(all->player->y - all->mass_sp[all->sprites->order][1], 2));
		all->sprites->order++;
	}
	sprite_sort(tmp_order, dist, all->num_sp);
	all->sprites->order = 0;
	while (all->sprites->order < all->num_sp)
	{
		//translate sprite position to relative to camera
		all->sp_x = all->mass_sp[tmp_order[all->sprites->order]][0] - all->player->x;
		all->sp_y = all->mass_sp[tmp_order[all->sprites->order]][1] - all->player->y;
		double invDet = 1.0 / (all->player->plane_x * all->player->dir_y - all->player->dir_x * all->player->plane_y); //required for correct matrix multiplication

		all->transfx = invDet * (all->player->dir_y * all->sp_x - all->player->dir_x * all->sp_y);
		all->transfy = invDet * (-all->player->plane_y * all->sp_x + all->player->plane_x * all->sp_y); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
		all->spritescreen_x = (int)((all->map->width / 2) * (1 + all->transfx / all->transfy));

		//parameters for scaling and moving the sprites
		all->mvscreen = (int)(MOVE / all->transfy);
        sp_wh(all);
		x = all->dr_startx;
		draw_sp(all, x);
		all->sprites->order++;
	}
}