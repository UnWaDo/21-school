#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "so_long.h"

#define WIDTH	640
#define HEIGHT	480
#define TITLE	"So long..."

static void	init_images(t_so_long *sl)
{
	sl->map->canvas = create_new_image(sl->mlx, (t_pos){.x = WIDTH, .y = HEIGHT});
}

static t_so_long	*init_so_long(char *map)
{
	t_so_long	*sl;

	sl = malloc(sizeof(*sl));
	if (!sl)
		return (NULL);
	sl->map = read_map(map);
	if (sl->map == NULL)
	{
		free(sl);
		return (NULL);
	}
	sl->hero = init_hero(sl->map);
	if (sl->hero == NULL)
	{
		delete_map(sl->map);
		free(sl);
		return (NULL);
	}
	sl->mlx = start_mlx_win((t_pos){.x = WIDTH, .y = HEIGHT}, TITLE);
	if (sl->mlx == NULL)
	{
		delete_map(sl->map);
		free(sl->hero);
		free(sl);
		return (NULL);
	}
	init_images(sl);
	if (sl->map->canvas == NULL) // add hero check
	{
		delete_map(sl->map);
		free(sl->hero);
		free(sl);
		return (NULL);
	}
	return (sl);
}

static int	key_released(int keycode, t_so_long *sl)
{
	if (keycode == KEYCODE_W)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 0, .y = -1});
	else if (keycode == KEYCODE_S)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 0, .y = 1});
	else if (keycode == KEYCODE_A)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = -1, .y = 0});
	else if (keycode == KEYCODE_D)
		move_hero_rel(sl->hero, sl->map, (t_pos){.x = 1, .y = 0});
	else if (keycode == KEYCODE_ESCAPE)
		close_ok(sl);
	draw_map(sl->mlx, sl->map);
	print_hero_status(sl->hero);
	return (0);
}

#define TICK_LENGTH	1500

int	main(int argc, char **argv)
{
	t_so_long	*sl;

	if (argc != 2)
	{
		ft_printf("Usage: %s path_to_map.ber\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sl = init_so_long(argv[1]);
	if (sl == NULL)
	{
		perror("Error during initialization");
		exit(EXIT_FAILURE);
	}
	draw_map(sl->mlx, sl->map);
	print_hero_status(sl->hero);
	mlx_key_hook(sl->mlx->win, &key_released, sl);
	mlx_hook(sl->mlx->win, ON_DESTROY, 0, &close_ok, sl);
	mlx_loop(sl->mlx->mlx);
	game_over(sl->hero);
	return (0);
}
