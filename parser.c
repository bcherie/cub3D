#include "ft_cub.h"


int	ft_mapsize(t_map_p *map)
{
	int	i;

	i = 0;
	while (map)
	{
		map = map->next;
		i++;
	}
	return (i);
}

int		create_trgb(int t, int r, int g, int b)
{
	// int t;
	// int r; 
	// int g;
	// int b;


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

void parse(char *line, t_map_p *map)
{

	//t_map_p *map;
	int i;

	i = 0;
	char **tmp;
	char **colr;
	//map = malloc(sizeof(ft_mapsize(map)));

	tmp = ft_split(&line[i], ' ');
	if (line[i] == 'R')
	{
		map->width = ft_atoi(tmp[1]);
		map->hight = ft_atoi(tmp[2]);
		printf("width: %d\n", map->width);
		printf("hight: %d\n", map->hight);
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
		map->path_no = tmp[1];
		printf("path_no: %s\n", map->path_no);
	}
	else if (line[i] == 'S' && line[++i] == 'O')
	{
		map->path_so = tmp[1];
		printf("path_so: %s\n", map->path_so);
	}
	else if (line[i] == 'W' && line[++i] == 'E')
	{
		map->path_we = tmp[1];
		printf("path_we: %s\n", map->path_we);	
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
		map->path_ea = tmp[1];
		printf("path_ea: %s\n", map->path_ea);
	}
	else if (ft_strnstr(line, "sprite", ft_strlen(line)))
	{
		map->path_sprite = tmp[1];
		printf("path_s: %s\n", map->path_sprite);
	}
	else if (line[i] == 'F' && line[++i] == ' ')
	{
		colr = ft_split(tmp[1], ',');
		map->R = ft_atoi(colr[0]);
		map->G = ft_atoi(colr[1]);
		map->B = ft_atoi(colr[2]);
		map->floor = create_trgb(0, map->R, map->G, map->B);
		printf("path_f: %d\n", map->floor);
	}
	else if (line[i] == 'C')
	{
		//map->ceil = tmp[1];
		colr = ft_split(tmp[1], ',');
		map->C_R = ft_atoi(colr[0]);
		map->C_G = ft_atoi(colr[1]);
		map->C_B = ft_atoi(colr[2]);
		map->ceil = create_trgb(0, map->C_R, map->C_G, map->C_B);
		printf("path_c: %d\n", map->ceil);
	}
	// printf("0: %s\n", tmp[0]);
	// printf("1: %s\n", tmp[1]);
	// printf("2: %s\n", tmp[2]);
}

// char	**make_map(t_list **head, int size)
// {
// 	char	  **map = ft_calloc(size + 1, sizeof(char *));
// 	int		  i = -1;
// 	t_list	*tmp = *head;

// 	while (tmp)
// 	{
// 		map[++i] = tmp->content;
// 		tmp = tmp->next;
// 	}
// 	i = -1;
// 	while (map[++i])
// 		ft_putendl_fd(map[i]);
// 	return (map);
// }


int		main(int argc, char **argv)
{
	int		fd = open(argv[1], O_RDONLY);
	char	*line = NULL;
	t_map_p *map = NULL;
	map = malloc(sizeof(t_map_p));
	ft_init(map);
	//t_list	*head = NULL; // структура для записи спецификаторов
	//int count = 0;
	//init_str(head);
	//t_all   *all = NULL;

	if (argc == 2)
	{
		// if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		// {
			while (get_next_line(fd, &line) > 0)
			{
				while (*line != '1')
				{
					parse(line, map);
					break ;
				}	
				// ft_lstadd_back(&head, ft_lstnew(line));
				// count++;
				// line = NULL;
			}
			// close(fd);
			// ft_lstadd_back(&head, ft_lstnew(line));
			// count++;
			//return (make_map(&head, ft_lstnew(line)));
			// make_map(&head, ft_lstsize(head));
		// }
		// else 
		// 	return (printf("map error"));
	}
	ft_window();
	//draw_screen(all);
}