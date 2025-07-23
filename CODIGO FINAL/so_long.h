/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thevaris <thevaris@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:24:42 by thevaris          #+#    #+#             */
/*   Updated: 2025/07/22 14:24:43 by thevaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MALLOC_ERROR	1
# define WIDTH 			600
# define HEIGHT 			600
# define PIXS			50

# define KEY_ESC			65307
# define KEY_W			65362
# define KEY_A			65361
# define KEY_S			65364
# define KEY_D			65363

# define KEY_UP			119
# define KEY_LEFT		97
# define KEY_DOWN		115
# define KEY_RIGHT		100

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	**map_clone;
	void	*img_backg;
	void	*img_wall;
	void	*img_colect;
	void	*img_exit;
	int		map_width;
	int		map_height;
	int		img_x;
	int		img_y;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			colect;
	int			player;
	int			exit;
	int			c_checker;
	int			e_checker;
	int			moves;
	int			endgame;
	void		*player_pose;
	int			player_x;
	int			player_y;
	t_map		t_map;
}			t_game;

int			main(int argc, char *argv[]);
int			handle_args(char *arg);
void		read_map(t_game *data, char *path);
int			check_map(t_game *data);
int			check_path(t_game *data);
void		flood_fill(int x, int y, t_game *data);
int			is_rectangle(char *map[]);
int			is_surrounded_wall(char *map[]);
int			check_itens(t_game *data);
int			is_valid(char *map[]);
void		gather_elements(t_game *data);
void		free_map(char **map);
void		free_images(t_game *data);
void		put_image(t_game *data, int x, int y);
void		player_position(t_game *data);
int			start_game(t_game *data);
void		update_player_img(char c, t_game *data);
void		update_door_img(t_game *data);
int			handle_key(int keysim, t_game *data);
int			handle_esc(t_game *data);
int			handle_w(t_game *data);
int			handle_a(t_game *data);
int			handle_s(t_game *data);
int			handle_d(t_game *data);
int			render_map(t_game *data);
int			exit_game(t_game *data);
int			won_game(t_game *data);
void		error_open_fd(void);
int			map_error(int n);

#endif
