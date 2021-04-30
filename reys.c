#include "ft_cub.h"

// void ft_draw_textures(t_all *all, int x)
// {
// 	if (all->rc.side == 0)
// 		all->rc.wallx = all->player->y + all->rc.perpwalldist * all->rc.raydiry;
//     else
// 		all->rc.wallx = all->player->x + all->rc.perpwalldist * all->rc.raydirx;
//     all->rc.wallx -= floor((all->rc.wallx));
// 	all->rc.texx = (int)(all->rc.wallx * (double)(all->current.img_width));
// 	if(all->rc.side == 0 && all->rc.raydirx > 0)
// 		all->rc.texx = all->current.img_width - all->rc.texx - 1;
// 	if(all->rc.side == 1 && all->rc.raydiry < 0)
// 		all->rc.texx = all->current.img_width - all->rc.texx - 1;
// 	all->rc.step = 1.0 * all->current.img_height / all->rc.lineheight;
// 	all->rc.texpos = (all->rc.drawstart - all->map->hight / 2 + all->rc.lineheight / 2) * all->rc.step;
// 	while (all->rc.drawstart < all->rc.drawend)
// 	{
// 		all->rc.texy = (int)all->rc.texpos & (all->current.img_height - 1);
// 		all->rc.color = *(unsigned int*)(all->current.img_addr + (all->rc.texy * \
// 		all->current.llength + all->rc.texx * \
// 		(all->current.bpp / 8)));
// 		my_mlx_pixel_put(all, x, all->rc.drawstart, all->rc.color);
// 		all->rc.texpos += all->rc.step;
// 		all->rc.drawstart++;
// 	}
// }

// static void	draw(t_all *all)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y++ < all->map->hight)
// 	{
// 		x = 0;
// 		while (x++ < all->map->width)
// 			all->current.img_addr[y * all->map->width + x] = all->buf[y][x];
// 	}
// 	mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, all->current.img, 0, 0);
// }

// static void	ft_draw_wall(t_all *all, int x)
// {
// 	int		y;
// 	//int color;
// 	// x coordinate on the texture:
// 	//int texNum = all->map->map_m[all->rc.mapx][all->rc.mapy];
// 	all->rc.texx = (int)(all->rc.wallx * (double)all->current.img_width);
//     if(all->rc.side == 0 && all->rc.raydirx > 0)
// 		all->rc.texx = all->current.img_width - all->rc.texx - 1;
//     if(all->rc.side == 1 && all->rc.raydiry < 0)
// 		all->rc.texx = all->current.img_width - all->rc.texx - 1;

// 	// How much to increase the texture coordinate perscreen pixel:
// 	all->rc.step = 1.0 * all->current.img_height / all->rc.lineheight;
//     all->rc.texpos = (all->rc.drawstart - all->map->hight / 2 + all->rc.lineheight / 2) * all->rc.step;
// 	y = all->rc.drawstart;
//     while (y < all->rc.drawend)
//     {
//         all->rc.texy = (int)all->rc.texpos & (all->current.img_height - 1);
//         // all->rc.texpos += all->rc.step;
//         all->rc.color = *(unsigned int*)(all->current.img_addr + (all->rc.texy * \
// 		all->current.img_height + all->rc.texx * \
// 		(all->current.bpp / 8)));
// 		// int color = all->current[texNum][all->current.img_height * all->rc.texy + all->rc.texx];
// 		// if (all->rc.side == 1)
// 		// 		color = (color >> 1) & 8355711;
// 		// 	all->buf[y][x] = color;
// 		//printf("color: %d\n", all->rc.color);
//         //my_mlx_pixel_put(all->win->mlx_w, x, y, all->rc.color);
// 		my_mlx_pixel_put(all, x, y, all->rc.color);
// 		all->rc.texpos += all->rc.step;
// 		y++;
// 	}
// }

//звпись текстур в рабочую:
static void ft_texture(t_all *all)
{
	if (all->rc.side == 0 && all->rc.raydirx > 0)
		all->current = all->ea;
	if (all->rc.side == 0 && all->rc.raydirx < 0)
		all->current = all->we;
	if (all->rc.side == 1 && all->rc.raydiry > 0)
		all->current = all->so;
	if (all->rc.side == 1 && all->rc.raydiry < 0)
		all->current = all->no;
}

// void		sprite(t_all *all, int x)
// {
// 	// int y;
// 	int i;
// 	i = 0;

