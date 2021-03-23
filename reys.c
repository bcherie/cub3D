#include "ft_cub.h"

void	ft_cast_ray(t_plr *player)
{
	t_plr	ray = plr->plrayer; // задаем координаты луча равные координатам игрока

	while (win->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		mlx_pixel_put(win->mlx, win->win, ray.x, ray.y, 0x990099);
	}
}