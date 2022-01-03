/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:10:37 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 21:17:21 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static char	*define_base(t_arg arg_fmt)
{
	if (arg_fmt.type == 'x')
		return (HEX_BASE_LOWER);
	else if (arg_fmt.type == 'X')
		return (HEX_BASE_UPPER);
	else
		return (DECIMAL_BASE);
}

static long	convert_value(int value, t_arg arg_fmt)
{
	if (value < 0)
		return (-((long) value));
	else
		return (value);
}

// TODO:	"%u" with negative values
// 			width is precision
//			0 flag must be ignored with precision given
int	int_to_buffer(int value, t_arg arg_fmt, char *buffer, size_t *pos)
{
	char	*base;
	char	*num_line;

	base = define_base(arg_fmt);
	num_line = ulong_to_string(convert_value(value, arg_fmt), base);
	if (!num_line)
		return (0);
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		sign_to_buffer(value, arg_fmt, buffer, pos);
		num_to_buffer(num_line, arg_fmt, buffer, pos);
	}
	fill_width(arg_fmt,
		total_num_length(value, num_line, arg_fmt), buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		sign_to_buffer(value, arg_fmt, buffer, pos);
		num_to_buffer(num_line, arg_fmt, buffer, pos);
	}
	free(num_line);
	return (1);
}
