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

#ifndef SO_LONG_MLX_H
# define SO_LONG_MLX_H

# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "so_long_utils.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_list	*images;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_pos	w_h;
}	t_img;

int		to_trgb(unsigned char t,
			unsigned char r, unsigned char g, unsigned char b);
void	put_pixel(t_img *img, t_pos pos, int c);
void	put_rect(t_img *img, t_pos corner, t_pos w_h, int c);
void	fill_color(t_img *img, int c);
t_mlx	*start_mlx_win(t_pos w_h, char *title);
t_img	*create_new_image(t_mlx *mlx, t_pos w_h);

#endif