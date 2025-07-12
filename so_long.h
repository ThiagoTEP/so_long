#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "printf.h"

# define TILE_SIZE 32

// Estrutura principal do jogo
typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int	width;
	int	height;
	int	moves;
	int	player_x;
	int	player_y;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	int	collect_total;
	int	collect_count;
} t_game;

// Funções principais
void	exit_error(char *msg);
char	**read_map(char *filename);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	init_game(t_game *game, char *file);
void	free_map(char **map);

#endif