#include "ft_cub.h"

void			ft_sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	j = 0;
	while (j < cub->file.scnt - 1)
	{
		i = 0;
		while (i < cub->file.scnt - j - 1)
		{
			if (cub->sprite[i].dist < cub->sprite[i + 1].dist)
			{
				tmp = cub->sprite[i];
				cub->sprite[i] = cub->sprite[i + 1];
				cub->sprite[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void			ft_order_sprites(t_cub *cub, int i)
{
	while (i < cub->file.scnt)
	{
		cub->sprite[i].ord = i;
		cub->sprite[i].dist = pow(cub->pov.x - \
		cub->sprite[i].x, 2) + pow(cub->pov.y - cub->sprite[i].y, 2);
		i++;
	}
}

void			ft_set_sprites(t_cub *cub, int i, int j)
{
	int			x;

	x = 0;
	if (!(cub->sprite = (t_sprite *)malloc(sizeof(t_sprite) * cub->file.scnt)))
		exit_cub(cub, 34);
	while (i < cub->file.map.rows)
	{
		j = 0;
		while (cub->file.map.map[i][j])
		{
			if (cub->file.map.map[i][j] == '2')
			{
				cub->sprite[x].y = i + 0.5;
				cub->sprite[x].x = j + 0.5;
				x++;
			}
			j++;
		}
		i++;
	}
}

static void		ft_init_sprites(t_cub *cub, int i)
{
	cub->rcs.spritex = cub->sprite[cub->sprite[i].ord].x - cub->pov.x;
	cub->rcs.spritey = cub->sprite[cub->sprite[i].ord].y - cub->pov.y;
	cub->rcs.invdet = 1.0 / (cub->pov.planex * cub->pov.dir.y - \
	cub->pov.dir.x * cub->pov.planey);
	cub->rcs.transformx = cub->rcs.invdet * (cub->pov.dir.y * \
	cub->rcs.spritex - cub->pov.dir.x * cub->rcs.spritey);
	cub->rcs.transformy = cub->rcs.invdet * (-cub->pov.planey * \
	cub->rcs.spritex + cub->pov.planex * cub->rcs.spritey);
	cub->rcs.screenx = (int)((cub->file.w / 2) * (1 + \
	cub->rcs.transformx / cub->rcs.transformy));
	cub->rcs.h = abs((int)(cub->file.h / cub->rcs.transformy));
	cub->rcs.w = abs((int)(cub->file.h / cub->rcs.transformy));
}

void			ft_rc_sprites(t_cub *cub)
{
	int			i;

	ft_order_sprites(cub, 0);
	ft_sort_sprites(cub);
	i = 0;
	while (i < cub->file.scnt)
	{
		ft_init_sprites(cub, i);
		cub->rcs.drawstarty = -cub->rcs.h / 2 + cub->file.h / 2;
		if (cub->rcs.drawstarty < 0)
			cub->rcs.drawstarty = 0;
		cub->rcs.drawendy = cub->rcs.h / 2 + cub->file.h / 2;
		if (cub->rcs.drawendy >= cub->file.h)
			cub->rcs.drawendy = cub->file.h - 1;
		cub->rcs.drawstartx = -cub->rcs.w / 2 + cub->rcs.screenx;
		if (cub->rcs.drawstartx < 0)
			cub->rcs.drawstartx = 0;
		cub->rcs.drawendx = cub->rcs.w / 2 + cub->rcs.screenx;
		if (cub->rcs.drawendx >= cub->file.w)
			cub->rcs.drawendx = cub->file.w - 1;
		ft_render_sprites(cub, cub->rcs.drawstartx);
		i++;
	}
}