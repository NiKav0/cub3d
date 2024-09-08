#include "map.h"

int	check_no(t_map *map)
{
	char		*ext;
	int			fd;
	size_t		len;

	ext = ft_strrchr(map->no, '.');
	len = ft_strlen(ext);
	if (!ext || len != 4 || ext[len - 1] != 'g' || ext[len - 2] != 'n'
		|| ext[len - 3] != 'p' || ext[len - 4] != '.')
		return (0);
	fd = open(map->no, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_so(t_map *map)
{
	char		*ext;
	int			fd;
	size_t		len;

	ext = ft_strrchr(map->so, '.');
	len = ft_strlen(ext);
	if (!ext || len != 4 || ext[len - 1] != 'g' || ext[len - 2] != 'n'
		|| ext[len - 3] != 'p' || ext[len - 4] != '.')
		return (0);
	fd = open(map->so, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_we(t_map *map)
{
	char		*ext;
	int			fd;
	size_t		len;

	ext = ft_strrchr(map->we, '.');
	len = ft_strlen(ext);
	if (!ext || len != 4 || ext[len - 1] != 'g' || ext[len - 2] != 'n'
		|| ext[len - 3] != 'p' || ext[len - 4] != '.')
		return (0);
	fd = open(map->we, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_ea(t_map *map)
{
	char		*ext;
	int			fd;
	size_t		len;

	ext = ft_strrchr(map->ea, '.');
	len = ft_strlen(ext);
	if (!ext || len != 4 || ext[len - 1] != 'g' || ext[len - 2] != 'n'
		|| ext[len - 3] != 'p' || ext[len - 4] != '.')
		return (0);
	fd = open(map->ea, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_textures(t_map *infos)
{
	if (!infos->no || !infos->so || !infos->we || !infos->ea || !infos->f || !infos->c)
		return (0);
	if (infos->no[0] == '\0' || infos->so[0] == '\0'
		|| infos->we[0] == '\0' || infos->ea[0] == '\0' || infos->f[0] == '\0' || infos->c[0] == '\0')
		return (0);
	if (check_no(infos) == 0 || check_so(infos) == 0
		|| check_we(infos) == 0 || check_ea(infos) == 0)
		return (0);
	return (1);
}
