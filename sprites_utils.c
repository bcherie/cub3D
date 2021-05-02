#include "ft_cub.h"

void	ft_count_sprites(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->num_sp = 0;
	while (all->map->map_m[i])
	{
		j = 0;
		while (all->map->map_m[i][j])
		{
			if (all->map->map_m[i][j] == '2')
				all->num_sp += 1;
			j++;
		}
		i++;
	}
}

void	sort_order(t_temp *orders, int col)
{
	t_temp	temp;
	int		i;
	int		j;

	i = 0;
	while (i < col)
	{
		j = 0;
		while (j < col - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				temp.first = orders[j].first;
				temp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = temp.first;
				orders[j + 1].second = temp.second;
			}
			j++;
		}
		i++;
	}
}

void	sprite_sort(int *order, double *dist, int col)
{
	t_temp	*sprite;
	int		i;

	i = 0;
	sprite = (t_temp *)malloc(sizeof(t_temp) * col);
	while (i < col)
	{
		sprite[i].first = dist[i];
		sprite[i].second = order[i];
		i++;
	}
	sort_order(sprite, col);
	i = 0;
	while (i < col)
	{
		dist[i] = sprite[col - i - 1].first;
		order[i] = sprite[col - i - 1].second;
		i++;
	}
	free(sprite);
}
