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

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	KEYCODE_ENTER = 65293,
	KEYCODE_ESCAPE = 65307,
	KEYCODE_W = 119,
	KEYCODE_A = 97,
	KEYCODE_S = 115,
	KEYCODE_D = 100,
	KEYCODE_SPACE = 32
};

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

#endif