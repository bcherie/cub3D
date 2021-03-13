#ifndef FT_CUB_H
# define FT_CUB_H
# define ERROR_MAP_NAME "error map name"
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct	s_app
{
	char content;
	struct Node *next;

}				t_app;

typedef struct s_map_p
{
	int width;
	int hight;
	void *path_no;
	void *path_so;
	void *path_we;
	void *path_ea;
	void *path_sprite;
	int *floor;
	void *ceil;
	void *next;

}				t_map_p;

typedef struct	s_window //  структура окна
{
	void	*mlx;
	void	*win;
	void	*img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;

}				t_window;

typedef struct		s_all
{
	t_window		*win;
	//t_plr			*plr;
	char			**map;

}				t_all;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

// typedef struct  s_data {  // подумать и перенести в структуру window
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

// typedef struct s_list
// {
// 	void *next;
// 	void *content;

// } 		t_list;



void	my_mlx_pixel_put(t_window *data, int x, int y, int color);
char	**make_map(t_list **head, int size);
int     ft_window(void);
void	draw_screen(t_all *all);
void ft_init_w(t_window *win);
void ft_init_point(t_point *point);
void ft_init_all(t_all *all);
void parse(char *line, t_map_p *map);
//void init_str(t_list *head);
int	ft_mapsize(t_map_p *map);
void ft_init(t_map_p *map);

#endif