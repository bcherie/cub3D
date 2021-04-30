#include "ft_cub.h"

// make various func for north/so/ea textures and func for draw
static void		ft_set_tex(t_all *all)
{
	if (!(all->no.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_no, &all->no.img_width, &all->no.img_height)))
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->no.img_addr = mlx_get_data_addr(all->no.img, &all->no.bpp, &all->no.llength, &all->no.end);
	if (!(all->so.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_so, &all->so.img_width, &all->so.img_height)))
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->so.img_addr = mlx_get_data_addr(all->so.img, &all->so.bpp, &all->so.llength, &all->so.end);
	if (!(all->ea.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_ea, &all->ea.img_width, &all->ea.img_height)))
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->ea.img_addr = mlx_get_data_addr(all->ea.img, &all->ea.bpp, &all->ea.llength, &all->ea.end);
	if (!(all->we.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_we, &all->we.img_width, &all->we.img_height)))
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->we.img_addr = mlx_get_data_addr(all->we.img, &all->we.bpp, &all->we.llength, &all->we.end);
	if (!(all->sp.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_sprite, &all->sp.img_width, &all->sp.img_height)))
	{
		printf("Error\nInvalid texture path");
		exit(0);
	}
	all->sp.img_addr = mlx_get_data_addr(all->sp.img, &all->sp.bpp, &all->sp.llength, &all->sp.end);
}

int		create_trgb(int t, int r, int g, int b)
{
	t = 0; 
	return(t << 24 | r << 16 | g << 8 | b);
}

static size_t	words_count(char const *s, char sp)
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

char check_zap(char *line)
{
	char *t;
	int i;

	i = 0;
	t = line;
	while (*t != '\0')
	{
		if (*t == ',')
			*t = ' ';
		t++;
	}
	line = t;
	return(*line);
}

void parse(char *line, t_all *all)
{
	int i;
	int j;
	int	x;

	j = 0;
	i = 0;
	x = 0;

	char **tmp;
	// init_flags(all);
	check_zap(line);
	j = words_count(line, ' ');
	tmp = ft_split(&line[i], ' ');
	if (line[i] == 'R')
	{
		all->x++;
		all->flag_r += 1;
		all->map->width = ft_atoi(tmp[1]);
		all->map->hight = ft_atoi(tmp[2]);
		wrongs_pars_resolution(all, j);
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
		all->x++;
		all->flag_no += 1;
		wrongs_pars_texture(all, j);
		all->map->path_no = tmp[1];
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		all->x++;
		all->flag_so += 1;
		wrongs_pars_texture(all, j);
		all->map->path_so = tmp[1];
	}
	else if (line[i] == 'W' && line[++i] == 'E')
	{
		all->x++;
		all->flag_we += 1;
		wrongs_pars_texture(all, j);
		all->map->path_we = tmp[1];
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
		all->x++;
		all->flag_ea += 1;
		wrongs_pars_texture(all, j);
		all->map->path_ea = tmp[1];
	}
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
	{
		all->x++;
		all->flag_s += 1;
		wrongs_pars_texture(all, j);
		all->map->path_sprite = tmp[1];
	}
	else if (line[i] == 'F' && line[++i] == ' ')
	{
		all->x++;
		all->flag_f += 1;
		all->map->R = ft_atoi(tmp[1]);
		all->map->G = ft_atoi(tmp[2]);
		all->map->B = ft_atoi(tmp[3]);
		wrongs_pars_color(all, j);
		all->map->floor = create_trgb(0, all->map->R, all->map->G, all->map->B);
	}
	else if (line[i] == 'C')
	{
		all->x++;
		all->flag_c += 1;
		all->map->C_R = ft_atoi(tmp[1]);
		all->map->C_G = ft_atoi(tmp[2]);
		all->map->C_B = ft_atoi(tmp[3]);
		wrongs_pars_color(all, j);
		all->map->ceil = create_trgb(0, all->map->C_R, all->map->C_G, all->map->C_B);
	}
	// printf("i %d\n", i);
	// if(i != 8)
	// {
	// 	printf("Error\nWrong spec arg");
	// 	exit(0);
	// }
	// 	i++;
	// if(i != 8)
	// {
	// 	printf("Error\nWrong spec arg");
	// 	exit(0);
	// }
}

