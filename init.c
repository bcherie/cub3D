#include "ft_cub.h"

void ft_init_map(t_all *all)
{
	all->map->width = 0;
	all->map->hight = 0;
	all->map->path_no = NULL;
	all->map->path_so = NULL;
	all->map->path_we = NULL;
	all->map->path_ea = NULL;
	all->map->path_sprite = NULL;
	all->map->floor = 0;
	all->map->ceil = 0;
	all->map->next = NULL;
	all->map->R = 0;
	all->map->B = 0;
	all->map->G = 0;
	all->map->C_R = 0;
	all->map->C_G = 0;
	all->map->C_B = 0;
	all->map->map_m = NULL;
	all->map->save = 0;
}

// void ft_init_w(t_window *win)
// {
// 	//win->win = NULL;
// 	win->mlx = NULL;
// 	win->mlx_w = NULL;
// 	win->img_w = 0;
//     win->addr = NULL;
//     win->bits_per_pixel = 0;
//     win->line_length = 0;
//     win->endian = 0;
// }

void ft_init_scale(t_scale *mashtab)
{
	mashtab->one = 0;
	mashtab->two = 0;
}

void ft_init_tex(t_texture *tex)
{
// void	*mlx_img;
	// void	*mlx_w_ing;
	tex->img = NULL;
	tex->img_width = 0;
	tex->img_height = 0;
	tex->img_addr = NULL;
	tex->bpp = 0;
	tex->llength = 0;
	tex->end = 0;
}

void ft_inint_plr_str(t_plr *player)
{
	player->x		= 0;
	player->y		= 0;
	player->dir_x	= 0.0;
	player->dir_y	= 0.0;
	player->start	= 0;
	player->end		= 0;
}
