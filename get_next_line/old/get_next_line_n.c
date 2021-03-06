/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:14:52 by bcherie           #+#    #+#             */
/*   Updated: 2020/12/09 14:53:42 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char rem(char *res, char **line)
{
	char *ptr;

	ptr = NULL;
	if (res)
	{
		if ((ptr = ft_strchr(res, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(res);
			ft_strcpy(res, ++ptr);
		}
		else
		{
			*line = ft_strdup(res);
			res = ft_memset(res, 0, ft_strlen(res));
		}
	}
	else
		*line = ft_memset(res, 0, sizeof(res));
	return (ptr);
}

int get_next_line(int fd, char **line)
{

	char buf[BUFFER_SIZE + 1];
	int num;
	char *ptr;
	char *res;

	rem(res, line);
	//if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	//	return (0);
	while ((!ptr && (num = read(fd, buf, BUFFER_SIZE))))
	{
		buf[num] = '\0'; // kill rubbish after text;
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			ptr++;
			res = ft_strdup(ptr);
		}
		*line = ft_strjoin(*line, buf);
	}
	//printf("ptr: %s\n", ptr);
	return (0);
}

int	main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	//printf("ptr: %s\n", ptr);
	printf("line: %s\n", line);
	return (0);
}


