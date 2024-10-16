/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:12:28 by calmouht          #+#    #+#             */
/*   Updated: 2024/09/15 08:12:29 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	get_pixel(t_img *img, int x, int y, double wall_height)
{
	int				color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	brightness;

	y = ((y - (((WIN_HEIGHT - wall_height) / 2))) * img->height) / wall_height;
	color = img->addr[y * (img->line_length / 4) + x];
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	brightness = 0xFF * (wall_height * VIEW_RANGE) / WIN_HEIGHT;
	r = r * brightness / 0xFF;
	g = g * brightness / 0xFF;
	b = b * brightness / 0xFF;
	if (r > (color & 0xFF0000) >> 16)
		r = (color & 0xFF0000) >> 16;
	if (g > (color & 0xFF00) >> 8)
		g = (color & 0xFF00) >> 8;
	if (b > (color & 0xFF))
		b = (color & 0xFF);
	return (r << 16 | g << 8 | b);
}
/*
		WIN_HEIGHT -> 0xFF
		wallheight -> brightness
*/
