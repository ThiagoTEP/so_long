#include "so_long.h"
#include "get_next_line.h"


void free_map(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int count_lines(char *filename)
{
	int fd = open(filename, O_RDONLY);
	int count = 0;
	char *line;

	if (fd < 0)
		exit_error("Erro ao abrir o mapa");
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char **read_map(char *filename)
{
	int fd = open(filename, O_RDONLY);
	int i = 0;
	int lines = count_lines(filename);
	char **map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		exit_error("Erro de alocação de mapa");

	fd = open(filename, O_RDONLY);
	while (i < lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
