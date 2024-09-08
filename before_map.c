#include "map.h"

int	extract_infos(char *line, t_map *infos)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		infos->no = ft_datacpy(line, 2);
	else if (ft_strncmp(line, "SO", 2) == 0)
		infos->so = ft_datacpy(line, 2);
	else if (ft_strncmp(line, "WE", 2) == 0)
		infos->we = ft_datacpy(line, 2);
	else if (ft_strncmp(line, "EA", 2) == 0)
		infos->ea = ft_datacpy(line, 2);
	else if (ft_strncmp(line, "F", 1) == 0)
		infos->f = ft_datacpy(line, 1);
	else if (ft_strncmp(line, "C", 1) == 0)
		infos->c = ft_datacpy(line, 1);
	return (1);
}

char	**get_infos(int fd, t_map *infos)
{
	char *line;
	char *before_map;
	char **first_half;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nEmpty or no file.\n", 24);
		exit(1);
	}
	before_map = ft_calloc(1, 1);
	while (line)
	{
		if (is_empty_line(line) == 1)
			continue;
		line = ft_strtrim(line, " \t");
		before_map = ft_strjoin(before_map, line);
		// printf("ZEBBI\n");
		free(line);
		line = get_next_line(fd);
		if (only_ones(line) == 0)
		{
			infos->map_line = ft_strcpy(line);
			free(line);
			break;
		}
	}
	first_half = ft_split(before_map, '\n');
	return (free(before_map), first_half);
}

int check_infos(t_map *infos, char **first_half)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (first_half[i])
	{
		j += extract_infos(first_half[i], infos);
		i++;
	}
	if (j != 6)
		return (1);
	return (0);
}
