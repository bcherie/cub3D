#include "ft_cub.h"

// void            my_mlx_pixel_put(t_window *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int     ft_window(t_map_p *map)
{
    void    *mlx;
    void    *mlx_w;
    int     x;
    int y;
    //t_all *all = NULL;
    //t_window *win = NULL;
    //ft_init_w(win);

    x = 0;
    y = 0;

    mlx = mlx_init();
    mlx_w = mlx_new_window(mlx, map->width, map->hight, "Oasis");
    //img->img = mlx_new_image(mlx, 200, 200);
    //img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    // draw_screen(map);
    while (y < 100)
    {
        x = 0;
        while (x < 100)
        {
            mlx_pixel_put(mlx, mlx_w, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
    //mlx_put_image_to_window(mlx, mlx_w, img->img, 0, 0);
	mlx_loop(mlx);
    return (0);
}
