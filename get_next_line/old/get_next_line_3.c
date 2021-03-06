#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*int read_file(int fd, void *buf, size_t BUFFER_SIZE)
*/
int get_next_line(int fd, char **line)
{
	int i;
	char *buf;
	//static int buf_col = 1;
	int BUFFER_SIZE = 4;
	int num;
	//int j;

	//j = 0;
	i = 0;
	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	//while (i < BUFFER_SIZE)
	//	i++;
	if (buf[i] != '\n')
	{
		BUFFER_SIZE *= 2;
	}
	line = (char **)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (0);
	num = read(fd, buf, BUFFER_SIZE);
	strlcpy((char *)line, buf, num + 1);
	//if (buf[i] != '\0')
	//*line = '\0';
	printf("buf: %s\n", buf);
	//printf("line: %s\n", (char *)line);
	//printf("num: %d\n", num);
	printf("buf_s: %d\n", BUFFER_SIZE);
	return (0);
}

int	main()
{
	char **line;
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd, line);
	//printf("%d\n", i = get_next_line(fd, ar);
	close(fd);
	return (0);
}

