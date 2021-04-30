#include "ft_cub.h"

void from_main(t_all *all, int argc)
{
    if (!(all = (t_all *)malloc(sizeof(t_all))))
    {
        printf("Error\nMalloc error");
        exit(0);
    }
    if (argc < 2)
    {
        printf("Error\nWrong arguement number");
        exit(0);
    }
    // all->map = (t_map_p *)malloc(sizeof(t_map_p));
	// all->win = (t_window *)malloc(sizeof(t_window));
	// all->player = (t_plr *)malloc(sizeof(t_plr));
	// init_flags(all);
	// ft_init_map(all);
}