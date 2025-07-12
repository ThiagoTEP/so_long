#include "so_long.h"
#include "ft_printf.h"

void move_player(t_game *g, int dx, int dy)
{
	int nx = g->player_x + dx;
	int ny = g->player_y + dy;
	char next = g->map[ny][nx];

	if (next == '1')
		return;
	if (next == 'C')
		g->collect_count++;
	if (next == 'E' && g->collect_count == g->collect_total)
	{
		ft_printf("Parabéns! Você venceu com %d movimentos.\n", ++g->moves);
		exit(0);
	}
	if (next != 'E')
	{
		g->map[g->player_y][g->player_x] = '0';
		g->map[ny][nx] = 'P';
		g->player_x = nx;
		g->player_y = ny;
		g->moves++;
		ft_printf("Movimentos: %d\n", g->moves);
		render_map(g);
	}
}

int handle_key(int keycode, t_game *g)
{
	if (keycode == 53) // ESC
		exit(0);
	else if (keycode == 13 || keycode == 126) // W ou cima
		move_player(g, 0, -1);
	else if (keycode == 1 || keycode == 125) // S ou baixo
		move_player(g, 0, 1);
	else if (keycode == 0 || keycode == 123) // A ou esquerda
		move_player(g, -1, 0);
	else if (keycode == 2 || keycode == 124) // D ou direita
		move_player(g, 1, 0);
	return (0);
}