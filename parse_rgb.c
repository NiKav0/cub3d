#include "map.h"

int	first_check(char **tmp, char *str)
{
	int i;
	int j;
	int fasila;

	i = 0;
	j = 0;
	fasila = 0;
	while (str[i])
	{
		if (str[i] == ',')
			fasila++;
		i++;
	}
	while (tmp[j])
		j++;
	if (j != 3 || fasila != 2)
		return (0);
	return (1);
}
int	second_check(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
				return (0);
			j++;
		}
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb(t_map *map)
{
	char	**tmp;
	char	*new;

	if (!map->f || !map->c)
		return (0);
	new = ft_strtrim(map->f, "\n");
	tmp = ft_split(new, ',');
	if (first_check(tmp, new) == 0 || second_check(tmp) == 0)
		return (0);
	free_arr(tmp);
	free(new);
	new = ft_strtrim(map->c, "\n");
	tmp = ft_split(new, ',');
	if (first_check(tmp, new) == 0 || second_check(tmp) == 0)
		return (0);
	free_arr(tmp);
	free(new);
	return (1);
}
