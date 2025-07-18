#include "so_long.h"

int	is_rectangle(char *map[])
{
	int	i;

	i = 1;
	if (!map[0])
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_wall(char *map[])
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_itens(t_game *data)
{
	int	i;
	int	j;

	data->colect = 0;
	data->exit = 0;
	data->player = 0;
	i = 0;
	while (data->t_map.map[i])
	{
		j = 0;
		while (data->t_map.map[i][j] != '\0')
		{
			if (data->t_map.map[i][j] == 'P')
				data->player++;
			if (data->t_map.map[i][j] == 'E')
				data->exit++;
			if (data->t_map.map[i][j] == 'C')
				data->colect++;
			j++;
		}
		i++;
	}
	if (data->player != 1 || data->exit != 1 || data->colect == 0)
		return (0);
	return (1);
}

int	is_valid(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *data)
{
	int	i;

	if (!is_rectangle(data->t_map.map) || !is_surrounded_wall(data->t_map.map))
		return (map_error(1));
	else if (!check_itens(data) || !is_valid(data->t_map.map))
		return (map_error(2));
	else if (!check_path(data))
		return (map_error(3));
	else
	{
		i = 0;
		while (data->t_map.map[i])
			i++;
		data->t_map.map_width = ft_strlen(data->t_map.map[0]);
		data->t_map.map_height = i;
		return (1);
	}
	return (0);
}