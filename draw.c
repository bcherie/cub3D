#include "ft_cub.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->data.img_addr + (y * all->data.llength + \
	x * (all->data.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_sp(t_all *all, int x)
{
	int	y;

	while (x < all->dr_drendx)
	{
		all->s_texx = (int)(256 * (x - (-all->sp_width / 2 + \
		all->spritescreen_x)) * all->sp.img_width / all->sp_width) / 256;
		if (all->transfy > 0 && x > 0 && x < all->map->width && \
		all->transfy < all->zbuff[x])
		{
			y = all->dr_starty;
			while (y < all->dr_drendy)
			{
				all->d = y * 256 - all->map->hight * 128 + all->sp_heigth * 128;
				all->s_texy = ((all->d * all->sp.img_height) / \
				all->sp_heigth) / 256;
				all->s_clr = *(unsigned int *)(all->sp.img_addr + \
				(all->s_texy * all->sp.llength + all->s_texx * \
				(all->sp.bpp / 8)));
				if ((all->s_clr & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all, x, y, all->s_clr);
				y++;
			}
		}
		x++;
	}
}

void	draw_tex(t_all *all, int i, int x)
{
	all->rc.texy = (int)all->rc.texpos & (all->current.img_height - 1);
	all->rc.color = *(unsigned int *)(all->current.img_addr + (all->rc.texy \
	* all->current.llength + all->rc.texx * (all->current.bpp / 8)));
	if (all->rc.side == 1)
	{
		if (all->rc.raydiry < 0)
			my_mlx_pixel_put(all, x, i, all->rc.color);
		else if (all->rc.raydiry > 0)
			my_mlx_pixel_put(all, x, i, all->rc.color);
	}
	else if (all->rc.side == 0)
	{
		if (all->rc.raydirx > 0)
			my_mlx_pixel_put(all, x, i, all->rc.color);
		else if (all->rc.raydirx < 0)
			my_mlx_pixel_put(all, x, i, all->rc.color);
	}
	all->rc.texpos += all->rc.step;
}
