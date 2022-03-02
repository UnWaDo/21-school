/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 18:34:24 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "ft_printf.h"
# include "so_long_mlx.h"
# include "so_long_utils.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	t_img	*canvas;
}	t_map;

typedef struct s_hero
{
	t_pos	pos;
	t_img	*icon;
	int		hp;
	int		xp;
	int		status;
	size_t	steps_done;
}	t_hero;

typedef struct s_so_long
{
	t_hero	*hero;
	t_map	*map;
	t_mlx	*mlx;
}	t_so_long;

t_map	*read_map(const char *file);
void	delete_map(t_map *map);
void	draw_map(t_mlx *mlx, t_map *map);
t_hero	*init_hero(t_map *map);
void	move_hero(t_hero *hero, t_map *map, t_pos pos);
void	move_hero_rel(t_hero *hero, t_map *map, t_pos pos);
int		damage_hero(t_hero *hero, int damage);
void	print_hero_status(t_hero *hero);
void	game_over(t_hero *hero);
int		close_ok(t_so_long *so_long);
int		close_error(t_so_long *so_long);

# define EMPTY_CODE	'0'
# define WALL_CODE	'1'
# define HERO_CODE	'P'
# define COLL_CODE	'C'
# define EXIT_CODE	'E'
# define ENEMY_CODE	'R'

# define STATUS_HEALTHY	0b1
# define STATUS_HURT	0b10
# define STATUS_DAMAGED	0b100
# define STATUS_DEAD	0b1000
# define STATUS_WON		0b10000

#endif