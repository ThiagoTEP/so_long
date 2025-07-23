/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:25:32 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/22 14:26:52 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_game *data)
{
	char	type;

	type = data->t_map.map_clone[y][x];
	if (type == 'C')
	{
		data->c_checker -= 1;
		data->t_map.map_clone[y][x] = '1';
	}
	else if (type == 'E')
	{
		data->e_checker -= 1;
		data->t_map.map_clone[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		data->t_map.map_clone[y][x] = '1';
	else
		return ;
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

int	check_path(t_game *data)
{
	player_position(data);
	data->c_checker = data->colect;
	data->e_checker = data->exit;
	flood_fill(data->player_x, data->player_y, data);
	if (data->c_checker != 0 || data->e_checker >= data->exit)
		return (0);
	return (1);
}
