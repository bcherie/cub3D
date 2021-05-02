#include "ft_cub.h"

char	**make_map(t_list **head, t_all *all, int size)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = -1;
	all->map->map_m = ft_calloc(size + 1, sizeof(char **));
	while (tmp)
	{
		all->map->map_m[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (all->map->map_m);
}

void	split_dalshe(t_all *all)
{
	ft_count_sprites(all);
	ft_init_plr(all->map, all->player);
	all->win->mlx = mlx_init();
	ft_set_tex_ns(all);
	ft_set_tex_we(all);
	ft_set_tex_sp(all);
	all->win->mlx_w = mlx_new_window(all->win->mlx, all->map->width, \
	all->map->hight, "Oasis");
	all->data.img = mlx_new_image(all->win->mlx, all->map->width, \
	all->map->hight);
	all->data.img_addr = mlx_get_data_addr(all->data.img, &all->data.bpp, \
	&all->data.llength, &all->data.end);
	mlx_hook(all->win->mlx_w, 2, 1L << 0, keypress, all);
	mlx_hook(all->win->mlx_w, 17, 1L << 0, ft_exit, all);
	ft_cast_ray(all);
}

void	split_two(int argc, t_all *all)
{
	if (argc < 2)
	{
		printf("Error\nWrong arguement number");
		exit(0);
	}
	all->map = (t_map_p *)malloc(sizeof(t_map_p));
	all->win = (t_window *)malloc(sizeof(t_window));
	all->player = (t_plr *)malloc(sizeof(t_plr));
	init_flags(all);
	ft_init_map(all);
}

void	gnl_parse(t_all *all, char *line)
{
	while (get_next_line(all->fd, &line) > 0)
	{
		if (*line == '1' || *line == ' ')
		{
			all->flag_map = 1;
			map_spec(line);
			ft_lstadd_back(&all->head, ft_lstnew(line));
		}
		else
			parse(line, all);
		if (all->flag_map == 1)
		{
			if (ft_strlen(line) == 0)
			{
				printf("inv map");
				exit(0);
			}
		}
	}
	ft_lstadd_back(&all->head, ft_lstnew(line));
	make_map(&all->head, all, ft_lstsize(all->head));
	map_zamk(all);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	char	*line;

	line = NULL;
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		ft_exit_malloc();
	split_two(argc, all);
	all->fd = open(argv[1], O_RDONLY);
	if (argc >= 2)
	{
		if (ft_strnstr(ft_strrchr(argv[1], '.'), ".cub", ft_strlen(".cub")))
			gnl_parse(all, line);
		else
		{
			printf("Error\n map's name error\n");
			exit (0);
		}
	}
	split_dalshe(all);
	if (argc == 3)
		bmp_save(all, argv[2]);
	mlx_loop(all->win->mlx);
}