// 	// all->zBuffer[x] = all->rc.perpwalldist;
// 	//all->sprites = (t_sprites *)malloc(sizeof(t_sprites) * all->num_sp);
// 	ft_coord_sprite(all);
// 	int *tmp_order;
// 	double  *dist;
// 	tmp_order = malloc(sizeof(int) * all->num_sp);
// 	dist = malloc(sizeof(double) * all->num_sp);
// 	all->sprites->order = 0;
// 	while (all->sprites->order < all->num_sp)
// 	{
// 		tmp_order[all->sprites->order] = all->sprites->order;
// 		//dist[all->sprites->order] = ((all->player->x - all->mass_sp[all->sprites->order][0]) * (all->player->x - all->mass_sp[all->sprites->order][0]) + (all->player->y - all->mass_sp[all->sprites->order][1]) * (all->player->y - all->mass_sp[all->sprites->order][1]));
// 		dist[all->sprites->order] = sqrt(pow(all->player->x - all->mass_sp[all->sprites->order][0], 2) + pow(all->player->y - all->mass_sp[all->sprites->order][1], 2));
// 		all->sprites->order++;
// 	}
// 	sprite_sort(tmp_order, dist, all->num_sp);
// 	all->sprites->order = 0;
// 	while (all->sprites->order < all->num_sp)
// 	{
// 		//translate sprite position to relative to camera
// 		all->sp_x = all->mass_sp[tmp_order[all->sprites->order]][0] - all->player->x;
// 		all->sp_y = all->mass_sp[tmp_order[all->sprites->order]][1] - all->player->y;
// 		// printf("mass_sp[0]: %f", all->mass_sp[tmp_order[all->sprites->order]][0]);
// 		// printf("mass_sp[1]: %f", all->mass_sp[tmp_order[all->sprites->order]][1]);
// 		// all->sprites->dist[all->sprites->order] = ((all->player->x
// 		// 		- all->mass_sp[all->sprites->order][0]) * (all->player->x
// 		// 		- all->mass_sp[all->sprites->order][0]) + (all->player->y
// 		// 		- all->mass_sp[all->sprites->order][1]) * (all->player->y
// 		// 		- all->mass_sp[all->sprites->order][1]));
// 		double invDet = 1.0 / (all->player->plane_x * all->player->dir_y - all->player->dir_x * all->player->plane_y); //required for correct matrix multiplication

// 		all->transfx = invDet * (all->player->dir_y * all->sp_x - all->player->dir_x * all->sp_y);
// 		all->transfy = invDet * (-all->player->plane_y * all->sp_x + all->player->plane_x * all->sp_y); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
// 		all->spritescreen_x = (int)((all->map->width / 2) * (1 + all->transfx / all->transfy));

// 		//parameters for scaling and moving the sprites
// 		all->mvscreen = (int)(MOVE / all->transfy);

// 		all->sp_heigth = (int)fabs((all->map->hight / all->transfy) / 1);
// 			//calculate lowest and highest pixel to fill in current stripe
// 		all->dr_starty = -all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
// 		if(all->dr_starty < 0)
// 			all->dr_starty = 0;
// 		all->dr_drendy = all->sp_heigth / 2 + all->map->hight / 2 + all->mvscreen;
// 		if(all->dr_drendy >= all->map->hight)
// 			all->dr_drendy = all->map->hight - 1;

// 		//calculate width of the sprite
// 		all->sp_width = (int)fabs((all->map->hight / all->transfy) / 1);
// 		all->dr_startx = -all->sp_width / 2 + all->spritescreen_x;
// 		if(all->dr_startx < 0)
// 			all->dr_startx = 0;
// 		all->dr_drendx = all->sp_width / 2 + all->spritescreen_x;
// 		if(all->dr_drendx >= all->map->width)
// 			all->dr_drendx = all->map->width - 1;

