/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:06:59 by calmouht          #+#    #+#             */
/*   Updated: 2023/01/09 14:39:40 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			how;
	char		*tarro;
	static char	*lba9i[1024];

	tarro = ft_calloc(BUFFER_SIZE, 1);
	how = 1;
	if (lba9i[fd])
	{
		tarro = ft_strjoin(tarro, lba9i[fd]);
		free(lba9i[fd]);
		lba9i[fd] = NULL;
	}
	tarro = reder(fd, tarro, &how);
	if (tarro && (position(tarro, '\n') != -1))
	{
		lba9i[fd] = ft_substr(tarro, (position(tarro, '\n') + 1),
				(position(tarro, '\0')));
		tarro = li_3jbek(tarro);
	}
	else if (how == 0 && ft_strlen(tarro) == 0)
	{
		free(tarro);
		return (NULL);
	}
	return (tarro);
}

char	*li_3jbek(char *str)
{
	char	*pointer;

	if (!str)
		return (NULL);
	pointer = ft_substr(str, 0, (position(str, '\n') + 1));
	free(str);
	return (pointer);
}

char	*reder(int fd, char *tarro, int *how)
{
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	while (position(buff, '\n') == -1 && *how > 0)
	{
		ft_bzero(buff, BUFFER_SIZE);
		*how = read(fd, buff, BUFFER_SIZE);
		if (*how == -1)
		{
			free(buff);
			free(tarro);
			return (NULL);
		}
		tarro = ft_strjoin(tarro, buff);
	}
	free(buff);
	return (tarro);
}

void	ft_bzero(void *s, size_t l)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < l)
	{
		str[i] = 0;
		i++;
	}
}
