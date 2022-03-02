#include "so_long.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

static t_map	*alloc_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(map->height * sizeof(*(map->map)));
	if (map->map == NULL)
	{
		free(map);
		return (NULL);
	}
	while (i < map->height)
	{
		map->map[i] = malloc(map->width * sizeof(**(map->map)));
		if (map->map[i] == NULL)
		{
			while (i--)
				free(map->map[i]);
			free(map->map);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static t_map	*init_map(int width, int height)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->width = width;
	map->height = height;
	if (alloc_map(map) == NULL)
		return (NULL);
	map->canvas = NULL;
	return (map);
}

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

static t_pos	get_width_and_height(int fd)
{
	char	*line;
	char	**values;
	t_pos	wah;

	wah = (t_pos){.x = -1, .y = -1};
	line = get_next_line(fd);
	if (line == NULL)
		return (wah);
	values = ft_split(line, ' ');
	free(line);
	if (values == NULL)
		return (wah);
	if (values[0] == NULL || values[1] == NULL || values[2] != NULL)
	{
		clean_strings(values);
		return (wah);
	}
	wah.x = ft_atoi(values[0]);
	wah.y = ft_atoi(values[1]);
	if (wah.x <= 0 || wah.y <= 0)
		wah.x = -1;
	clean_strings(values);
	return (wah);
}

static int	parse_line(t_map *map, int y, char *line)
{
	int		x;
	char	**values;

	values = ft_split(line, ' ');
	if (values == NULL)
		return (-1);
	x = 0;
	while (x < map->width)
	{
		if (values[x] == NULL)
		{
			clean_strings(values);
			return (-1);
		}
		map->map[y][x] = values[x][0];
		x++;
	}
	clean_strings(values);
	return (0);
}

static int	read_lines(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (-1);
		if (parse_line(map, i, line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		i++;
	}
	return (0);
}

#define ALLOWED_CHARS	"01CEPR"

static int	check_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x == 0 || y == 0 || x == map->width - 1
					|| y == map->height - 1) && map->map[y][x] != WALL_CODE)
				return (0b1);
			if (ft_strchr(ALLOWED_CHARS, map->map[y][x]) == NULL)
				return (0b10);
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*read_map(const char *file)
{
	int		fd;
	t_map	*map;
	t_pos	wah;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	wah = get_width_and_height(fd);
	if (wah.x <= 0)
	{
		close(fd);
		return (NULL);
	}
	map = init_map(wah.x, wah.y);
	if (read_lines(map, fd) == -1 || check_map(map) != 0)
	{
		delete_map(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

#define CELL_WIDTH	50

void	draw_map(t_mlx *mlx, t_map *map)
{
	t_pos	corner;
	t_pos	w_h;
	int		color;
	char	code;

	fill_color(map->canvas, 0);
	w_h = (t_pos){.x = CELL_WIDTH, .y = CELL_WIDTH};
	corner.y = 0;
	while (corner.y < map->height * CELL_WIDTH)
	{
		corner.x = 0;
		while (corner.x < map->width * CELL_WIDTH)
		{
			code = map->map[corner.y / CELL_WIDTH][corner.x / CELL_WIDTH];
			if (code == WALL_CODE)
				color = 0;
			else if (code == ENEMY_CODE)
				color = to_trgb(0, 255, 0, 0);
			else if (code == HERO_CODE)
				color = to_trgb(0, 0, 128, 128);
			else if (code == COLL_CODE)
				color = to_trgb(0, 100, 100, 255);
			else if (code == EXIT_CODE)
				color = to_trgb(0, 65, 130, 130);
			else
				color = to_trgb(0, 255, 255, 255);
			put_rect(map->canvas, corner, w_h, color);
			corner.x += CELL_WIDTH;
		}
		corner.y += CELL_WIDTH;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->canvas->img, 0, 0);
}
