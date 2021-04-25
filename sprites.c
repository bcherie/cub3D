// #include "ft_cub.h"

// void ft_coord_sprite(t_all *all)
// {
// 	int i;
// 	int j;
//     int x;

// 	i = 0;
//     x = 0;
//     all->sprites = (t_sprites *)malloc(sizeof(t_sprites) * all->num_sp);
//     //ft_bzero(all->sprites, sizeof(t_sprites));
//     all->mass_sp = ft_calloc((all->num_sp + 1), sizeof(double *));
//     //all->mass_sp[all->sprites->order] = ft_calloc(2, sizeof(double));
//     // printf("mass_sp: %p", all->mass_sp);
//     // while (all->sprites->order < all->num_sp)
// 	// {
//     //     if (!(all->mass_sp[all->sprites->order] = ft_calloc(2, sizeof(double))))
// 	// 		printf("ОШИБКА\n");
// 	// 	all->sprites->order++;
// 	// }

//     //all->sprites->order = 0;
// 	while (all->map->map_m[i])
// 	{
// 		j = 0;
// 		while (all->map->map_m[i][j])
// 		{
// 			if (all->map->map_m[i][j] == '2')
// 			{
// 				// all->mass_sp[all->sprites->order][0] = j + 0.5;
// 				// all->mass_sp[all->sprites->order][1] = i + 0.5;
//                 all->sprites[x].y = i + 0.5;
// 				all->sprites[x].x = j + 0.5;
// 				//all->sprite->dist = sqrt(pow(all->player->x - all->mass_sp[all->sprites->order][0]) + pow(all->player->x - all->mass_sp[all->sprites->order][0]));	
// 				//all->sprites->order++;
//                 x++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
//     //all->sprites->order = x;
//     //ft_sp(all);
// }

// void	sort_order(t_pair *orders, int amount)
// {
// 	t_pair	tmp;

// 	for (int i = 0; i < amount; i++)
// 	{
// 		for (int j = 0; j < amount - 1; j++)
// 		{
// 			if (orders[j].first > orders[j + 1].first)
// 			{
// 				tmp.first = orders[j].first;
// 				tmp.second = orders[j].second;
// 				orders[j].first = orders[j + 1].first;
// 				orders[j].second = orders[j + 1].second;
// 				orders[j + 1].first = tmp.first;
// 				orders[j + 1].second = tmp.second;
// 			}
// 		}
// 	}
// }

// void sprite_sort(int *order, double *dist, int amount)
// {
// 	t_pair	*sprite;
//     int i;

//     i = 0;
// 	sprite = (t_pair*)malloc(sizeof(t_pair) * amount);
// 	while (i < amount)
// 	{
// 		sprite[i].first = dist[i];
// 		sprite[i].second = order[i];
//         i++;
// 	}
// 	sort_order(sprite, amount);
// 	//std::sort(sprites.begin(), sprites.end());
// 	for (int i = 0; i < amount; i++)
// 	{
// 		dist[i] = sprite[amount - i - 1].first;
// 		order[i] = sprite[amount - i - 1].second;
// 	}
// 	free(sprite);

// }

// void ft_sp(t_all *all, int i)
// {
//     int tmp_order[all->num_sp];
//     double  dist[all->num_sp];

//     //all->sprites->order = 0;
// 	while (all->sprites->order < all->num_sp)
//     {
//     	tmp_order[all->sprites->order] = all->sprites->order;
//     	//all->sprite->dist[j] = ((all->rc.posX - sprite[j].x) * (posX - sprite[j].x) + (posY - sprite[j].y) * (posY - sprite[j].y)); //sqrt not taken, unneeded
// 		//dist[all->sprites->order] = sqrt(pow(all->player->x - all->mass_sp[all->sprites->order][0], 2) + pow(all->player->x - all->mass_sp[all->sprites->order][1], 2));
// 		all->sprites[i].dist = pow(all->player->x - all->sprites[i].x, 2) + pow(all->player->x - all->sprites[i].y, 2);
//         // all->sprites->dist[all->sprites->order] = ((all->player->x
// 		// 		- all->mass_sp[all->sprites->order][0]) * (all->player->x
// 		// 		- all->mass_sp[all->sprites->order][0]) + (all->player->y
// 		// 		- all->mass_sp[all->sprites->order][1]) * (all->player->y
// 		// 		- all->mass_sp[all->sprites->order][1]));
//         all->sprites->order++;
// 	}
//     printf("num_sp1 %d\n", all->num_sp);
//     sprite_sort(&all->sprites->order, dist, all->num_sp);
// 	all->sprites->order = 0;
//     // while (all->sprites->order < all->num_sp)
// 	// {
// 		//translate sprite position to relative to camera
// 		// all->sp_x = all->mass_sp[tmp_order[all->sprites->order]][0] - all->player->x;
// 		// all->sp_y = all->mass_sp[tmp_order[all->sprites->order]][1] - all->player->y;
//         all->sp_x = all->sprites[all->sprites[i].order].x - all->player->x;
//         all->sp_x = all->sprites[all->sprites[i].order].y - all->player->y;

