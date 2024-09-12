#include "map.h"

int	extract_infos(char *line, t_map *infos)
{
	// line = ft_strtrim(line, "\n");
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		infos->no = ft_datacpy(line, 2);
		return (1);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		infos->so = ft_datacpy(line, 2);
		return (1);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		infos->we = ft_datacpy(line, 2);
		return (1);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		infos->ea = ft_datacpy(line, 2);
		return (1);
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		infos->f = ft_datacpy(line, 1);
		return (1);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		infos->c = ft_datacpy(line, 1);
		return (1);
	}
	return (0);
}

char	**get_infos(int fd, t_map *infos)
{
	(void)infos;
	char *line;
	char *before_map;
	char **first_half;
	int i;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nEmpty or no file.\n", 24);
		exit(1);
	}
	before_map = ft_calloc(1, 1);
	i = 0;
	while (line)
	{
		if (is_empty_line(line) == 1)
			continue;
		line = ft_strtrim(line, " \t");
		// printf("line: %s\n", line);
		i += extract_infos(line, infos);
		before_map = ft_strjoin(before_map, line);
		free(line);
		if (i == 6)
			break ;
		line = get_next_line(fd);
	}
	// printf("line: '%s'\n",line = get_next_line(fd));
	// printf("line: '%s'\n",line = get_next_line(fd));
	first_half = ft_split(before_map, '\n');
	return (free(before_map), first_half);
}

// int check_infos(t_map *infos, char **first_half)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (first_half[i])
// 	{
// 		j += extract_infos(first_half[i], infos);
// 		if (j == 6)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
