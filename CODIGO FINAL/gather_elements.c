#include "so_long.h"

static void	load_textures(t_game *data)
{
	data->t_map.img_backg = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_colect = mlx_xpm_file_to_image(data->mlx,
			"./textures/colectable.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->player_pose = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_right.xpm", &data->t_map.img_x, &data->t_map.img_y);
}

void	gather_elements(t_game *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Erro ao iniciar mlx\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, data->t_map.map_width * PIXS,
			data->t_map.map_height * PIXS, "SO_LONG");
	data->moves = 0;
	load_textures(data);
}

static void	set_exit_image(t_game *data, char *path)
{
	mlx_destroy_image(data->mlx, data->t_map.img_exit);
	data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx, path,
			&data->t_map.img_x, &data->t_map.img_y);
}

void	update_door_img(t_game *data)
{
	if (data->t_map.map[data->player_y][data->player_x] == 'E')
		set_exit_image(data, "./textures/closed_exit.xpm");
	else if ((data->t_map.map[data->player_y][data->player_x] == 'C'
			&& data->colect == 1) || data->colect == 0)
		set_exit_image(data, "./textures/o_exit.xpm");
	else
		set_exit_image(data, "./textures/exit.xpm");
}

void	player_position(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->t_map.map[y])
	{
		x = 0;
		while (data->t_map.map[y][x])
		{
			if (data->t_map.map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
}