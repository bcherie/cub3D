#include "ft_cub.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     ft_window(void)
{
  //  t_data    *img;
    void    *mlx;
    void    *mlx_w;
    int     x;
    int y;

    x = 0;
    y = 0;

    mlx = mlx_init();
    mlx_w = mlx_new_window(mlx, 540, 540, "Oasis");
    //img->img = mlx_new_image(mlx, 200, 200);
    //img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    while (y < 200)
    {
        x = 0;
        while (x < 200)
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
