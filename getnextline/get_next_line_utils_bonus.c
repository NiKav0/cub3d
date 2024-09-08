/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:07:29 by calmouht          #+#    #+#             */
/*   Updated: 2023/01/09 14:35:13 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	int		t;
	int		i;

	t = count * size;
	dst = malloc(t);
	if (!dst)
		return (NULL);
	i = 0;
	while (t--)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}

ssize_t	position(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	r = ft_calloc(ft_strleng(s1) + ft_strleng(s2) + 1, 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (r);
}

size_t	ft_strleng(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_substrg(char *s, unsigned int start, size_t len)
{
	size_t			b;
	char			*subs;
	unsigned int	test;

	if (!s)
	{
		return (0);
	}
	if (len > ft_strleng(s))
		len = ft_strleng(s);
	b = 0;
	test = ft_strleng(s);
	subs = malloc(len * sizeof(char) + 1);
	if (!subs)
		return (0);
	while (b < len && test >= start)
	{
		subs[b] = s[start];
		b++;
		start++;
	}
	subs[b] = '\0';
	return (subs);
}
