#include "so_long.h"

void put_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void render_map(t_game *g)
{
	int y = 0;
	int x;

	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			put_tile(g, g->img_floor, x, y);
			if (g->map[y][x] == '1')
				put_tile(g, g->img_wall, x, y);
			else if (g->map[y][x] == 'C')
				put_tile(g, g->img_collect, x, y);
			else if (g->map[y][x] == 'E')
				put_tile(g, g->img_exit, x, y);
			else if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
				put_tile(g, g->img_player, x, y);
			}
			x++;
		}
		y++;
	}
}
