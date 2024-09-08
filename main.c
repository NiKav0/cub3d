#include "map.h"

int	check_extension(char *file)
{
	char		*ext;
	size_t		len;

	ext = ft_strrchr(file, '.');
	len = ft_strlen(ext);
	if (!ext || len != 4 || ext[len - 1] != 'b' || ext[len - 2] != 'u'
		|| ext[len - 3] != 'c' || ext[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int fd;
	t_map mapping;

	if (ac != 2)
		return (write(2, "Error: Make sure you entered 2 arguments.\n", 42), 1);
	ft_bzero(&mapping, sizeof(t_map));
	if (!check_extension(av[1]))
		return (write(2, "Error: Invalid file extension.\n", 30), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "File not opened/found\n", 20), 1);
	if (parse_infos(fd, &mapping) == 1)
		return (free_data(&mapping), 1);
	// if (parse_map(av[1]) != 0)
	// 	return (write(2, "Error: Map parsing failed.\n", 27), 1);
	return (0);
}
