/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:07:05 by calmouht          #+#    #+#             */
/*   Updated: 2024/09/15 08:07:06 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char **s)
{
	char	*line;
	char	*to_free;
	int		i;

	to_free = *s;
	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		line = ft_gnl_substr(*s, 0, i + 1);
		*s = ft_gnl_strdup(*s + i + 1);
	}
	else
	{
		line = ft_gnl_strdup(*s);
		*s = NULL;
	}
	free(to_free);
	return (line);
}

int	ft_str(int fd, char **s)
{
	char	*bufer;
	char	*to_free;
	int		byte_read;

	bufer = (char *)malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (-1);
	byte_read = 4;
	while (!ft_gnl_strchr(*s, '\n') && byte_read)
	{
		byte_read = read(fd, bufer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(bufer);
			return (-1);
		}
		bufer[byte_read] = '\0';
		to_free = *s;
		*s = ft_gnl_strjoin(*s, bufer);
		free(to_free);
	}
	free(bufer);
	return (byte_read);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*line;
	int			byte_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s)
		s = ft_gnl_strdup("");
	byte_read = ft_str(fd, &s);
	line = ft_line(&s);
	if (byte_read <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (ft_gnl_strchr(line, '\n'))
		*(ft_gnl_strchr(line, '\n')) = 0;
	return (line);
}
