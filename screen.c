#include "ft_cub.h"

// char  **ft_read_map(char *av, t_plr *plr)
// {

// }
void            my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
    char    *dst;

    dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_scale_map(t_window *win, t_point *point)
{
	// void    *mlx;
    // void    *mlx_w;
	t_scale *mashtab = NULL;
	mashtab = malloc(sizeof(t_scale));
	ft_init_scale(mashtab);

	// mlx = mlx_init();
    // mlx_w = mlx_new_window(mlx, map->width, map->hight, "Oasis");
	mashtab->one = (point->x + 1) * SCALE;
	mashtab->two = (point->y + 1) * SCALE;
	point->x *= SCALE;
	point->y *= SCALE;
	while (point->y < mashtab->one)
	{
		while (point->x < mashtab->two)
		{
			mlx_pixel_put(win->mlx, win->mlx_w, point->x, point->y, 0xFFFFFF);
			point->x++;
		}
		point->x -= SCALE;
		point->y++;
	}
	//mlx_loop(mlx);
}

void draw_screen(t_map_p *map)
{
	// void    *mlx;
    // void    *mlx_w;
	t_point *point;
	//t_window *win = all->win;

	ft_bzero(&point, sizeof(t_point));
	t_window *win = NULL;
	win = malloc(sizeof(t_window));
	ft_init_w(win);

	point = malloc(sizeof(t_point));
	ft_init_point(point);
	//map->map_m = ft_calloc(size + 1, sizeof(char *));

 	win->mlx = mlx_init();
    win->mlx_w = mlx_new_window(win->mlx, map->width, map->hight, "Oasis");
	//img = mlx_xpm_file_to_image();
	win->img = mlx_new_image(win->mlx, map->width, map->hight);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, &win->line_length, &win->endian);
	while (map->map_m[point->y])
	{
		point->x = 0;
		while (map->map_m[point->y][point->x])
		{
			if (map->map_m[point->y][point->x] == '1')
				my_mlx_pixel_put(win, point->x, point->y, 0xFFFFFF);
				//ft_scale_map(win, point); // масштаб карты
				//mlx_pixel_put(win->mlx, win->mlx_w, point->x, point->y, 0xFFFFFF);
			point->x++;
		}
		point->y++;
	}
	//ft_draw_player(all, all->plr); // отрисовка игрока
	mlx_put_image_to_window(win->mlx, win->mlx_w, win->img, 0, 0);
	//mlx_destroy_image(win->mlx, win->img);
	mlx_loop(win->mlx);
}


// void	ft_draw_floorsky(t_window *win, t_map_p *map)
// {
// 	int x;
// 	int y;

// 	x = 0;
	
// 	while (x < map->width)
// 	{
// 		y = 0;
// 		while (y < map->hight / 2)
// 		{
// 			win->img[y * map->width + x] = map->ceil;
// 			y++;
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	while (x < map->width)
// 	{
// 		y = map->hight / 2;
// 		while (y < map->hight)
// 		{
// 			win->img[y * map->width + x] = map->floor;
// 			y++;
// 		}
// 		x++;
// 	}
	
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