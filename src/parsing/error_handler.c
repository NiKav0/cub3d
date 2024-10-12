/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:11:47 by calmouht          #+#    #+#             */
/*   Updated: 2024/10/12 06:20:34 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_handler(char *message)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(message, 2);
	ft_clear(NULL);
	exit(EXIT_FAILURE);
}
