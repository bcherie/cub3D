#ifndef FT_CUB_H
# define FT_CUB_H
# define ERROR_MAP_NAME "error map name"
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "libx_opengl/mlx.h"
#define SCALE 40
#define W 13
#define S 1
#define D 2
#define A 0
#define ARROW_L 124
#define ARROW_R 123
#define ESC 53
# define DIV 1
# define DIV 1
# define MOVE 0.0
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
// #define img_width 64
// #define img_height 64

typedef struct	s_app
{
	char content;
	struct Node *next;

}				t_app;

typedef struct  s_scale
{
	int one;
	int two;
}				t_scale;


typedef struct s_map_p
{
	int width;
	int hight;
	char *path_no;
	char *path_so;
	char *path_we;
	char *path_ea;
	char *path_sprite;
	int	floor;
	int R;
	int G;
	int B;
	int ceil;
	int C_R;
	int C_G;
	int C_B;
	void *next;
	char **map_m; 
	int		save;
}				t_map_p;

typedef struct s_ray
{
	double camerax;
    double raydirx;
    double raydiry;
	int mapx;
    int mapy;
    double sidedistx;
    double sidedisty;
	double deltadistx;
    double deltadisty;
    double perpwalldist;
	int stepx;
    int stepy;
	int hit;
    int side;
	int lineheight;
	int drawstart;
    int drawend;
    int texnum;
	double wallx;
    int texx;
    double step;
    double texpos;
	int texy;
	//int texwidth;
	//int texheight;
	int	color;
	double			*zbuff;
}				t_ray;


typedef struct	s_window //  структура окна
{
	void	*mlx;
	void	*mlx_w;
	//void	*win;
	void	*img_w;
	// int		img_width;
	// int		img_height;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}				t_window;


typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_texture
{
	void	*img;
	int		img_width;
	int		img_height;
    char    *img_addr;
    int     bpp;
    int     llength;
    int     end;
	int		color;
}				t_texture;

typedef struct	s_sprites
{
	double x;
	double y;
	// double s_width;
	// double	s_height;
	double	dist;
	int		order;
}				t_sprites;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct		s_bmp
{
	int				fd;
	int				size;
	int				h2;
	unsigned char	*head;
	int				clr;
	int				offset;
}					t_bmp;

typedef struct		s_all
{
	t_window		*win;
	t_plr			*player;
	t_map_p			*map;
	t_ray			rc;
	t_texture		data;
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_texture		sp;
	t_texture		current;
	t_texture		floor;
	t_texture		ceil;
	t_sprites		*sprites;
	//t_pair	*sprite;
	double			moveSpeed;
	double			rorate;
	int				**buf;
	int				flag;
	int				num_sp;
	//int				tmp_order;
	double			**mass_sp;
	double			transfx;
	double			transfy;
	int				dr_startx;
	int				dr_starty;
	int				dr_drendx;
	int				dr_drendy;
	int				spritescreen_x;
	double			*zBuffer;
	double			sp_x;
	double			sp_y;
	int				s_texx;
	int				s_texy;
	int				d;
	int				s_clr;
	int mvscreen;
	int	sp_width;
	int	sp_heigth;
	t_bmp			bmp;
	// double	dist;
	// int		order;
	//t_plr			*plr;
	//char			**map_m;
	//int		texture[8][img_height * img_width];

}				t_all;


//void            my_mlx_pixel_put(t_window *win, int x, int y, int color);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
//char	**make_map(t_list **head, int size);
// char	**make_map(t_list **head, t_map_p *map, int size);
char	**make_map(t_list **head, t_all *all, int size);
//int     ft_window(void);
int     ft_window(t_map_p *map);
void draw_screen(t_all *all);
void ft_init_w(t_window *win);
// void ft_init_all(t_all *all);
//void parse(char *line, t_map_p *map);
void parse(char *line, t_all *all);
//void init_str(t_list *head);
int	ft_mapsize(t_map_p *map);
void ft_init_map(t_all *all);
int		create_trgb(int t, int r, int g, int b);
void ft_init_w(t_window *win);
void	ft_draw_floorsky(t_window *win, t_map_p *map); // kill
void ft_init_scale(t_scale *mashtab);
void ft_scale_map(t_window *win, int x, int y, int color);
void ft_init_tex(t_texture *tex);
//void ft_draw_player(t_window *win, t_plr *player, t_map_p *map);
//void ft_draw_player(t_window *win, t_point *point);
void		ft_cast_ray(t_all *all);
void ft_init_plr(t_map_p *map, t_plr *player);
void ft_inint_plr_str(t_plr *player);
int keypress(int key, t_all *all);

void sprites_main(t_all *all, int x);
void draw_sp(t_all *all, int x);
void ft_clac_hw_sp(t_all *all);
void ft_sp(t_all *all, int i);
void sprite_sort(int *order, double *dist, int amount);
void	sort_order(t_pair *orders, int amount);
void ft_coord_sprite(t_all *all);
void ft_count_sprites(t_all *all);
void    bmp_save(t_all *all, char *argv);
void		sprite(t_all *all, int x);
void ft_draw_textures(t_all *all, int i, int x);
void wrongs_pars_color(t_all *all, int j);

#endif