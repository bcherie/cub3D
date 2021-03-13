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
	map->floor = NULL;
	map->ceil = NULL;
	map->next = NULL;
}