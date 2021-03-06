#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int num;
	char *ptr;

	ptr = NULL;
	while (strcmp(*line, buf) != 0)
	{
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			break;
		}
		num = read(fd, buf, BUFFER_SIZE);
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int	main()
{
	char *line;
	line = NULL;
	int fd = open("test.txt", O_RDONLY);
	*get_next_line(fd, &line);
	//printf("ptr: %s\n", ptr);
	printf("line: %s\n", line);
	return (0);
}
