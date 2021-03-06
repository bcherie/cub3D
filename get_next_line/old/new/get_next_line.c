/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                  :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:14:52 by bcherie           #+#    #+#             */
/*   Updated: 2020/12/23 04:13:59 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *rem(char *res, char **line)
{
	char *ptr;
	//char *tmp;

	//tmp = NULL;
	ptr = NULL;
	*line = ft_strdup("");
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
			//tmp = *line;
			*line = ft_strdup(res);
			res = ft_memset(res, 0, ft_strlen(res));
			//free(tmp);
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
	
	//tmp = NULL;
	//ptr = NULL;
	ptr = rem(res, line); // problem is here
	while ((!ptr && (num = read(fd, buf, BUFFER_SIZE))))
	{
		buf[num] = '\0'; // kill rubbish after text;
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
	//printf("ptr: %s\n", ptr);
	return ((!res) ? 0 : 1);
}

int    main()
{
    char *line;
    int fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("line: %s\n", line);
		free(line);
    }
	free(line);
    return (0);
}


