#include "ft_cub.h"

void	init_pl_ns(t_map_p *map, t_plr *player, int x, int y)
{
	if (map->map_m[y][x] == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = player->dir_y * 0.66;
		player->plane_y = 0;
	}
	if (map->map_m[y][x] == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = player->dir_y * 0.66;
		player->plane_y = 0;
	}
}

void	init_pl_we(t_map_p *map, t_plr *player, int x, int y)
{
	if (map->map_m[y][x] == 'W')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_y = -0.66;
		player->plane_x = 0;
	}
	if (map->map_m[y][x] == 'E')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_y = 0.66;
		player->plane_x = 0;
	}
}

void	ft_init_plr(t_map_p *map, t_plr *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_m[y])
	{
		x = 0;
		while (map->map_m[y][x])
		{
			if (ft_strchr("NEWS", map->map_m[y][x]))
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
				init_pl_ns(map, player, x, y);
				init_pl_we(map, player, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
}
