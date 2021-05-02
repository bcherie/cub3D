#include "ft_cub.h"

void	ft_texture(t_all *all)
{
	if (all->rc.side == 0 && all->rc.raydirx > 0)
		all->current = all->ea;
	if (all->rc.side == 0 && all->rc.raydirx < 0)
		all->current = all->we;
	if (all->rc.side == 1 && all->rc.raydiry > 0)
		all->current = all->so;
	if (all->rc.side == 1 && all->rc.raydiry < 0)
		all->current = all->no;
}

void	coord_tex(t_all *all)
{
	if (all->rc.side == 0)
		all->rc.wallx = all->player->y + all->rc.perpwalldist * all->rc.raydiry;
	else
		all->rc.wallx = all->player->x + all->rc.perpwalldist * all->rc.raydirx;
	all->rc.wallx -= floor((all->rc.wallx));
	all->rc.texx = (int)(all->rc.wallx * (double)(all->current.img_width));
	if (all->rc.side == 0 && all->rc.raydirx > 0)
		all->rc.texx = all->current.img_width - all->rc.texx - 1;
	if (all->rc.side == 1 && all->rc.raydiry < 0)
		all->rc.texx = all->current.img_width - all->rc.texx - 1;
	all->rc.step = 1.0 * all->current.img_height / all->rc.lineheight;
	all->rc.texpos = (all->rc.drawstart - all->map->hight / 2 \
	+ all->rc.lineheight / 2) * all->rc.step;
}

void	ft_set_wall(t_all *all, int x)
{
	int	i;

	i = 0;
	line_h_clac(all);
	while (i < all->rc.drawstart)
	{
		my_mlx_pixel_put(all, x, i, all->map->ceil);
		i++;
	}
	ft_texture(all);
	coord_tex(all);
	draw_tex(all, i, x);
	while (i < all->rc.drawend)
	{
		draw_tex(all, i, x);
		i++;
	}
	while (i < all->map->hight)
	{
		my_mlx_pixel_put(all, x, i, all->map->floor);
		i++;
	}
}
