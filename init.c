#include "so_long.h"
#include "get_next_line.h"

void count_collectibles(t_game *g)
{
	int y = 0;
	int x;
	g->collect_total = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				g->collect_total++;
			x++;
		}
		y++;
	}
}

void init_game(t_game *g, char *file)
{
	g->mlx = mlx_init();
	g->map = read_map(file);
	g->height = 0;
	g->width = ft_strlen(g->map[0]);
	while (g->map[g->height])
		g->height++;
	g->win = mlx_new_window(g->mlx, g->width * TILE_SIZE, g->height * TILE_SIZE, "so_long");
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &g->width, &g->height);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &g->width, &g->height);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &g->width, &g->height);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &g->width, &g->height);
	g->img_collect = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &g->width, &g->height);
	g->moves = 0;
	g->collect_count = 0;
	count_collectibles(g);
}