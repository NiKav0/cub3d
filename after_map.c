#include "map.h"

char	**get_map(int fd, t_map *infos)
{
	(void)infos;
	char *line;
	char *map;
	char **second_half;
	int i;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nEmpty or no file.\n", 24);
		exit(1);
	}
	map = ft_calloc(1, 1);
	i = 0;
	while (line)
	{
		if (is_empty_line(line) == 1)
			continue;
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	second_half = ft_split(map, '\n');
	return (free(map), second_half);
}
