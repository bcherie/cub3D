#ifndef FT_CUB_H
# define FT_CUB_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"

typedef struct	s_app
{
	char content;
	struct Node *next;

}				t_app;


typedef struct	window
{
	void *mlx;
	void *win;

}				t_window;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

// typedef struct s_list
// {
// 	void *next;
// 	void *content;

// } 		t_list;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**make_map(t_list **head, int size);
int     ft_window(void);

#endif