// 		x = all->dr_startx;
// 		// y = 0;
// 		//int stripe;
// 		draw_sp(all, x);
// 		// int y = all->dr_starty;
// 		// while (y <= all->dr_drendy)
//     	// {
// 		// 	int d = (y - all->mvscreen) * 256 - all->map->hight * 128 + all->sp.img_height * 128; //256 and 128 factors to avoid floats
// 		// 	int s_texy = ((d * TEX_HEIGHT) / all->sp.img_height) / 256;
// 		// 	//x = 0;
// 		// 	//x = all->dr_startx;
// 		// 	while (x <= all->dr_drendx)
// 		// 	{
// 		// 		int s_texx = (int)((256 * (x - (-all->sp.img_width / 2 + all->spritescreen_x)) * TEX_WIDTH / all->sp.img_width) / 256);
// 		// 		int color = *(unsigned int*)(all->sp.img_addr + (s_texy * \
// 		// 		all->sp.llength + s_texx * \
// 		// 		(all->sp.bpp / 8)));
// 		// 		if(all->transfy > 0 && x > 0 && x < all->map->width && all->transfy < all->zBuffer[x])
// 		// 			my_mlx_pixel_put(all, x, y, color);
// 		// 		x++;
// 		// 	}
// 		// 	y++;
//     	// }
// 		// int y;
// 		// int stripe = all->dr_startx;
// 		// while (x < all->dr_drendx)
// 		// {
// 		// 	int s_texx = (int)((256 * (x - (-all->sp.img_width / 2 + all->spritescreen_x)) * TEX_WIDTH / all->sp.img_width) / 256);
// 		// 	if(all->transfy > 0 && x > 0 && x < all->map->width && all->transfy < all->zBuffer[x])
// 		// 	{
// 		// 		y = all->dr_starty;
// 		// 		while (y < all->dr_drendy)
// 		// 		{
// 		// 			int d = (y - all->mvscreen) * 256 - all->map->hight * 128 + all->sp.img_height * 128; //256 and 128 factors to avoid floats
// 		// 			int s_texy = ((d * TEX_HEIGHT) / all->sp.img_height) / 256;
// 		// 			int color = all->mass_sp[tmp_order[all->sprites->order]][TEX_WIDTH * s_texy + s_texx]; //get current color from the texture
// 		// 			if((color & 0x00FFFFFF) != 0)
// 		// 				all->buf[y][x] = color;
// 		// 			y++;
// 		// 		}
// 		// 	}
// 		// 	x++;
// 		// }
// 		all->sprites->order++;
// 	}
// }

static void ft_set_wall(t_all *all, int x)
{
	int i;
	i = 0;
	//Calculate height of line to draw on screen:
	all->rc.lineheight = (int)(all->map->hight / all->rc.perpwalldist);
	//calculate lowest and highest pixel to fill in current stripe:
	//all->rc.drawstart = -all->rc.lineheight / 2 + all->map->hight / 2;
	all->rc.drawstart = all->map->hight / 2 - all->rc.lineheight / 2;
	if (all->rc.drawstart < 0)
		all->rc.drawstart = 0;
	all->rc.drawend = all->rc.lineheight / 2 + all->map->hight / 2;
	// think about it
	if (all->rc.drawend >= all->map->hight)
		all->rc.drawend = all->map->hight - 1;
	//draw ceil
	while (i < all->rc.drawstart)
	{
		my_mlx_pixel_put(all, x, i, all->map->ceil);
		i++;
	}

	//draw textures:
	ft_texture(all);
	if (all->rc.side == 0)
		all->rc.wallx = all->player->y + all->rc.perpwalldist * all->rc.raydiry;
	else
		all->rc.wallx = all->player->x + all->rc.perpwalldist * all->rc.raydirx;
	all->rc.wallx -= floor((all->rc.wallx));
	//x coordinate on the texture
	all->rc.texx = (int)(all->rc.wallx * (double)(all->current.img_width));
	if (all->rc.side == 0 && all->rc.raydirx > 0)
		all->rc.texx = all->current.img_width - all->rc.texx - 1;
	if (all->rc.side == 1 && all->rc.raydiry < 0)
		all->rc.texx = all->current.img_width - all->rc.texx - 1;

	all->rc.step = 1.0 * all->current.img_height / all->rc.lineheight;
	all->rc.texpos = (all->rc.drawstart - all->map->hight / 2 + all->rc.lineheight / 2) * all->rc.step;
	//variant tex:
	//ft_draw_textures(all, i, x);
	while (i < all->rc.drawend)
	{
		all->rc.texy = (int)all->rc.texpos & (all->current.img_height - 1);
		all->rc.color = *(unsigned int *)(all->current.img_addr + (all->rc.texy *
																	   all->current.llength +
																   all->rc.texx *
																	   (all->current.bpp / 8)));
		if (all->rc.side == 1)
		{
			if (all->rc.raydiry < 0)
				my_mlx_pixel_put(all, x, i, all->rc.color);
			else if (all->rc.raydiry > 0)
				my_mlx_pixel_put(all, x, i, all->rc.color);
		}
		else if (all->rc.side == 0)
		{
			if (all->rc.raydirx > 0)
				my_mlx_pixel_put(all, x, i, all->rc.color);
			else if (all->rc.raydirx < 0)
				my_mlx_pixel_put(all, x, i, all->rc.color);
		}
		all->rc.texpos += all->rc.step;
		i++;
	}

	//draw floor
	while (i < all->map->hight)
	{
		//my_mlx_pixel_put(all, x, i, 0x00FFFFFF);
		my_mlx_pixel_put(all, x, i, all->map->floor);
		i++;
	}
}

