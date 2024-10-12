/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:08:35 by calmouht          #+#    #+#             */
/*   Updated: 2024/10/12 06:29:07 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;
	size_t			i;

	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	i = 0;
	if (!s_ptr && !d_ptr)
		return (NULL);
	while (n > i)
	{
		d_ptr[i] = s_ptr[i];
		i++;
	}
	return (dest);
}
