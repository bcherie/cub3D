#include "ft_cub.h"

// char  **ft_read_map(char *av, t_plr *plr)
// {

// }

// void draw_screen(t_all *all)
// {
// 	t_point point;
// 	t_map_p *map;
// 	t_window *win = all->win;

// 	win->img = mlx_new_image(win->mlx, map->width, map->hight);
// 	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, &win->line_length, &win->endian);
// 	ft_bzero(&point, sizeof(t_point));
// 	while (all->map[point.y])
// 	{
// 		point.x = 0;
// 		while (all->map[point.x])
// 		{
// 			if (all->map[point.y][point.x] == '1')
// 				mlx_pixel_put(all->win->mlx, all->win->win, point.x, point.y, 0xFFFFFF);
// 			point.x++;
// 		}
// 		point.y++;
// 	}
// 	//ft_draw_player(all, all->plr);
// 	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
// 	//mlx_destroy_image(win->mlx, win->img);
// }

// int main(int argc, char **argv)
// {
// 	t_window	win;
// 	//t_plr		plr;
// 	t_all		all;
// 	int			x;
//     int			y;

//     x = 0;
//     y = 0;

// 	// if (argc == 2)
// 	// 	all.map = ft_read_map(argv[1], &plr);
// 	// else
// 	// 	return (ft_putendl_fd("read map"), 2);
// 	//ft_init_player(all.map, &plr);
// 	win.mlx = mlx_init();
// 	win.win = mlx_new_window(win.mlx, 640, 480, "Oasis");
// 	while (y < 200)
//     {
//         x = 0;
//         while (x < 200)
//         {
//             mlx_pixel_put(win.mlx, win.win, x, y, 0xFFFFFF);
//             x++;
//         }
//         y++;
//     }
//     //mlx_put_image_to_window(mlx, mlx_w, img->img, 0, 0);
// 	mlx_loop(win.mlx);
//     return (0);
	
// }