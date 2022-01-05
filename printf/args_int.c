/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:10:37 by lalex             #+#    #+#             */
/*   Updated: 2022/01/05 15:34:01 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static char	*int_to_string(int value, t_arg arg_fmt)
{
	char	*base;

	if (arg_fmt.type == 'd' || arg_fmt.type == 'i')
		return (ft_itoa(value));
	if (arg_fmt.type == 'x')
		base = HEX_BASE_LOWER;
	else if (arg_fmt.type == 'X')
		base = HEX_BASE_UPPER;
	else
		base = DECIMAL_BASE;
	return (uint_to_string(value, base));
}

int	int_to_buffer(int value, t_arg arg_fmt, char *buffer, size_t *pos)
{
	char	*num_line;
	size_t	total_length;

	num_line = int_to_string(value, arg_fmt);
	if (!num_line)
		return (0);
	total_length = total_num_length(value, num_line, arg_fmt);
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
	{
		num_prefix_to_buffer(value, arg_fmt, buffer, pos);
		num_to_buffer(num_line, arg_fmt, buffer, pos);
	}
	if (!(arg_fmt.flags & O_ZERO_PADDED))
		fill_width(arg_fmt, total_length, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
	{
		num_prefix_to_buffer(value, arg_fmt, buffer, pos);
		if (arg_fmt.flags & O_ZERO_PADDED)
			fill_width(arg_fmt, total_length, buffer, pos);
		num_to_buffer(num_line, arg_fmt, buffer, pos);
	}
	free(num_line);
	return (1);
}
