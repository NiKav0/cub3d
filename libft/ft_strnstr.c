/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:20:21 by calmouht          #+#    #+#             */
/*   Updated: 2022/10/18 01:38:35 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	char	*bp;
	char	*lp;

	if (!*n)
		return ((char *)h);
	while (len-- && *h)
	{
		if (*h == *n)
		{
			i = len;
			bp = (char *)h + 1;
			lp = (char *)n + 1;
			while (i-- && *bp && *lp && *lp == *bp)
			{
				lp++;
				bp++;
			}
			if (*lp == '\0')
				return ((char *)h);
		}
		h++;
	}
	return (NULL);
}
