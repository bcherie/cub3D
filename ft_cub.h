#ifndef FT_CUB_H
# define FT_CUB_H
# include <stdlib.h>

typedef struct	s_list
{
	char content;
	struct Node *next;

}				t_list;


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

#endif