#include "so_long.h"

static char	*read_lines(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	if (!map)
		return(NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	return (map);
}

void	read_map(t_game *data, char *path)
{
	int		fd;
	char	*holder;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_open_fd();
	holder = read_lines(fd);
	data->t_map.map = ft_split(holder, '\n');
	data->t_map.map_clone = ft_split(holder, '\n');
	free(holder);
	close(fd);
}

static void	put_tile(t_game *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, img, x * PIXS, y * PIXS);
}

void	put_image(t_game *data, int x, int y)
{
	char	c = data->t_map.map[y][x];

	if (c == '0')
		put_tile(data, data->t_map.img_backg, x, y);
	else if (c == 'P')
		put_tile(data, data->player_pose, x, y);
	else if (c == 'C')
		put_tile(data, data->t_map.img_colect, x, y);
	else if (c == 'E')
		put_tile(data, data->t_map.img_exit, x, y);
	else if (c == '1')
		put_tile(data, data->t_map.img_wall, x, y);
}

int	render_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->t_map.map[y])
	{
		x = 0;
		while (data->t_map.map[y][x])
		{
			put_image(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}