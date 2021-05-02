#include "ft_cub.h"

void	write_rgb(t_all *all, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'F')
	{
		all->map->R = ft_atoi(all->tmp[1]);
		all->map->G = ft_atoi(all->tmp[2]);
		all->map->B = ft_atoi(all->tmp[3]);
		all->map->floor = create_trgb(0, all->map->R, all->map->G, all->map->B);
	}
	if (line[i] == 'C')
	{
		all->map->C_R = ft_atoi(all->tmp[1]);
		all->map->C_G = ft_atoi(all->tmp[2]);
		all->map->C_B = ft_atoi(all->tmp[3]);
		all->map->ceil = create_trgb(0, all->map->C_R, \
		all->map->C_G, all->map->C_B);
	}
}

void	parse_resol(t_all *all)
{
	all->x++;
	all->flag_r += 1;
	all->map->width = ft_atoi(all->tmp[1]);
	all->map->hight = ft_atoi(all->tmp[2]);
	wrongs_pars_resolution(all);
}

size_t	words_count(char const *s, char sp)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != sp && (s[i + 1] == sp || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

char	check_zap(char *line)
{
	char	*t;
	int		i;

	i = 0;
	t = line;
	while (*t != '\0')
	{
		if (*t == ',')
			*t = ' ';
		t++;
	}
	line = t;
	return (*line);
}

void	parse(char *line, t_all *all)
{
	int	i;

	i = 0;
	check_zap(line);
	all->j = words_count(line, ' ');
	all->tmp = ft_split(&line[i], ' ');
	if (ft_strnstr(line, "R ", ft_strlen(line)))
		parse_resol(all);
	else if (line[i] == 'N' && line[++i] == 'O')
		parse_text_no(all);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		parse_text_so(all);
	else if ((line[i] == 'W' && line[++i] == 'E') \
		|| (line[i] == 'E' && line[++i] == 'A'))
		parse_text_we_ea(all, line);
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
		parse_text_s(all);
	else if ((line[i] == 'F' && line[++i] == ' ') \
		|| line[i] == 'C')
		parse_color_fc(all, line);
	else if (all->x == 8 && *line != '\0')
	{
		printf("Error\nWrong spec arg");
		exit(0);
	}
}
