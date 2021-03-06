/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:45:36 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/30 19:25:30 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "GET_NEXT_LINE"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*int read_file(int fd, void *buf, size_t BUFFER_SIZE)
*/
int get_next_line(int fd, char **line)
{
	int i;
	char *buf;
	static int buf_col = 1;
	int BUFFER_SIZE = 4;
	int num;
	int j;

	j = 0;
	i = 0;
	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	while (i < BUFFER_SIZE)
		i++;
	if (buf[i] != '\n')
	{
		BUFFER_SIZE *= 2;
		buf_col++;
	}
	else
	{
		line = (char **)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!line)
			return (0);
		num  = read(fd, buf, BUFFER_SIZE);
		while ((buf[j] && line[j]) && j < num)
			j++;
	}
	printf("buf_col: %d\n", buf_col);
	printf("line: %s\n", &line);
	printf("i: %d\n", i);
	//printf("num: %d\n", num);
	printf("buf_s: %d\n", BUFFER_SIZE);
	return (0);
}

int	main()
{
	char **line;
	int fd = open("test.c", O_RDONLY);
	get_next_line(fd, line);
	//printf("%d\n", i = get_next_line(fd, buf));
	//if (!i)
	//	return (-1);
	close(fd);
	return (0);
}
