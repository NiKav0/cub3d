/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:12:36 by calmouht          #+#    #+#             */
/*   Updated: 2024/09/15 08:12:37 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	ft_isnumber(char *str)
{
	char	*bak;

	str = ft_strtrim(str, WHITE_SPACES);
	bak = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	free(bak);
	return (true);
}

int	get_rgb(char *num)
{
	char	**tmp;
	int		len;
	int		r;
	int		g;
	int		b;

	if (count(num, ',') != 2)
		error_handler("Invalid color format");
	tmp = ft_split(num, ',');
	len = -1;
	while (tmp[++len])
		if (!ft_isnumber(tmp[len]))
			error_handler("invalid color");
	if (len != 3)
		error_handler("Invalid color format");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_handler("invalid color");
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return ((r << 16) | (g << 8) | b);
}
