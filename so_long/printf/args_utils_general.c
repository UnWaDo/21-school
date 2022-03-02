/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils_general.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:38:16 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 20:14:22 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	single_char_to_buffer(char c, char *buffer, size_t *pos)
{
	if (*pos == (size_t) BUFFER_SIZE)
		print_buffer(buffer, pos, 0);
	buffer[(*pos)++] = c;
}

void	fill_width(t_arg arg_fmt, size_t val_length, char *buffer, size_t *pos)
{
	char	filler;

	if ((arg_fmt.flags & O_ZERO_PADDED & (~O_LEFT_JUSTIFICATION)))
		filler = '0';
	else
		filler = ' ';
	while ((arg_fmt.width--) > val_length)
		single_char_to_buffer(filler, buffer, pos);
}

void	n_str_symbols_to_buffer(char *str, size_t n, char *buffer, size_t *pos)
{
	while (*str && (n--))
		single_char_to_buffer(*(str++), buffer, pos);
}

void	alt_form_to_buffer(t_arg arg_fmt, char *buffer, size_t *pos)
{
	if (arg_fmt.type == 'p'
		|| (arg_fmt.type == 'x' && (arg_fmt.flags & O_ALT_FORM)))
		n_str_symbols_to_buffer("0x", 2, buffer, pos);
	if (arg_fmt.type == 'X' && (arg_fmt.flags & O_ALT_FORM))
		n_str_symbols_to_buffer("0X", 2, buffer, pos);
}
