#include "ft_cub.h"

void	parse_text_no(t_all *all)
{
	all->x++;
	all->flag_no += 1;
	wrongs_pars_texture(all);
	all->map->path_no = all->tmp[1];
}

void	parse_text_so(t_all *all)
{
	all->x++;
	all->flag_so += 1;
	wrongs_pars_texture(all);
	all->map->path_so = all->tmp[1];
}

void	parse_text_we_ea(t_all *all, char *line)
{
	if (ft_strnstr(line, "WE", ft_strlen(line)))
	{
		all->x++;
		all->flag_we += 1;
		wrongs_pars_texture(all);
		all->map->path_we = all->tmp[1];
	}
	if (ft_strnstr(line, "EA", ft_strlen(line)))
	{
		all->x++;
		all->flag_ea += 1;
		wrongs_pars_texture(all);
		all->map->path_ea = all->tmp[1];
	}
}

void	parse_color_fc(t_all *all, char *line)
{
	if (ft_strnstr(line, "F ", ft_strlen(line)))
	{
		all->x++;
		all->flag_f += 1;
		write_rgb(all, line);
		wrongs_pars_color(all);
	}
	if (ft_strnstr(line, "C ", ft_strlen(line)))
	{
		all->x++;
		all->flag_c += 1;
		write_rgb(all, line);
		wrongs_pars_color(all);
	}
}

void	parse_text_s(t_all *all)
{
	all->x++;
	all->flag_s += 1;
	wrongs_pars_texture(all);
	all->map->path_sprite = all->tmp[1];
}
