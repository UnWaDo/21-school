#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	int		**map;
	int		width;
	int		height;
	t_point	zero;
}	t_map;

typedef struct s_square {
	t_point	coord;
	int		side;
}	t_square;

void	map_output(t_map map)
{
	int	i;
	int	j;

	i = map.zero.x;
	while (i < map.zero.x + map.height)
	{
		j = map.zero.y;
		while (j < map.zero.y + map.width)
		{
			ft_putchar('0' + map.map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	square_compare(t_square sq1, t_square sq2)
{
	if (sq1.side != sq2.side)
		return (sq1.side - sq2.side);
	if (sq1.coord.x != sq2.coord.x)
		return (sq2.coord.x - sq1.coord.x);
	if (sq1.coord.y != sq2.coord.y)
		return (sq2.coord.y - sq1.coord.y);
	return (0);
}

t_point	find_obstacle(t_map map)
{
	int		x;
	int		y;
	t_point	res;

	x = map.zero.x;
	while (x < map.zero.x + map.height)
	{
		y = map.zero.y;
		while (y < map.zero.y + map.width)
		{
			if (map.map[x][y] == 1)
			{
				res.x = x;
				res.y = y;
				return (res);
			}
			y++;
		}
		x++;
	}
	res.x = -1;
	return (res);
}

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

void	output(t_point obst, t_square sq)
{
	ft_putstr("Obstacle: ");
	ft_putchar(obst.x + '0');
	ft_putchar(' ');
	ft_putchar(obst.y + '0');
	ft_putchar('\n');
	ft_putstr("Square: ");
	ft_putchar(sq.coord.x + '0');
	ft_putchar(' ');
	ft_putchar(sq.coord.y + '0');
	ft_putstr(", side: ");
	ft_putchar(sq.side + '0');
	ft_putchar('\n');
}

t_square	solve(t_map map, t_square sq)
{
	t_point		obst;
	t_square	tmp;
	t_map		tmp_map;

	if (map.width < 1 || map.height < 1)
		return (sq);
	if (ft_min(map.width, map.height) < sq.side)
		return (sq);
	obst = find_obstacle(map);
	if (obst.x == -1)
	{
		tmp.coord = map.zero;
		tmp.side = ft_min(map.width, map.height);
		return (tmp);
	}
	tmp_map = map;
	tmp_map.height = obst.x - map.zero.x;
	tmp = solve(tmp_map, sq);
	if (square_compare(tmp, sq) > 0)
		sq = tmp;
	tmp_map.height = map.height;
	tmp_map.width = obst.y - map.zero.y;
	tmp = solve(tmp_map, sq);
	if (square_compare(tmp, sq) > 0)
		sq = tmp;
	tmp_map.zero.y = obst.y + 1;
	tmp_map.width = map.width - obst.y - 1;
	tmp = solve(tmp_map, sq);
	if (square_compare(tmp, sq) > 0)
		sq = tmp;
	tmp_map.zero.x = obst.x + 1;
	tmp_map.zero.y = map.zero.y;
	tmp_map.height = map.height - obst.x - 1;
	tmp_map.width = map.width;
	tmp = solve(tmp_map, sq);
	if (square_compare(tmp, sq) > 0)
		sq = tmp;
	return (sq);
}

void	map_draw_sq(t_map map, t_square sq)
{
	int	x;
	int	y;

	x = sq.coord.x;
	while (x < sq.coord.x + sq.side)
	{
		y = sq.coord.y;
		while (y < sq.coord.y + sq.side)
		{
			map.map[x][y] = 2;
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_map	map;
	int i = 0;

	map.width = 6;
	map.height = 6;
	map.map = malloc(sizeof (int *) * map.height);
	while (i < map.height)
	{
		map.map[i] = malloc(sizeof (int) * map.width);
		i++;
	}
	map.map[0][0] = 0;
	map.map[0][1] = 0;
	map.map[0][2] = 1;
	map.map[0][3] = 0;
	map.map[0][4] = 0;
	map.map[0][5] = 0;
	map.map[1][1] = 1;
	map.map[1][2] = 0;
	map.map[1][3] = 0;
	map.map[1][4] = 0;
	map.map[1][5] = 0;
	map.map[2][0] = 0;
	map.map[2][1] = 0;
	map.map[2][2] = 1;
	map.map[2][3] = 0;
	map.map[2][4] = 0;
	map.map[2][5] = 0;
	map.map[3][0] = 0;
	map.map[3][1] = 0;
	map.map[3][2] = 0;
	map.map[3][3] = 1;
	map.map[3][4] = 0;
	map.map[3][5] = 0;
	map.map[4][0] = 0;
	map.map[4][1] = 1;
	map.map[4][2] = 0;
	map.map[4][3] = 0;
	map.map[4][4] = 0;
	map.map[4][5] = 1;
	map.map[5][0] = 0;
	map.map[5][1] = 0;
	map.map[5][2] = 0;
	map.map[5][3] = 1;
	map.map[5][4] = 0;
	map.map[5][5] = 0;

	map.zero = (t_point){.x = 0, .y = 0};
	map_output(map);
	ft_putstr("\n--------\n");
	t_square sq = (t_square){.side = 0, .coord = map.zero};
	sq = solve(map, sq);	
	map_draw_sq(map, sq);
	map_output(map);
	i = 0;
	while (i < map.height)
	{
		free(map.map[i]);
		i++;
	}
	return (0);
}
