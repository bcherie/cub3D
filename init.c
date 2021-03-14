#include "ft_cub.h"

void ft_init(t_map_p *map)
{
	map->width = 0;
	map->hight = 0;
	map->path_no = NULL;
	map->path_so = NULL;
	map->path_we = NULL;
	map->path_ea = NULL;
	map->path_sprite = NULL;
	map->floor = 0;
	map->ceil = 0;
	map->next = NULL;
	map->R = 0;
	map->B = 0;
	map->G = 0;
	map->C_R = 0;
	map->C_G = 0;
	map->C_B = 0;
}