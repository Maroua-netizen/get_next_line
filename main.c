#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *next_line;
	int count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break;
		count++;
		printf("Line %d: %s", count, next_line);
		free(next_line);
	}
	close(fd);
}
