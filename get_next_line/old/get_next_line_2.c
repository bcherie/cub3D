/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:02:06 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/29 18:37:03 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*int read_file(int fd, void *buf, size_t BUFFER_SIZE)
{
	int num;
	int i;

	i = 0;
	free(buf);
	return (num);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;
	unsigned int	len_s;
	char			*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	len_s = strlen(s);
	i = 0;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	while (start < len_s && i < (unsigned int)len && *s1)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int len_line(char *buf, char n)
{
	int j;

	j = 0;
	while (buf[j] && buf[j] != n)
		j++;
	printf("j_length: %d\n", j); // length line
	return (j);
}
int get_next_line(int fd, char **line)
{
	int i;
	int llen;
	char *buf;
	int BUFFER_SIZE;
	int num;
	int k;
	int j;

	j = 0;
	k = 0;
	i = 0;
	llen = 0;	
	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	num = read(fd, buf, BUFFER_SIZE);
	if (fd < 0)
		return (ERROR);
	while (i < BUFFER_SIZE && fd >= 0)
		i++;
	buf[i] = '\0';
	printf("num: %d\n", num);
	line = (char **)malloc(sizeof(char) * num + 1);
	if (!line)
		return (0);
	//while (buf[j] && buf[j] != '\n')
	//	j++;
	//printf("j: %d\n", j);
	while (llen <= j)
	{
		while (buf[i] == '\n')
			k++;
		printf("k_index: %d\n", k); // '\n' index
		if (!(line[llen] = ft_substr(buf, k, j)))
			return (0);
		k += len_line(buf, '\n');
		llen++;
	}
	line[llen] = NULL;
	printf("%s\n", line[llen]);
	return (0);
}

int	main()
{
	char **line;

	int fd;
	fd = open("test.c", O_RDONLY);
	get_next_line(fd, line);
	//if (!i)
	//	return (-1);
	//printf("%d\n", num);
	close(fd);
	printf("fd: %d\n", fd);
	return (0);
}

