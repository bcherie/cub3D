/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:14:52 by bcherie           #+#    #+#             */
/*   Updated: 2020/12/04 18:21:54 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int i;
	char *buf;
	int BUFFER_SIZE = 10;
	int num;

	i = 0;
	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	if (!fd)
		return (-1);
	while ((num = read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE] = '\0';
		*line = ft_strj(*line, buf);
	}
	printf("buf: %s\n", buf);
	printf("line: %s\n", (char *)line);
	printf("num: %d\n", num);
	printf("i: %d\n", i);
	printf("buf_s: %d\n", BUFFER_SIZE);
	return (0);
}

int	main()
{
	char **line;
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd, line);
	//printf("%d\n", i = get_next_line(fd, ar);
	if (fd == -1)
		return (-1);
	printf("fd: %d\n", fd);
	close(fd);
	return (0);
}


