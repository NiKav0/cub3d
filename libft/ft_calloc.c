/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:10:12 by calmouht          #+#    #+#             */
/*   Updated: 2022/10/22 23:10:27 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	t;
	unsigned int	i;

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
	return ((void *)dst);
}
