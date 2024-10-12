/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collegion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:11:19 by calmouht          #+#    #+#             */
/*   Updated: 2024/09/15 08:11:20 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_collegion(t_data *data, double angle)
{
	if (data->is_horizontal[WIN_WIDTH / 2])
	{
		if ((angle > PI / 2 || angle < 3 * PI / 2) && move_dist(data, PI) - \
		50 > cos(angle) * PLAYER_SPEED)
			data->player->x = data->player->x + cos(angle) * PLAYER_SPEED;
		else if ((angle < PI / 2 || angle > 3 * PI / 2) && move_dist(data, 0) - \
		50 > cos(angle) * PLAYER_SPEED)
			data->player->x = data->player->x + cos(angle) * PLAYER_SPEED;
	}
	else if (!data->is_horizontal[WIN_WIDTH / 2])
	{
		if ((angle > 0 && angle <= PI) && move_dist(data, PI / 2) - 50 > \
		sin(angle) * PLAYER_SPEED)
			data->player->y = data->player->y - sin(angle) * PLAYER_SPEED;
		else if ((angle < 0 || angle > PI) && move_dist(data, 3 * PI / 2) - \
		50 > sin(angle) * PLAYER_SPEED)
			data->player->y = data->player->y - sin(angle) * PLAYER_SPEED;
	}
}
