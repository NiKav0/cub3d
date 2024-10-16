/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:10:52 by calmouht          #+#    #+#             */
/*   Updated: 2024/10/14 22:00:15 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = (char *)data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, double b_x, double b_y)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltay = (b_y - sin(data->player->angle) * 9) - b_y;
	deltax = (b_x + cos(data->player->angle) * 9) - b_x;
	pixels = data->rays_dist[WIN_WIDTH / 2];
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(data->img, b_x, b_y, 0xFF1818);
		b_x += deltax;
		b_y += deltay;
		--pixels;
	}
}

static void	draw_pixels(t_data *data, int j, int mx, int my)
{
	int	i;
	int	x;

	x = data->minimap->box;
	i = 0;
	while (i < MINI * data->minimap->box)
	{
		if (my < 0 || mx < 0 || my / x > data->game->map_height - 1 || mx / \
		x > data->game->map_width - 1 || data->game->map[my / x][mx / x] == ' ')
			my_mlx_pixel_put(data->img, i, j, 0x7058FF);
		else if (data->game->map[my / x][mx / x] == '1')
			my_mlx_pixel_put(data->img, i, j, 0x9958FF);
		else if (data->game->map[my / x][mx / x] == '0' || \
		ft_strchr("NSWE", data->game->map[my / x][mx / x]))
			my_mlx_pixel_put(data->img, i, j, 0xD2DAFF);
		i++;
		mx++;
	}
}

void	draw_map(t_data *data, double mini_p_x, double mini_p_y)
{
	int	my;
	int	mx;
	int	j;

	my = mini_p_y - MINI / 2 * data->minimap->box;
	mx = mini_p_x - MINI / 2 * data->minimap->box;
	j = 0;
	while (j < MINI * data->minimap->box)
	{
		draw_pixels(data, j, mx, my);
		j++;
		my++;
	}
	draw_line(data, MINI / 2 * 6, MINI / 2 * 6);
	get_distance(data);
}
