#include "ft_cub.h"

static void	ft_color_to_bmp(t_all *all)
{
	int	j;
	int	i;

	i = all->map->hight - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->map->width)
		{
			all->bmp.clr = *(int *)(all->data.img_addr + (all->data.llength * i \
			+ j * (all->data.bpp / 8)));
			write(all->bmp.fd, &all->bmp.clr, 4);
			j++;
		}
		i--;
	}
}

static void	ft_head_bmp(t_all *all)
{
	all->bmp.h2 = 40;
	all->bmp.offset = 54;
	all->bmp.size = all->bmp.offset + ((all->map->width * 3) + \
	(all->map->width % 4)) * all->map->hight;
	all->bmp.head[0] = (unsigned char) 'B';
	all->bmp.head[1] = (unsigned char) 'M';
	all->bmp.head[2] = (unsigned char)all->bmp.size;
	all->bmp.head[3] = (unsigned char)(all->bmp.size >> 8);
	all->bmp.head[4] = (unsigned char)(all->bmp.size >> 16);
	all->bmp.head[5] = (unsigned char)(all->bmp.size >> 24);
	all->bmp.head[10] = (unsigned char)(all->bmp.offset);
	all->bmp.head[14] = (unsigned char)(all->bmp.h2);
	all->bmp.head[18] = (unsigned char)all->map->width;
	all->bmp.head[19] = (unsigned char)(all->map->width >> 8);
	all->bmp.head[20] = (unsigned char)(all->map->width >> 16);
	all->bmp.head[21] = (unsigned char)(all->map->width >> 24);
	all->bmp.head[22] = (unsigned char)all->map->hight;
	all->bmp.head[23] = (unsigned char)(all->map->hight >> 8);
	all->bmp.head[24] = (unsigned char)(all->map->hight >> 16);
	all->bmp.head[25] = (unsigned char)(all->map->hight >> 24);
	all->bmp.head[26] = (unsigned char)(1);
	all->bmp.head[28] = (unsigned char)(32);
	write(all->bmp.fd, all->bmp.head, 54);
	ft_color_to_bmp(all);
}

void	bmp_save(t_all *all, char *argv)
{
	all->bmp.head = ft_calloc(54, sizeof(char));
	if (ft_strlen(argv) != 6)
	{
		printf("Error\nError bmp\n");
		printf("bmp %d\n", ft_strlen(argv));
		exit(0);
	}
	else
	{
		if ((ft_strnstr(argv, "--save", 6)))
		{
			all->bmp.fd = open("bmp.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
			ft_head_bmp(all);
			printf("bmp создан\n");
			close(all->bmp.fd);
			exit(0);
		}
	}
}
