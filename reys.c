#include "ft_cub.h"

void	line_h_clac(t_all *all)
{
	all->rc.lineheight = (int)(all->map->hight / all->rc.perpwalldist);
	all->rc.drawstart = all->map->hight / 2 - all->rc.lineheight / 2;
	if (all->rc.drawstart < 0)
		all->rc.drawstart = 0;
	all->rc.drawend = all->rc.lineheight / 2 + all->map->hight / 2;
	if (all->rc.drawend >= all->map->hight)
		all->rc.drawend = all->map->hight - 1;
}

static void	ft_dda(t_all *all)
{
	while (all->rc.hit == 0)
	{
		if (all->rc.sidedistx < all->rc.sidedisty)
		{
			all->rc.sidedistx += all->rc.deltadistx;
			all->rc.mapx += all->rc.stepx;
			all->rc.side = 0;
		}
		else
		{
			all->rc.sidedisty += all->rc.deltadisty;
			all->rc.mapy += all->rc.stepy;
			all->rc.side = 1;
		}
		if (all->map->map_m[all->rc.mapy][all->rc.mapx] == '1')
			all->rc.hit = 1;
	}
	if (all->rc.side == 0)
		all->rc.perpwalldist = (all->rc.mapx - all->player->x \
		+ (1 - all->rc.stepx) / 2) / all->rc.raydirx;
	else
		all->rc.perpwalldist = (all->rc.mapy - all->player->y \
		+ (1 - all->rc.stepy) / 2) / all->rc.raydiry;
}

static void	ft_steps(t_all *all)
{
	if (all->rc.raydirx < 0)
	{
		all->rc.stepx = -1;
		all->rc.sidedistx = (all->player->x - all->rc.mapx) \
		* all->rc.deltadistx;
	}
	else
	{
		all->rc.stepx = 1;
		all->rc.sidedistx = (all->rc.mapx + 1.0 - all->player->x) \
		* all->rc.deltadistx;
	}
	if (all->rc.raydiry < 0)
	{
		all->rc.stepy = -1;
		all->rc.sidedisty = (all->player->y - all->rc.mapy) \
		* all->rc.deltadisty;
	}
	else
	{
		all->rc.stepy = 1;
		all->rc.sidedisty = (all->rc.mapy + 1.0 - all->player->y) \
		* all->rc.deltadisty;
	}
}

void	ft_init_rc(t_all *all, int x)
{
	all->rc.camerax = 2 * x / (double)all->map->width - 1;
	all->rc.raydirx = all->player->dir_x + all->player->plane_x \
	* all->rc.camerax;
	all->rc.raydiry = all->player->dir_y + all->player->plane_y \
	* all->rc.camerax;
	all->rc.mapx = (int)all->player->x;
	all->rc.mapy = (int)all->player->y;
	all->rc.deltadistx = fabs(1 / all->rc.raydirx);
	all->rc.deltadisty = fabs(1 / all->rc.raydiry);
}

int	ft_cast_ray(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->map->width)
	{
		ft_init_rc(all, x);
		ft_steps(all);
		all->rc.hit = 0;
		ft_dda(all);
		ft_set_wall(all, x);
		malloc_alloc(all);
		all->zbuff[x] = all->rc.perpwalldist;
		sprite(all, x);
		x++;
	}
	free(all->mass_sp);
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, \
	all->data.img, 0, 0);
	return (0);
}