void ft_count_sprites(t_all *all)
{
	int i;
	int j;

	i = 0;
	all->num_sp = 0;
	while (all->map->map_m[i])
	{
		j = 0;
		while (all->map->map_m[i][j])
		{
			if (all->map->map_m[i][j] == '2')
				all->num_sp += 1;
			j++;
		}
		i++;
	}
}

char	**make_map(t_list **head, t_all *all, int size)
{
	all->map->map_m = ft_calloc(size + 1, sizeof(char **));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		all->map->map_m[++i] = tmp->content;
		tmp = tmp->next;
	}
	// i = -1;
	// while (all->map->map_m[++i])
	// 	ft_putendl_fd(all->map->map_m[i]);
	return (all->map->map_m);
}

int		main(int argc, char **argv)
{
	t_all		*all = NULL;
	char	*line = NULL;	
	t_list	*head = NULL;
	int		fd;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
	{
		printf("Error\nMalloc error");
		exit(0);
	}
	if (argc < 2)
	{
		printf("Error\nWrong arguement number");
		exit(0);
	}
	all->flag_map = 0;
	//fd = open(argv[1], O_RDONLY);
	//from_main(all, argc);
	all->map = (t_map_p *)malloc(sizeof(t_map_p));
	all->win = (t_window *)malloc(sizeof(t_window));
	all->player = (t_plr *)malloc(sizeof(t_plr));
	init_flags(all);
	ft_init_map(all);
	fd = open(argv[1], O_RDONLY);
	if (argc >= 2)
	{
		if (ft_strnstr(ft_strrchr(argv[1], '.'), ".cub", ft_strlen(".cub")))
		{
			while (get_next_line(fd, &line) > 0)
			{
				if (*line == '1' || *line == ' ')
				{
					all->flag_map = 1;
					map_spec(line);
					ft_lstadd_back(&head, ft_lstnew(line));
				}
				else
					parse(line, all);
				// printf("flag: %d", all->flag_map);
				if (all->flag_map == 1)
				{
					if (ft_strlen(line) == 0)
					{
						printf("inv map");
						exit(0);	
					}
				}
			}
			ft_lstadd_back(&head, ft_lstnew(line));	
			make_map(&head, all, ft_lstsize(head));
			map_zamk(all);
		}
		else 
			printf("Error: map's name error\n");
	}
	//printf("i %d\n", all->x);
	// if(all->x != 8)
	// {
	// 	printf("Error\nWrong spec arg");
	// 	exit(0);
	//}
	// j = all->flag_c + all->flag_f + all->flag_we + all->flag_ea + all->flag_no + all->flag_so + all->flag_s + all->flag_r;
	// if (j != 8)
	// {
	// 	printf("Error\nWrong spec arg");
	// 	exit(0);
	// }
	ft_count_sprites(all);
	ft_init_plr(all->map, all->player);
	all->win->mlx = mlx_init();
	ft_set_tex(all);
    all->win->mlx_w = mlx_new_window(all->win->mlx, all->map->width, all->map->hight, "Oasis");
	all->data.img = mlx_new_image(all->win->mlx, all->map->width, all->map->hight);
	all->data.img_addr = mlx_get_data_addr(all->data.img, &all->data.bpp, &all->data.llength, &all->data.end);
	mlx_hook(all->win->mlx_w, 2, 1L<<0, keypress, all);
	ft_cast_ray(all);
	if (argc == 3)
		bmp_save(all, argv[2]);
	mlx_loop(all->win->mlx);
}