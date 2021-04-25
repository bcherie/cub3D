void ft_wrongs(int argc, char **argv, t_all *all)
{

    if (argc < 2 || argc > 3)
    {
        printf("Error\nWrong arguement number");
        exit(0);
    }

    if (!(all = (t_all *)malloc(sizeof(t_all))))
	{
		printf("Error\nMalloc error");
		exit(0);
	}
}

void ft_map_res_fc()
{
    if ((line[i] == 'C' || line[i] == 'F') && j != 4)
    {
	    printf("Error: wrong spec\n");
        exit(0);
    }
}