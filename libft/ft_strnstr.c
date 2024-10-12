/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:09:59 by calmouht          #+#    #+#             */
/*   Updated: 2024/10/12 06:30:09 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;
	char	*sr;
	char	*to_find;

	sr = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	b = 0;
	if (!to_find[b])
		return (sr);
	if (!sr[b])
		return (NULL);
	while (i < len)
	{
		b = 0;
		while (sr[i + b] == to_find[b] && to_find[b] && i + b < len)
		{
			if (!to_find[b + 1])
				return (&sr[i]);
			b++;
		}
		i++;
	}
	return (NULL);
}
