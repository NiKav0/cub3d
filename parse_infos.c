#include "map.h"

int	parse_infos(int fd, t_map *infos)
{
	char **first_half;

	first_half = get_infos(fd, infos);
	if (check_infos(infos, first_half) == 1)
		return (write (2, "Error\nInvalid file data.\n", 25), 1);
	if (check_textures(infos) == 0)
		return (write(2, "Error\nInvalid texture path.\n", 28), 1);
	if (check_rgb(infos) == 0)
		return (write(2, "Error\nInvalid RGB values.\n", 26), 1);
	return (0);
}