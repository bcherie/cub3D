#include "ft_cub.h"


// char  **ft_read_map(char *av, t_plr *plr)
// {

// }
// void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
// {
//     char    *dst;

//     dst = all->win->addr + (y * all->win->line_length + x * (all->win->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }


void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->data.img_addr + (y * all->data.llength + x * (all->data.bpp / 8));
    *(unsigned int*)dst = color;
}

// void ft_scale_map(t_window *win, int x, int y, int color)
// {
// 	int one;
// 	int two;
// 	//mashtab = malloc(sizeof(t_scale));
// 	//ft_init_scale(mashtab);

// 	// mlx = mlx_init();
//     // mlx_w = mlx_new_window(mlx, map->width, map->hight, "Oasis");
// 	// mashtab->one = (point->x * SCALE);

// 	one = ((x + 1) * SCALE);
// 	two = ((y + 1) * SCALE);
// 	y *= SCALE;
// 	x *= SCALE;
// 	while (y < two)
// 	{
// 		//one = (point->x * SCALE);
// 		while (x < one)
// 		{
// 			my_mlx_pixel_put(win, x++, y, color);
// 			//mlx_pixel_put(win->mlx, win->mlx_w, point->x, point->y, 0xFFFFFF);
// 			//point->x++;ww
// 		}
// 		x -= SCALE;
// 		y++;
// 	}
// 	//mlx_loop(mlx);
// }

// void draw_screen(t_all *all)
// {
// 	//t_point *point;
// 	int x;
// 	int y;

// 	y = 0;
	//t_all *all = NULL;
	//t_window *win = all->win;

	//ft_bzero(&point, sizeof(t_point));
	// t_window *win = NULL;
	// win = malloc(sizeof(t_window));
	// ft_init_w(win);

	// point = malloc(sizeof(t_point));
	// ft_init_point(point);

	// t_plr *player = NULL;
	// player = malloc(sizeof(t_plr));
	// ft_inint_plr_str(player);
	// ft_init_plr(map, player);

	// t_texture *tex = NULL;
	// tex = malloc(sizeof(t_texture));
	// ft_init_tex(tex);
	//map->map_m = ft_calloc(size + 1, sizeof(char *));

 	//win->mlx = mlx_init();
    //win->mlx_w = mlx_new_window(win->mlx, map->width, map->hight, "Oasis");
	//win->img_w = mlx_new_image(win->mlx, map->width, map->hight);
	//tex->img = mlx_xpm_file_to_image(win->mlx, "/Users/bcherie/cub3D/textures/mossy.xpm", &win->img_width, &win->img_height);
	//win->addr = mlx_get_data_addr(win->img_w, &win->bits_per_pixel, &win->line_length, &win->endian);

	// all->tex->img = mlx_new_image(all->win->mlx, map->width, map->hight);
	// all->tex->img_addr = mlx_get_data_addr(all->tex->img, &tex->bpp, &tex->llength, &tex->end);
	
	// while (all->map->map_m[y])
	// {
	// 	x = 0;
	// 	while (all->map->map_m[y][x])
	// 	{
	// 		if (all->map->map_m[y][x] == '1')
	// 			//my_mlx_pixel_put(win, point->x, point->y, 0xFFFFFF);
	// 			ft_scale_map(all->win, x, y, 0xFFFFFF); // масштаб карты
	// 			//mlx_pixel_put(win->mlx, win->mlx_w, point->x, point->y, 0xFFFFFF);
	// 		if (all->map->map_m[y][x] == 'N')
	// 			ft_scale_map(all->win, x, y, 0x00FF00); // масштаб карты
	// 		x++;
	// 	}
	// 	y++;
	// }
// 	ft_cast_ray(all);
// 	// ft_init_plr(map, player);
// 	// ft_draw_player(win, player, map); // отрисовка игрока
// 	//ft_cast_ray(all->player,all->map, all->win);

// 	mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, all->win->img_w, 0, 0);

// 	// mlx_put_image_to_window(win->mlx, win->mlx_w, tex->img, 0, 0);
// 	//mlx_destroy_image(win->mlx, win->img);
// 	//ft_init_plr(map, player);
// 	//ft_draw_player(win, *point); // отрисовка игрока
// 	//ft_draw_player(win, point);
// 	//mlx_loop(win->mlx);
// }


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