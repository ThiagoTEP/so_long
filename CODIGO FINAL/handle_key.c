/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:25:12 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/23 10:54:33 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_img(char c, t_game *data)
{
	static char	last_dir = 0;

	if (c == last_dir)
		return ;
	last_dir = c;
	mlx_destroy_image(data->mlx, data->player_pose);
	update_door_img(data);
	if (c == 'w')
		data->player_pose = mlx_xpm_file_to_image(data->mlx,
				"./textures/player_up.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
	else if (c == 'a')
		data->player_pose = mlx_xpm_file_to_image(data->mlx,
				"./textures/player_left.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
	else if (c == 's')
		data->player_pose = mlx_xpm_file_to_image(data->mlx,
				"./textures/player_down.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
	else if (c == 'd')
		data->player_pose = mlx_xpm_file_to_image(data->mlx,
				"./textures/player_right.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
}

int	handle_w(t_game *data)
{
	update_player_img('w', data);
	if (data->t_map.map[data->player_y][data->player_x] == 'E' &&
	data->colect == 0)
		won_game(data);
	else if (data->t_map.map[data->player_y][data->player_x] == '1')
		data->player_y += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->player_y][data->player_x] == 'C')
			data->colect -= 1;
		if (data->t_map.map[data->player_y][data->player_x] != 'E')
			data->t_map.map[data->player_y][data->player_x] = 'P';
		if (data->t_map.map[data->player_y + 1][data->player_x] == 'E')
			data->t_map.map[data->player_y + 1][data->player_x] = 'E';
		else
			data->t_map.map[data->player_y + 1][data->player_x] = '0';
		render_map(data);
	}
	return (0);
}

int	handle_a(t_game *data)
{
	update_player_img('a', data);
	if (data->t_map.map[data->player_y][data->player_x] == 'E' &&
	data->colect == 0)
		won_game(data);
	else if (data->t_map.map[data->player_y][data->player_x] == '1')
		data->player_x += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->player_y][data->player_x] == 'C')
			data->colect -= 1;
		if (data->t_map.map[data->player_y][data->player_x] != 'E')
			data->t_map.map[data->player_y][data->player_x] = 'P';
		if (data->t_map.map[data->player_y][data->player_x + 1] == 'E')
			data->t_map.map[data->player_y][data->player_x + 1] = 'E';
		else
			data->t_map.map[data->player_y][data->player_x + 1] = '0';
		render_map(data);
	}
	return (0);
}

int	handle_s(t_game *data)
{
	update_player_img('s', data);
	if (data->t_map.map[data->player_y][data->player_x] == 'E' &&
	data->colect == 0)
		won_game(data);
	else if (data->t_map.map[data->player_y][data->player_x] == '1')
		data->player_y -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->player_y][data->player_x] == 'C')
			data->colect -= 1;
		if (data->t_map.map[data->player_y][data->player_x] != 'E')
			data->t_map.map[data->player_y][data->player_x] = 'P';
		if (data->t_map.map[data->player_y - 1][data->player_x] == 'E')
			data->t_map.map[data->player_y - 1][data->player_x] = 'E';
		else
			data->t_map.map[data->player_y - 1][data->player_x] = '0';
		render_map(data);
	}
	return (0);
}

int	handle_d(t_game *data)
{
	update_player_img('d', data);
	if (data->t_map.map[data->player_y][data->player_x] == 'E' &&
	data->colect == 0)
		won_game(data);
	else if (data->t_map.map[data->player_y][data->player_x] == '1')
		data->player_x -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->player_y][data->player_x] == 'C')
			data->colect -= 1;
		if (data->t_map.map[data->player_y][data->player_x] != 'E')
			data->t_map.map[data->player_y][data->player_x] = 'P';
		if (data->t_map.map[data->player_y][data->player_x - 1] == 'E')
			data->t_map.map[data->player_y][data->player_x - 1] = 'E';
		else
			data->t_map.map[data->player_y][data->player_x - 1] = '0';
		render_map(data);
	}
	return (0);
}
