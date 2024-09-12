#include "map.h"

int	parse_infos(int fd, t_map *infos)
{
	char **first_half;
	char **second_half;
	int	i;

	first_half = get_infos(fd, infos);
	if (check_textures(infos) == 0)
		return (write(2, "Error\nInvalid texture path.\n", 28), 1);
	if (check_rgb(infos) == 0)
		return (write(2, "Error\nInvalid RGB values.\n", 26), 1);
	second_half = get_map(fd, infos);
	i = 0;
	while(second_half[i])
	{
		printf("%s\n", second_half[i]);
		i++;
	}
	return (0);
}