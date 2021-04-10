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
	if (!(all->ea.img = mlx_xpm_file_to_image(all->win->mlx, all->map->path_ea, &all->so.img_width, &all->so.img_height)))
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
	//vrem = ft_split(tmp[1], ',');
	//printf ("floor: %s", vrem[1]);
	// r = ft_atoi(vrem[0]);
	// g = ft_atoi(vrem[1]);
	// b = ft_atoi(vrem[2]);
	// printf("0: %d\n", r);
	// printf("1: %d\n", g);
	// printf("2: %d\n", b);
	return(t << 24 | r << 16 | g << 8 | b);
	//return (0);
}

void parse(char *line, t_all *all)
{

	//t_map_p *map;
	int i;

	i = 0;
	all->moveSpeed = 0.05;
	//all->rotSpeed = 0.05;
	char **tmp;
	char **colr;
	//ft_init_map(all);
	//map = malloc(sizeof(ft_mapsize(map)));
	// printf("Map passed to function: %p\n", &all->map);
	// printf("Map elem w: %p\n", &all->map->width);
	// printf("Map elem h: %p\n", &all->map->hight);
	tmp = ft_split(&line[i], ' ');
	if (line[i] == 'R')
	{
		all->map->width = ft_atoi(tmp[1]);
		all->map->hight = ft_atoi(tmp[2]);
		printf("width: %d\n", all->map->width);
		printf("hight: %d\n", all->map->hight);
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
		all->map->path_no = tmp[1];
		printf("path_no: %s\n", all->map->path_no);
	}
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		all->map->path_so = tmp[1];
		printf("path_so: %s\n", all->map->path_so);
	}
	// else if (line[i] == 'S' && line[++i] == 'O')
	// {
	// 	map->path_so = tmp[1];
	// 	printf("path_so: %s\n", map->path_so);
	// }
	else if (line[i] == 'W' && line[++i] == 'E')
	{
		all->map->path_we = tmp[1];
		printf("path_we: %s\n", all->map->path_we);	
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
		all->map->path_ea = tmp[1];
		printf("path_ea: %s\n", all->map->path_ea);
	}
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
	{
		all->map->path_sprite = tmp[1];
		printf("path_s: %s\n", all->map->path_sprite);
	}
	else if (line[i] == 'F' && line[++i] == ' ')
	{
		colr = ft_split(tmp[1], ',');
		all->map->R = ft_atoi(colr[0]);
		all->map->G = ft_atoi(colr[1]);
		all->map->B = ft_atoi(colr[2]);
		all->map->floor = create_trgb(0, all->map->R, all->map->G, all->map->B);
		printf("path_f: %d\n", all->map->floor);
	}
	else if (line[i] == 'C')
	{
		//map->ceil = tmp[1];
		colr = ft_split(tmp[1], ',');
		all->map->C_R = ft_atoi(colr[0]);
		all->map->C_G = ft_atoi(colr[1]);
		all->map->C_B = ft_atoi(colr[2]);
		all->map->ceil = create_trgb(0, all->map->C_R, all->map->C_G, all->map->C_B);
		printf("path_c: %d\n", all->map->ceil);
	}

	// printf("0: %s\n", tmp[0]);
	// printf("1: %s\n", tmp[1]);
	// printf("2: %s\n", tmp[2]);
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
	if (argc < 2 || argc > 3)
	{
		printf("Error\nWrong arguement number");
		exit(0);
	}
	// if (argc == 3)
	// {
	// 	if (ft_strncmp(argv[2], "--save", ft_strlen("--save")))
	// 		all->map->save = 1;
	// }
	int		fd = open(argv[1], O_RDONLY);
	char	*line = NULL;
	//t_window *win =  NULL;	
	t_list	*head = NULL; // структура для записи спецификаторов
	//init_str(head);
	//t_all   *all = NULL;
	// t_map_p *map = NULL;
	all->map = (t_map_p *)malloc(sizeof(t_map_p));
	all->win = (t_window *)malloc(sizeof(t_window));
	all->player = (t_plr *)malloc(sizeof(t_plr));
	ft_init_map(all);
	// t_window *win = NULL;
	// win = malloc(sizeof(t_window));
	// ft_init_w(win);
	if (argc == 2)
	{
		// if (ft_strnstr(&ft_strrchr(argv[1], '.'), ".cub", ft_strlen(".cub")))
		// {
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
			make_map(&head, all, ft_lstsize(head));
			//ft_draw_floorsky(win, map);
		// }
		// else 
		// 	return (printf("Error\nmap error"));
	}
	ft_init_plr(all->map, all->player);
	all->win->mlx = mlx_init();
	ft_set_tex(all);
	// ft_cast_ray(all);
    all->win->mlx_w = mlx_new_window(all->win->mlx, all->map->width, all->map->hight, "Oasis");
	all->current.img = mlx_new_image(all->win->mlx, all->map->width, all->map->hight);
	//printf("new_img: %p", all->current.img);
	//tex->img = mlx_xpm_file_to_image(win->mlx, "/Users/bcherie/cub3D/textures/mossy.xpm", &win->img_width, &win->img_height);
	all->current.img_addr = mlx_get_data_addr(all->current.img, &all->current.bpp, &all->current.llength, &all->current.end);
	mlx_hook(all->win->mlx_w, 2, 1L<<0, keypress, all);
	ft_cast_ray(all);
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, all->current.img, 0, 0);
	//draw_screen(all);
	mlx_loop(all->win->mlx);
}