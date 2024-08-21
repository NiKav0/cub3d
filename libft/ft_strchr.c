/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:48:30 by calmouht          #+#    #+#             */
/*   Updated: 2022/10/18 01:50:51 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	str;
	char	*alt;
	int		i;

	i = 0;
	alt = (char *)s;
	str = c;
	while (alt[i] != str)
	{
		if (alt[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)alt + i);
}
