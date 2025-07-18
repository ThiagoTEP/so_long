#include "so_long.h"


int	handle_args(char *arg)
{
	int	size;

	size = ft_strlen(arg);
	if (size > 4)
	{
		if (arg[size - 1] == 'r' && arg[size - 2] == 'e'
			&& arg[size - 3] == 'b' && arg[size - 4] == '.')
			return (1);
	}
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "file type .ber necessary.\n\033[0m", 31);
	return (0);
}

static void	exit_with_cleanup(t_game *data)
{
	if (data->t_map.map)
	{
		free_map(data->t_map.map);
		free_map(data->t_map.map_clone);
	}
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_game	data;

	if (argc == 2)
	{
		ft_memset(&data, 0, sizeof(t_game));
		read_map(&data, argv[1]);
		if (handle_args(argv[1]) && check_map(&data))
		{
			start_game(&data);
			mlx_loop(data.mlx);
		}
		else
			exit_with_cleanup(&data);
	}
	else
		exit(1);
	return (0);
}