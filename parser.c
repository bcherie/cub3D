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
	//return (0);
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
	// int i;

	// i = 0;
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
	static int k;
	int w;
	int h;

	j = 0;
	i = 0;
	k = 0;

	char **tmp;
	//char **colr;
	check_zap(line);
	printf("line: %s", line);
	j = words_count(line, ' ');
	tmp = ft_split(&line[i], ' ');
	// printf("k: %d\n", k);
	if (line[i] == 'R')
	{
		all->flag += 1;
		all->map->width = ft_atoi(tmp[1]);
		all->map->hight = ft_atoi(tmp[2]);
		printf("width: %d\n", all->map->width);
		printf("hight: %d\n", all->map->hight);
		if (j != 3)
			printf("1_Error: wrong spec\n");
		if (all->map->width < 0 || all->map->hight < 0)
			printf("1_Error: wrong resolution\n");
		mlx_get_screen_size(all->win->mlx_w, &w, &h);
		if(ft_strlen(ft_itoa(all->map->width)) > 4 || ft_strlen(ft_itoa(all->map->hight > 4)))
		{
			all->map->width = w;
			all->map->hight = h;	
			printf("too big resolution");
		}
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
		if (j != 2)
			printf("2_Error: wrong spec\n");
		all->flag += 1;
		all->map->path_no = tmp[1];
		printf("path_no: %s\n", all->map->path_no);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		if (j != 2)
			printf("3_Error: wrong spec\n");
		all->flag += 1;
		all->map->path_so = tmp[1];
		printf("path_so: %s\n", all->map->path_so);
	}
	else if (line[i] == 'W' && line[++i] == 'E')
	{
		if (j != 2)
			printf("4_Error: wrong spec\n");
		all->flag += 1;
		all->map->path_we = tmp[1];
		printf("path_we: %s\n", all->map->path_we);	
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
		if (j != 2)
			printf("5_Error: wrong spec\n");
		all->flag += 1;
		all->map->path_ea = tmp[1];
		printf("path_ea: %s\n", all->map->path_ea);
	}
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
	{
		if (j != 2)
			printf("6_Error: wrong spec\n");
		all->flag += 1;
		all->map->path_sprite = tmp[1];
		printf("path_s: %s\n", all->map->path_sprite);
	}
	else if (line[i] == 'F' && line[++i] == ' ')
	{
		// if (j != 4)
		// {
		// 	printf("7_Error: wrong spec\n");
		// 	exit(0);
		// }
		all->flag += 1;
		all->map->R = ft_atoi(tmp[1]);
		all->map->G = ft_atoi(tmp[2]);
		all->map->B = ft_atoi(tmp[3]);
		wrongs_pars_color(all, j);
		// if ((all->map->R > 255 || all->map->G > 255 || all->map->B > 255)
		// 	|| (all->map->R < 0 || all->map->G < 0 || all->map->B < 0))
		// 	{
		// 		printf("Error\nError: invalid digit\n");
		// 		exit(EXIT_SUCCESS);
		// 	}
		all->map->floor = create_trgb(0, all->map->R, all->map->G, all->map->B);
		printf("path_f: %d\n", all->map->floor);
	}
	else if (line[i] == 'C')
	{
		// if (j != 4)
		// {
		// 	printf("8_Error: wrong spec\n");
		// 	exit(0);
		// }
		all->flag = 8;
		all->map->C_R = ft_atoi(tmp[1]);
		all->map->C_G = ft_atoi(tmp[2]);
		all->map->C_B = ft_atoi(tmp[3]);
		wrongs_pars_color(all, j);
		// if ((all->map->C_R > 255 || all->map->C_G > 255 || all->map->C_B > 255)
		// 	|| (all->map->C_R < 0 || all->map->C_G < 0 || all->map->C_B < 0))
		// 	{
		// 		printf("Error\nError: invalid digit\n");
		// 		exit(EXIT_SUCCESS);
		// 	}
		all->map->ceil = create_trgb(0, all->map->C_R, all->map->C_G, all->map->C_B);
		printf("path_c: %d\n", all->map->ceil);
	}
	// while (*line)
	// {
	// 	if (*line == '\0')
	// 		k += 1; 
	// 	// if((tmp[0] == "R") > 1)
	// 	// 	printf("Error: wrong dub_spec\n");
	// 	// if (k != 8)
	// 	// 	printf("Error: wrong col_spec\n");
	// 	(*line)++;
	// 	// k++;
	// }
}

// write func for allocateion memory for sprites:
// void ft_memory_sp(t_all *all)
// {
// 	all->mass_sp = (int **)ft_calloc((all->num_sp + 1), sizeof(int **));

// }

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

// char	**make_map(t_list **head, t_map_p *map, int size)
char	**make_map(t_list **head, t_all *all, int size)
{
	// size = 0;
	// t_map_p *map;
	//map->map_m = ft_calloc(ft_mapsize(map) + 1, sizeof(char *));
	// printf("Map: %p\n", &map->map_m);
	// map->map_m =(char **)malloc(sizeof(char) * (size + 1));
	all->map->map_m = ft_calloc(size + 1, sizeof(char **));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		all->map->map_m[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (all->map->map_m[++i])
		ft_putendl_fd(all->map->map_m[i]);
	// while (map->map_m)
	//printf("map: %s", map->map_m[0]);
	return (all->map->map_m);
}


int		main(int argc, char **argv)
{
	t_all		*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
	{
		printf("Error\nMalloc error");
		exit(0);
	}
	// ft_bzero(all, sizeof(t_all));
	// all->map = malloc(sizeof(t_map_p));
	// ft_init(all);
	// all->num_sp = 0;
	if (argc < 2)
	{
		printf("Error\nWrong arguement number");
		exit(0);
	}
	int		fd = open(argv[1], O_RDONLY);
	char	*line = NULL;	
	t_list	*head = NULL; // структура для записи спецификаторов
	all->map = (t_map_p *)malloc(sizeof(t_map_p));
	all->win = (t_window *)malloc(sizeof(t_window));
	all->player = (t_plr *)malloc(sizeof(t_plr));
	ft_init_map(all);
	if (argc >= 2)
	{
		if (ft_strnstr(ft_strrchr(argv[1], '.'), ".cub", ft_strlen(".cub")))
		{
			while (get_next_line(fd, &line) > 0)
			{
				if (*line == '1' || *line == ' ')
				{
					ft_lstadd_back(&head, ft_lstnew(line));
				}
				else
					parse(line, all);
			}
			ft_lstadd_back(&head, ft_lstnew(line));
			// printf("flag_a: %d\n", all->flag);
			if (all->flag < 8 || all->flag > 8)
				printf("Error\nError: Don't have spec\n");
			make_map(&head, all, ft_lstsize(head));
		}
		else 
			printf("Error: map's name error\n");
	}
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
	{
		bmp_save(all, argv[2]);
		// if (ft_strncmp(argv[2], "--save", ft_strlen("--save")))
		// 	all->map->save = 1;
	}
	mlx_loop(all->win->mlx);
}