//         //transform sprite:
// 		double invDet = 1.0 / (all->player->plane_x * all->player->dir_y - all->player->dir_x * all->player->plane_y); //required for correct matrix multiplication

// 		all->transfx = invDet * (all->player->dir_y * all->sp_x - all->player->dir_x * all->sp_y);
// 		all->transfy = invDet * (-all->player->plane_y * all->sp_x + all->player->plane_x * all->sp_y); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])


// 		all->spritescreen_x = (int)((all->map->width / 2) * (1 + all->transfx / all->transfy));

// 		//parameters for scaling and moving the sprites
// 		all->mvscreen = (int)(MOVE / all->transfy);
// }

// void ft_clac_hw_sp(t_all *all)
// {
//     all->sp.img_height = abs((int)(all->map->hight / (all->transfx))) / 1;
// 	//calculate lowest and highest pixel to fill in current stripe
// 	all->dr_starty = -all->sp.img_height / 2 + all->map->hight / 2;
// 	if(all->dr_starty < 0)
//         all->dr_starty = 0;
// 	all->dr_drendy = all->sp.img_height / 2 + all->map->hight / 2;
// 	if(all->dr_drendy >= all->map->hight)
//         all->dr_drendy = all->map->hight - 1;

// 	//calculate width of the sprite
// 	all->sp.img_width = abs((int)(all->map->hight / (all->transfy)));
// 	all->dr_startx = -all->sp.img_width / 2 + all->spritescreen_x;
// 	if(all->dr_startx < 0)
//         all->dr_startx = 0;
// 	all->dr_drendx = all->sp.img_width / 2 + all->spritescreen_x;
// 	if(all->dr_drendx >= all->map->width)
//         all->dr_drendx = all->map->width - 1;
// }

// void draw_sp(t_all *all, int x)
// {
//     // int i = 0;
//     // for(int stripe = all->dr_startx; stripe < all->dr_drendx; stripe++)
//     // {
//     //     all->rc.texx = (int)((256 * (stripe - (-all->sp.img_width / 2 + all->spritescreen_x)) * TEX_WIDTH / all->sp.img_height) / 256);
//     //     //the conditions in the if are:
//     //     //1) it's in front of camera plane so you don't see things behind you
//     //     //2) it's on the screen (left)
//     //     //3) it's on the screen (right)
//     //     //4) ZBuffer, with perpendicular distance
//     //     if(all->transfy > 0 && stripe > 0 && stripe < all->map->width && all->transfy < all->zBuffer[stripe])
//     //     for(int y = all->dr_starty; y < all->dr_drendy; y++) //for every pixel of the current stripe
//     //     {
//     //         int d = (y-all->mvscreen) * 256 - all->map->hight * 128 + all->sp.img_height * 128; //256 and 128 factors to avoid floats
//     //         all->rc.texy = ((d * TEX_HEIGHT) / all->sp.img_height) / 256;
//     //         int color = all->mass_sp[all->sprite[all->sprites->order[i]].mass_sp][TEX_WIDTH * all->rc.texy + all->rc.texx]; //get current color from the texture
//     //         if((color & 0x00FFFFFF) != 0) all->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
//     //     }
//     // }
//     int y;
//     // int x;
//     y = 0;
// 	//int stripe = drawStartX;
// 	all->rc.texx = (int)(all->rc.wallx * (double)(all->sp.img_width));
// 	while (y <= all->dr_drendy)
//     {
// 		all->rc.texy = (int)all->rc.texpos & (all->sp.img_height - 1);
// 		all->rc.color = *(unsigned int*)(all->sp.img_addr + (all->rc.texy * \
//  		all->sp.llength + all->rc.texx * \
//  		(all->sp.bpp / 8)));
//         x = 0;
//         while (x <= all->dr_startx)
//         {
// 			my_mlx_pixel_put(all, x, y, all->rc.color);
//             //mlx_put_image_to_window(all->win->mlx, all->win->mlx_w, all->current.img, x, y);
//             x += all->sp.img_width;
//         }
//         y += all->sp.img_height;
//     }

// }

// void sprites_main(t_all *all, int x)
// {
//     int i;

//     i = 0;
//     ft_coord_sprite(all);
//     while (i < all->num_sp)
//     {
//         ft_sp(all, i);
//         ft_clac_hw_sp(all);
//         //draw_sp(all);
//         i++;
//     }
//     draw_sp(all, x);
// }