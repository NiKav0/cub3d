#include "map.h"
#include <fcntl.h>

int	mapping (char *file)
{
	int check;
	int i;

	i = ft_strlen(file) - 1;
	check = 0;
	while (file[i] && i > 0)
	{
		if (!(is_there("10NEWSFC \n", file[i])))
			check = 1;
		i--;
		if (file[i] == '\n' && file[i - 1] == '\n')
			return (i - 1);
	}
	return (-1);
}

int check_row (char **map, int y_pos)
{
	int x;
	int x_len;

	x = 0;
	x_len = ft_strlen(map[y_pos]);
	while (x < x_len)
	{
		if (!(is_there("0NEWSFC", map[y_pos][x])))
			return (1);
		x++;
	}
	return (0);
}

int check_begin_end (char ** map, int irtifa3)
{
	int y;
	int x_len;

	y = 0;
	while (y < irtifa3)
	{
		x_len = ft_strlen(map[y]);
		if (is_there("0NEWSFC", map[y][0]) 
			|| is_there("0NEWSFC", map[y][x_len - 1]))
			return (1);
		y++;
	}
	return (0);
}

int check_spots (char **map, int x, int y)
{
	if (is_there("0NEWSFC", map[y][x]) && 
			(not_valid(map[y - 1][x]) || 
			not_valid(map[y + 1][x]) ||
			not_valid(map[y][x - 1]) ||
			not_valid(map[y][x + 1]) ||
			not_valid(map[y - 1][x - 1]) ||
			not_valid(map[y - 1][x + 1]) ||
			not_valid(map[y + 1][x - 1]) ||
			not_valid(map[y + 1][x + 1])))
		return (1);
	else
			return (0);
}

int	check_map(t_map *map)
{
	int	x;
	int	y;
	int	rowlen;

	if (check_row(map->map, 0)
		|| check_row(map->map, map->x_len - 1)
		|| check_firstlast(map->map, map->x_len))
		return (1);
	y = 1;
	while (y < map->x_len - 1)
	{
		x = 1;
		rowlen = ft_strlen(map->map[y]);
		while (x < rowlen - 1)
		{
			if (check_spots(map->map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
