#include "so_long.h"

int close_game(t_game *game)
{
	free_map(game->map);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit_error("Uso: ./so_long mapa.ber");
	init_game(&game, argv[1]);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}