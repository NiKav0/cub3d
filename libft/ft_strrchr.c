/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:09:50 by calmouht          #+#    #+#             */
/*   Updated: 2022/12/12 17:59:56 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		str = (char *)&s[i];
	i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (str);
}