static void ft_dda(t_all *all)
{
	while (all->rc.hit == 0)
	{
		if (all->rc.sidedistx < all->rc.sidedisty)
		{
			all->rc.sidedistx += all->rc.deltadistx;
			all->rc.mapx += all->rc.stepx;
			all->rc.side = 0;
		}
		else
		{
			all->rc.sidedisty += all->rc.deltadisty;
			all->rc.mapy += all->rc.stepy;
			all->rc.side = 1;
		}
		// printf("POV: %f %f\n", all->player->x, all->player->y);
		// printf("CamPX: %f\nCamPY: %f\n", all->player->plane_x, all->player->plane_y);
		// printf("Map: %c at: %d %d\n", all->map->map_m[all->rc.mapy][all->rc.mapx], all->rc.mapy, all->rc.mapx);
		// провекрка, ударился ли луч обстену:
		if (all->map->map_m[all->rc.mapy][all->rc.mapx] == '1')
			all->rc.hit = 1;
	}
	if (all->rc.side == 0)
		all->rc.perpwalldist = (all->rc.mapx - all->player->x + (1 - all->rc.stepx) / 2) / all->rc.raydirx;
	else
		all->rc.perpwalldist = (all->rc.mapy - all->player->y + (1 - all->rc.stepy) / 2) / all->rc.raydiry;
}

static void ft_steps(t_all *all)
{
	if (all->rc.raydirx < 0)
	{
		all->rc.stepx = -1;
		all->rc.sidedistx = (all->player->x - all->rc.mapx) * all->rc.deltadistx;
	}
	else
	{
		all->rc.stepx = 1;
		all->rc.sidedistx = (all->rc.mapx + 1.0 - all->player->x) * all->rc.deltadistx;
	}
	if (all->rc.raydiry < 0)
	{
		all->rc.stepy = -1;
		all->rc.sidedisty = (all->player->y - all->rc.mapy) * all->rc.deltadisty;
	}
	else
	{
		all->rc.stepy = 1;
		all->rc.sidedisty = (all->rc.mapy + 1.0 - all->player->y) * all->rc.deltadisty;
	}
}

static void ft_init_rc(t_all *all, int x)
{
	all->rc.camerax = 2 * x / (double)all->map->width - 1;
	all->rc.raydirx = all->player->dir_x + all->player->plane_x * all->rc.camerax;
	all->rc.raydiry = all->player->dir_y + all->player->plane_y * all->rc.camerax;
	all->rc.mapx = (int)all->player->x;
	all->rc.mapy = (int)all->player->y;
	///length of ray from one x or y-side to next x or y-side:
	all->rc.deltadistx = fabs(1 / all->rc.raydirx);
	all->rc.deltadisty = fabs(1 / all->rc.raydiry);
}

void ft_cast_ray(t_all *all)
{
	int x;

	x = 0;
	while (x < all->map->width) //current.img_width
	{
		ft_init_rc(all, x);
		ft_steps(all);
		all->rc.hit = 0;
		ft_dda(all);
		ft_set_wall(all, x);
		//sprites_main(all, x);
		//ft_draw_wall(all, x);
		all->zBuffer = malloc(sizeof(double) * all->map->width);
		all->zBuffer[x] = all->rc.perpwalldist;
		sprite(all, x);
		// sprite(all, x);
		x++;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, all->data.img, 0, 0);
	//draw(all);
}

void ft_init_plr(t_map_p *map, t_plr *player)
{
	//t_point pos;
	int x;
	int y;

	y = 0;
	// t_plr *player = NULL;
	// player = malloc(sizeof(t_plr));
	// ft_inint_plr_str(player);

	//ft_bzero(&pos, sizeof(t_point));
	// ft_bzero(player, sizeof(t_plr));
	while (map->map_m[y])
	{
		x = 0;
		while (map->map_m[y][x])
		{
			if (ft_strchr("NEWS", map->map_m[y][x]))
			{
				player->x = x + 0.5;
				player->y = y + 0.5;
				// player->dir = 3 * M_PI_2;
				if (map->map_m[y][x] == 'N')
				{
					player->dir_x = 0.0;
					player->dir_y = -1.0;
					player->plane_x = player->dir_y * 0.66;
					player->plane_y = 0;
				}
				else if (map->map_m[y][x] == 'S')
				{
					player->dir_x = 0.0;
					player->dir_y = 1.0;
					player->plane_x = player->dir_y * 0.66;
					player->plane_y = 0;
				}
				else if (map->map_m[y][x] == 'W')
				{
					player->dir_x = 1.0;
					player->dir_y = 0.0;
					//player->plane_y = player->dir_x * 0.66;
					player->plane_y = -0.66;
					player->plane_x = 0;
				}
				else if (map->map_m[y][x] == 'E')
				{
					player->dir_x = -1.0;
					player->dir_y = 0.0;
					//player->plane_y = player->dir_x * 0.66;
					player->plane_y = 0.66;
					player->plane_x = 0;
				}
				break;
			}
			x++;
		}
		y++;
	}
	//ft_draw_player(map, player);
	//ft_scale_map(win, player->x, player->y, 0x00FF00);
}

