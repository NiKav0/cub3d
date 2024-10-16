/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:12:40 by calmouht          #+#    #+#             */
/*   Updated: 2024/09/15 08:12:40 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	open_map(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		error_handler("argument error");
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strcmp(".cub", &av[1][ft_strlen(av[1]) - 4]))
		error_handler("invalid file");
	return (fd);
}

int	next_frame(t_data *data)
{
	static double	mini_p_x;
	static double	mini_p_y;

	mini_p_x = data->player->x / data->box_size * data->minimap->box;
	mini_p_y = data->player->y / data->box_size * data->minimap->box;
	change_position(data);
	draw_map(data, mini_p_x, mini_p_y);
	draw_game(data);
	circlular_minimap(data->img->addr);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 10, 10);
	mlx_put_image_to_window(data->mlx, data->win, data->player->p_img,
		MINI / 2 * 6 + 5, MINI / 2 * 6 + 5);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == W || key == S || key == UP || key == DOWN)
		data->player->walk_direction = 0;
	if (key == A || key == D)
		data->player->turn_direction = 0;
	if (key == LEFT || key == RIGHT)
		data->player->rotation_direction = 0;
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	ft_clear(&data);
	fd = open_map(ac, av);
	init_data(&data);
	get_map(fd, data.game, NULL);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	check_elements_path(&data);
	get_player_pos(&data);
	init_images(&data);
	mlx_loop_hook(data.mlx, next_frame, &data);
	mlx_hook(data.win, 2, 0, &key_handler, &data);
	mlx_hook(data.win, 3, 0, &key_release, &data);
	mlx_hook(data.win, 17, 0, &ft_clear, &data);
	mlx_loop(data.mlx);
	ft_clear(&data);
	return (0);
}
