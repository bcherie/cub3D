#ifndef FT_CUB_H
# define FT_CUB_H
# define ERROR_MAP_NAME "error map name"
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# define SCALE 40
# define W 13
# define S 1
# define D 2
# define A 0
# define ARROW_L 124
# define ARROW_R 123
# define ESC 53
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_app
{
	char		content;
	struct Node	*next;

}				t_app;

typedef struct s_scale
{
	int	one;
	int	two;
}				t_scale;

typedef struct s_map_p
{
	int		width;
	int		hight;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*path_sprite;
	int		floor;
	int		R;
	int		G;
	int		B;
	int		ceil;
	int		C_R;
	int		C_G;
	int		C_B;
	void	*next;
	char	**map_m;
	int		save;
}				t_map_p;

typedef struct s_ray
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texnum;
	double		wallx;
	int			texx;
	double		step;
	double		texpos;
	int			texy;
	int			color;
	double		*zbuff;
}				t_ray;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_w;
	void	*img_w;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_window;

typedef struct s_plr
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		start;
	float		end;
}				t_plr;

typedef struct s_texture
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*img_addr;
	int		bpp;
	int		llength;
	int		end;
	int		color;
}				t_texture;

typedef struct s_sprites
{
	double	x;
	double	y;
	double	dist;
	int		order;
}				t_sprites;

typedef struct s_temp
{
	double	first;
	int		second;
}					t_temp;

typedef struct s_bmp
{
	int				fd;
	int				size;
	int				h2;
	unsigned char	*head;
	int				clr;
	int				offset;
}					t_bmp;

typedef struct s_all
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
	double			moveSpeed;
	double			rorate;
	int				**buf;
	int				flag_r;
	int				flag_no;
	int				flag_so;
	int				flag_ea;
	int				flag_we;
	int				flag_s;
	int				flag_f;
	int				flag_c;
	int				num_sp;
	double			**mass_sp;
	double			transfx;
	double			transfy;
	int				dr_startx;
	int				dr_starty;
	int				dr_drendx;
	int				dr_drendy;
	int				spritescreen_x;
	double			*zbuff;
	double			sp_x;
	double			sp_y;
	int				s_texx;
	int				s_texy;
	int				d;
	int				s_clr;
	int				mvscreen;
	int				sp_width;
	int				sp_heigth;
	t_bmp			bmp;
	t_list			newlist;
	int				**c_map;
	int				flag_map;
	int				x;
	double			dir_x_old;
	double			plane_x_old;
	double			invd;
	int				fd;
	char			**tmp;
	t_list			*head;
	int				j;
}				t_all;

void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
char	**make_map(t_list **head, t_all *all, int size);
int		ft_window(t_map_p *map);
void	draw_screen(t_all *all);
void	ft_init_w(t_window *win);
void	parse(char *line, t_all *all);
int		ft_mapsize(t_map_p *map);
void	ft_init_map(t_all *all);
int		create_trgb(int t, int r, int g, int b);
void	ft_init_w(t_window *win);
void	ft_init_scale(t_scale *mashtab);
void	ft_scale_map(t_window *win, int x, int y, int color);
void	ft_init_tex(t_texture *tex);
int		ft_cast_ray(t_all *all);
void	ft_init_plr(t_map_p *map, t_plr *player);
void	ft_inint_plr_str(t_plr *player);
int		keypress(int key, t_all *all);
void	sprites_main(t_all *all, int x);
void	draw_sp(t_all *all, int x);
void	ft_clac_hw_sp(t_all *all);
void	ft_sp(t_all *all, int i);
void	sprite_sort(int *order, double *dist, int amount);
void	sort_order(t_temp *orders, int amount);
void	ft_coord_sprite(t_all *all);
void	ft_count_sprites(t_all *all);
void	bmp_save(t_all *all, char *argv);
int		sprite(t_all *all, int x);
void	ft_draw_textures(t_all *all, int i, int x);
void	wrongs_pars_color(t_all *all);
void	wrongs_pars_resolution(t_all *all);
void	wrongs_pars_texture(t_all *all);
void	init_flags(t_all *all);
void	valid_map(char *line);
void	map_spec(char *line);
void	map_zamk(t_all *all);
void	from_main(t_all *all, int argc);
void	draw_tex(t_all *all, int i, int x);
void	line_h_clac(t_all *all);
void	coord_tex(t_all *all);
void	ft_set_wall(t_all *all, int x);
void	ft_set_tex_ns(t_all *all);
void	ft_set_tex_we(t_all *all);
void	ft_set_tex_sp(t_all *all);
int		create_trgb(int t, int r, int g, int b);
int		ft_exit(t_all *all);
void	split_dalshe(t_all *all);
int		ft_exit_malloc(void);
void	key_press_ror_l(int key, t_all *all);
void	key_press_ror_r(int key, t_all *all);
void	key_press_rl(int key, t_all *all);
char	check_zap(char *line);
size_t	words_count(char const *s, char sp);
void	parse_text_so(t_all *all);
void	parse_resol(t_all *all);
void	write_rgb(t_all *all, char *line);
void	parse_text_s(t_all *all);
void	parse_color_fc(t_all *all, char *line);
void	parse_text_we_ea(t_all *all, char *line);
void	parse_text_no(t_all *all);
int		malloc_alloc(t_all *all);

#endif
