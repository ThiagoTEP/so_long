#include "so_long.h"

void	print_moviments(int keysim, t_game *data)
{
	if (keysim == KEY_W || keysim == KEY_UP
		|| keysim == KEY_A || keysim == KEY_LEFT
		|| keysim == KEY_S || keysim == KEY_DOWN
		|| keysim == KEY_D || keysim == KEY_RIGHT)
	{
		data->moves += 1;
		ft_printf("moves ---------------- %d\n", data->moves);
	}
}

int	handle_esc(t_game *data)
{
	write(1, "\033[1;32m I hope you enjoyed the game...\n", 40);
	write(1, "...closing!\n\033[0m ", 18);
	exit_game(data);
	return (0);
}

static void	move_player(int keysym, t_game *data)
{
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		data->player_y -= 1;
		handle_w(data);
	}
	else if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		data->player_x -= 1;
		handle_a(data);
	}
	else if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		data->player_y += 1;
		handle_s(data);
	}
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		data->player_x += 1;
		handle_d(data);
	}
}

int	handle_key(int keysym, t_game *data)
{
	if (keysym == KEY_ESC)
		handle_esc(data);
	move_player(keysym, data);
	print_moviments(keysym, data);
	return (0);
}

int	start_game(t_game *data)
{
	gather_elements(data);
	render_map(data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	return (0);
}