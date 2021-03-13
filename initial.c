#include "ft_cub.h"

void ft_init_w(t_window *win)
{
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
    win->addr = NULL;
    win->bits_per_pixel = 0;
    win->line_length = 0;
    win->endian = 0;

}

void ft_init_all(t_all *all)
{
	t_window		*win;
	win = NULL;
	//t_plr			*plr;
	all->map = NULL;
}

void ft_init_point(t_point *point) // структура для точки
{
	point->x = 0;
	point->y = 0;
}

// void init_str(t_list *head)
// {
// 	head->next = NULL;
// 	head->content = NULL;
// 	head->x = 0;
// 	head->y = 0;
// }

// typedef struct  s_data {  // подумать и перенести в структуру window
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;

// typedef struct	s_plr //структура для игрока и луча
// {
// 	float		x;
// 	float		y;
// 	float		dir;
// 	float		start;
// 	float		end;
// }				  t_plr;