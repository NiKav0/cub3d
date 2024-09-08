#include "map.h"

char	*ft_datacpy(char *src, int n)
{
	char	*dst;
	char	*tmp;
	int		i;
	int		j;

	if (!src)
		return (NULL);
	i = n;
	tmp = malloc((ft_strlen(src) - i + 1) * sizeof(char));
	if (!tmp)
		exit(1);
	j = 0;
	while (src[i] != '\0')
	{
		tmp[j] = src[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	dst = ft_strtrim(tmp, "\t ");
	free(tmp);
	return (dst);
}
void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_data(t_map *data)
{
	if (data->map_line)
		free(data->map_line);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
	if (data->map)
		free_arr(data->map);
}

char	*ft_strcpy(char *src)
{
	int	i;
	char *dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		exit(1);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
