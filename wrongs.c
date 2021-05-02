#include "ft_cub.h"

void	wrongs_pars_color(t_all *all)
{
	if (all->flag_c > 1 || all->flag_f > 1)
	{
		printf("Error\n FC_Dublicate spec\n");
		exit(0);
	}
	if (all->j != 4)
	{
		printf("7_Error: wrong spec\n");
		exit(0);
	}
	if ((all->map->R > 255 || all->map->G > 255 || all->map->B > 255)
		|| (all->map->R < 0 || all->map->G < 0 || all->map->B < 0))
	{
		printf("Error\nError: invalid digit\n");
		exit(EXIT_SUCCESS);
	}
	if ((all->map->C_R > 255 || all->map->C_G > 255 || all->map->C_B > 255)
		|| (all->map->C_R < 0 || all->map->C_G < 0 || all->map->C_B < 0))
	{
		printf("Error\nError: invalid digit\n");
		exit(EXIT_SUCCESS);
	}
}

void	wrongs_pars_resolution(t_all *all)
{
	int	w;
	int	h;

	if (all->flag_r > 1)
	{
		printf("Error\n R_Dublicate spec\n");
		exit(0);
	}
	if (all->j != 3)
	{
		printf("1_Error: wrong spec\n");
		exit(0);
	}
	if (all->map->width < 0 || all->map->hight < 0)
	{
		printf("1_Error: wrong resolution\n");
		exit(0);
	}
	mlx_get_screen_size(all->win->mlx_w, &w, &h);
	if (all->map->width > w || all->map->hight > h)
	{
		all->map->width = w;
		all->map->hight = h;
	}
}

void	wrongs_pars_texture(t_all *all)
{
	if (all->flag_no > 1 || all->flag_so > 1 || all->flag_we > 1 \
		|| all->flag_ea > 1 || all->flag_s > 1)
	{
		printf("Error\n TEX_Dublicate spec\n");
		exit(0);
	}
	if (all->j != 2)
	{
		printf("2_Error: wrong spec\n");
		exit(0);
	}
}

void	map_spec(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'N' || line[j] == 'S' \
		|| line[j] == 'W' || line[j] == 'E' \
		|| line[j] == ' ' || line[j] == '2' \
		|| line[j] == '0' || line[j] == '1')
			j++;
		else
		{
			printf("Error\n invalid map params\n");
			exit(0);
		}
	}
}

void	map_zamk(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map->map_m[i])
	{
		j = 0;
		while (all->map->map_m[i][j])
		{
			if (all->map->map_m[i][j] == '0')
			{
				if (all->map->map_m[i][j + 1] == ' ' || all->map->map_m[i][j - 1] == ' ' \
				|| all->map->map_m[i + 1][j] == ' ' || all->map->map_m[i - 1][j] == ' ' \
				|| all->map->map_m[i][j + 1] == '\0')
				{
					printf("Error\nError zamk_map\n");
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}
