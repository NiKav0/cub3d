/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:41:32 by calmouht          #+#    #+#             */
/*   Updated: 2022/10/22 21:57:22 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d;
	unsigned int	s;

	d = ft_strlen(dst);
	if (dstsize < d)
		return (ft_strlen(src) + dstsize);
	s = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (d < (dstsize - 1) && src[s] != '\0')
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	while (src[s] != '\0')
	{
		d++;
		s++;
	}
	return (d);
}
