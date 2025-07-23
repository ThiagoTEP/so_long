/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:25:20 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/23 09:56:07 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *data)
{
	if (data->t_map.img_backg)
		mlx_destroy_image(data->mlx, data->t_map.img_backg);
	if (data->t_map.img_colect)
		mlx_destroy_image(data->mlx, data->t_map.img_colect);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player_pose);
	if (data->t_map.img_exit)
		mlx_destroy_image(data->mlx, data->t_map.img_exit);
	if (data->t_map.img_wall)
		mlx_destroy_image(data->mlx, data->t_map.img_wall);
}

int	exit_game(t_game *data)
{
	free_map(data->t_map.map);
	free_map(data->t_map.map_clone);
	free_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

int	won_game(t_game *data)
{
	write(1, "\033[1;32m🎉 SUCCESS: ", 22);
	write(1, "CONGRATULATIONS, YOU FINISHED THE GAME!!! 🎉\n\033[0m", 52);
	free_map(data->t_map.map);
	free_map(data->t_map.map_clone);
	free_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}
