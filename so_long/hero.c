#include "so_long.h"

static t_pos	get_hero_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == HERO_CODE)
				return ((t_pos){.x = x, .y = y});
			x++;
		}
		y++;
	}
	return ((t_pos){.x = -1, .y = -1});
}

t_hero	*init_hero(t_map *map)
{
	t_hero	*hero;

	hero = malloc(sizeof(*hero));
	if (!hero)
		return (NULL);
	hero->pos = get_hero_pos(map);
	if (hero->pos.x == -1)
	{
		free(hero);
		return (NULL);
	}
	hero->hp = 100;
	hero->xp = 0;
	hero->status = STATUS_HEALTHY;
	hero->icon = NULL;
	hero->steps_done = 0;
	return (hero);
}

void	move_hero(t_hero *hero, t_map *map, t_pos pos)
{
	if (pos.x < 0 || pos.x > map->width)
		pos.x = ((pos.x % map->width) + map->width) % map->width;
	if (pos.y < 0 || pos.y > map->height)
		pos.y = ((pos.y % map->height) + map->height) % map->height;
	if (map->map[pos.y][pos.x] == WALL_CODE)
	{
		damage_hero(hero, 10);
		return ;
	}
	else if (map->map[pos.y][pos.x] == ENEMY_CODE)
	{
		damage_hero(hero, 20);
		hero->xp += 50;
	}
	else if (map->map[pos.y][pos.x] == COLL_CODE)
		hero->xp += 20;
	else if (map->map[pos.y][pos.x] == EXIT_CODE)
		hero->status |= STATUS_WON;
	map->map[hero->pos.y][hero->pos.x] = EMPTY_CODE;
	map->map[pos.y][pos.x] = HERO_CODE;
	hero->pos = pos;
	hero->steps_done += 1;
}

void	move_hero_rel(t_hero *hero, t_map *map, t_pos pos)
{
	t_pos	abs_pos;

	abs_pos = hero->pos;
	abs_pos.x += pos.x;
	abs_pos.y += pos.y;
	move_hero(hero, map, abs_pos);
}

void	print_hero_status(t_hero *hero)
{
	if (hero->status & STATUS_DEAD)
	{
		ft_printf("Hero is dead. Nothing left from it\n");
		return ;
	}
	else if (hero->status & STATUS_DAMAGED)
		ft_printf("Your hero is very tired\n");
	else if (hero->status & STATUS_HURT)
		ft_printf("Your hero is feeling drozy\n");
	else if (hero->status & STATUS_HEALTHY)
		ft_printf("Your hero is full of energy\n");
	ft_printf("HP: %d\nXP: %d\n", hero->hp, hero->xp);
	ft_printf("You can find your location with %c symbol\n", HERO_CODE);
	ft_printf("You made %u steps\n", hero->steps_done);
}

int	damage_hero(t_hero *hero, int damage)
{
	if (damage <= 0)
		return (hero->hp);
	hero->hp -= damage;
	if (hero->hp < 0)
		hero->hp = 0;
	if (hero->hp == 0)
		hero->status = STATUS_DEAD;
	else if (hero->hp < 40)
		hero->status = STATUS_DAMAGED;
	else if (hero->hp < 80)
		hero->status = STATUS_HURT;
	return (hero->hp);
}
