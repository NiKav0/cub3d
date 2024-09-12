#include <stdio.h>
#include "getnextline/get_next_line.h"

int main()
{
	char *line;
	int fd;

	fd = open("maps/map1.cub", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}