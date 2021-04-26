#include "ft_cub.h"

void draw_sp(t_all *all, int x)
{
    int		y;

	while (x < all->dr_drendx)
	{
		all->s_texx = (int)(256 * (x - (-all->sp_width / 2 + \
		all->spritescreen_x)) * all->sp.img_width / all->sp_width) / 256;
		if (all->transfy > 0 && x > 0 && x < all->map->width && \
		all->transfy < all->zBuffer[x])
		{
			y = all->dr_starty;
			while (y < all->dr_drendy)
			{
				all->d = y * 256 - all->map->hight * 128 + all->sp_heigth * 128;
				all->s_texy = ((all->d * all->sp.img_height) / \
				all->sp_heigth) / 256;
				all->s_clr = *(unsigned int*)(all->sp.img_addr + \
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