int keypress(int key, t_all *all)
{
	all->rorate = 0.05;
	all->moveSpeed = 0.08;
	double oldDirX;
	double oldPlaneX;
	//move forward if no wall in front of you
	if (key == W)
	{
		if (all->map->map_m[(int)(all->player->y + all->player->dir_y * 0.5)][(int)(all->player->x)] != '1')
			all->player->y += all->player->dir_y * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x + all->player->dir_x * 0.5)] != '1')
			all->player->x += all->player->dir_x * 0.5;
	}
	//move backwards if no wall behind you
	if (key == S)
	{
		if (all->map->map_m[(int)(all->player->y - all->player->dir_y * 0.5)][(int)(all->player->x)] != '1')
			all->player->y -= all->player->dir_y * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x - all->player->dir_x * 0.5)] != '1')
			all->player->x -= all->player->dir_x * 0.5;
	}
	//left
	if (key == D)
	{
		if (all->map->map_m[(int)(all->player->y - all->player->dir_x * 0.5)][(int)(all->player->x)] != '1')
			all->player->y -= all->player->dir_x * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x - all->player->plane_x * 0.5)] != '1')
			all->player->x += all->player->plane_x * 0.5;
	}
	if (key == A)
	{
		if (all->map->map_m[(int)(all->player->y + all->player->dir_x * 0.5)][(int)(all->player->x)] != '1')
			all->player->y += all->player->dir_x * 0.5;
		if (all->map->map_m[(int)(all->player->y)][(int)(all->player->x + all->player->dir_y * 0.5)] != '1')
			all->player->x -= all->player->dir_y * 0.5;
	}

	//rotate to the right
	if (key == ARROW_R)
	{
		//both camera direction and camera plane must be rotated
		oldDirX = all->player->dir_x;

		all->player->dir_x = all->player->dir_x * cos(all->rorate) - all->player->dir_y * sin(all->rorate);
		all->player->dir_y = oldDirX * sin(all->rorate) + all->player->dir_y * cos(all->rorate);

		oldPlaneX = all->player->plane_x;

		all->player->plane_x = all->player->plane_x * cos(all->rorate) - all->player->plane_y * sin(all->rorate);
		all->player->plane_y = oldPlaneX * sin(all->rorate) + all->player->plane_y * cos(all->rorate);
	}
	//rotate to the left
	if (key == ARROW_L)
	{
		//both camera direction and camera plane must be rotated
		oldDirX = all->player->dir_x;
		all->player->dir_x = all->player->dir_x * cos(-all->rorate) - all->player->dir_y * sin(-all->rorate);
		all->player->dir_y = oldDirX * sin(-all->rorate) + all->player->dir_y * cos(-all->rorate);
		oldPlaneX = all->player->plane_x;
		all->player->plane_x = all->player->plane_x * cos(-all->rorate) - all->player->plane_y * sin(-all->rorate);
		all->player->plane_y = oldPlaneX * sin(-all->rorate) + all->player->plane_y * cos(-all->rorate);
	}
	if (key == ESC)
		exit(0);
	ft_cast_ray(all);
	return (0);
}

// int keypress(int key, t_all *all)
// {
// 	key = 0;
// 	all->map->save = 0;
//mlx_clear_window(all->win->mlx, all->win->mlx_w);
// t_plr *player = NULL;
// player = malloc(sizeof(t_plr));
// ft_inint_plr_str(player);
// ft_init_plr(all->map, player);
// if(key == 13)
// {
// 	all->player->y += sin(all->player->dir) * 4;
// 	all->player->x += cos(all->player->dir) * 4;
// }
// if(key == 1)
// {
// 	all->player->y -= sin(all->player->dir) * 4;
// 	all->player->x -= cos(all->player->dir) * 4;
// }
// if(key == 0)
// 	all->player->x -= 0.1;
// if(key == 2)
// 	all->player->x += 0.1;
// if(key == 53)
// 	exit(0);
//draw_screen(all);
// 	return (0);
// }