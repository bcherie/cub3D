#include "ft_cub.h"

// void ft_wrongs(int argc, char **argv, t_all *all)
// {

//     if (argc < 2 || argc > 3)
//     {
//         printf("Error\nWrong arguement number");
//         exit(0);
//     }

//     if (!(all = (t_all *)malloc(sizeof(t_all))))
// 	{
// 		printf("Error\nMalloc error");
// 		exit(0);
// 	}
// }

// void ft_map_res_fc()
// {
//     if ((line[i] == 'C' || line[i] == 'F') && j != 4)
//     {
// 	    printf("Error: wrong spec\n");
//         exit(0);
//     }
// }

void wrongs_pars_color(t_all *all, int j)
{
    if (j != 4)
		{
			printf("7_Error: wrong spec\n");
			exit(0);
		}
    if ((all->map->R > 255 || all->map->G > 255 || all->map->B > 255)
        || (all->map->R < 0 || all->map->G < 0 || all->map->B < 0))
        {
            printf("Error\nError: invalid digit\n");
            exit(EXIT_SUCCESS);
        }
    if ((all->map->C_R > 255 || all->map->C_G > 255 || all->map->C_B > 255)
        || (all->map->C_R < 0 || all->map->C_G < 0 || all->map->C_B < 0))
        {
            printf("Error\nError: invalid digit\n");
            exit(EXIT_SUCCESS);
        }
}