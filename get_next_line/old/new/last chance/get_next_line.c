/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                  :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:14:52 by bcherie           #+#    #+#             */
/*   Updated: 2020/12/22 15:46:52 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *rem(char **res, char **line)
{
	char *ptr;
	char *tmp;

	ptr = NULL;
	*line = ft_strdup("");
	if (*res != NULL)
	{
		if ((ptr = ft_strchr(*res, '\n')) != NULL)
		{
			//printf("res: %s\n", *res);
			*ptr = '\0';
			tmp = *line;
			*line = ft_strdup(*res);
			free(tmp);
			//tmp = *res;
			//*res = ft_strdup(++ptr);
			ft_strcpy(*res, ++ptr);
			//free(tmp);
		}
		else
		{
			tmp = *line;
			*line = ft_strdup(*res);
			//res = ft_memset(*res, 0, ft_strlen(*res));
			free(tmp);			
			//free(res);
			//res = NULL;
		}
	}
	/*else
		//line = ft_memset(res, 0, sizeof(res));
		*line = ft_strdup("");*/
	return (ptr);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int num;
	char *ptr;
	static char *res;
	char *tmp;
	// num = 1;
	//ptr = NULL;
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	ptr = rem(&res, line);
	while (!ptr && (num = read(fd, buf, BUFFER_SIZE)))
	{
		buf[num] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			ptr++;
			res = ft_strdup(ptr);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (-1);
		free (tmp);
	}
	return ((!num || !res/*ft_strlen(*line)*/) ? 0 : 1);
}

int    main()
{
    char *line;
 	int i = 0;

    int fd = open("test.txt", O_RDONLY);
    while ((i = get_next_line(fd, &line)))
 	{
     	printf("line: %s\n", line);
 		printf("return: %d\n", i);
 	}
 	printf("line: %s\n", line);
 	printf("return: %d\n", i);
    return (0);
 }
