/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:11:01 by calmouht          #+#    #+#             */
/*   Updated: 2024/10/12 06:19:53 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_distance(t_data *data)
{
	double	vr_hit;
	int		count;
	double	angle;

	angle = data->player->angle - (FOV / 2);
	count = -1;
	while (++count < WIN_WIDTH)
	{
		vr_hit = get_vertical(data, angle, count);
		set_rays(data, vr_hit, count);
		get_horizontal(data, angle, count);
		angle += FOV / WIN_WIDTH;
	}
}

double	move_dist(t_data *data, double angle)
{
	double	vr_hit;
	double	hr_hit;

	vr_hit = get_vertical(data, angle, -1);
	hr_hit = get_horizontal(data, angle, -1);
	if (vr_hit < hr_hit && vr_hit)
		return (vr_hit);
	return (hr_hit);
}
