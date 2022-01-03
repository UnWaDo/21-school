/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:18:23 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 21:06:33 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int	char_to_buffer(char symbol, t_arg arg_fmt, char *buffer, size_t *pos)
{
	if (arg_fmt.width <= 1)
	{
		buffer[(*pos)++] = symbol;
		return (1);
	}
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
		buffer[(*pos)++] = symbol;
	fill_width(arg_fmt, 1, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
		buffer[(*pos)++] = symbol;
	return (1);
}

int	pointer_to_buffer(void *ptr, t_arg arg_fmt, char *buffer, size_t *pos)
{
	char	*line;
	size_t	length;

	line = ulong_to_string((unsigned long) ptr, HEX_BASE_LOWER);
	if (!line)
		return (0);
	length = total_num_length((int) ptr, line, arg_fmt);
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		num_to_buffer(line, arg_fmt, buffer, pos);
	}
	fill_width(arg_fmt, length, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		num_to_buffer(line, arg_fmt, buffer, pos);
	}
	free(line);
	return (1);
}

int	string_to_buffer(char *str, t_arg arg_fmt, char *buffer, size_t *pos)
{
	size_t	strlen;

	if (str == NULL)
		str = NULL_POINTER_REPR;
	if (arg_fmt.precision >= 0)
		strlen = arg_fmt.precision;
	else
		strlen = ft_strlen(str);
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
		n_str_symbols_to_buffer(str, strlen, buffer, pos);
	fill_width(arg_fmt, strlen, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
		n_str_symbols_to_buffer(str, strlen, buffer, pos);
	return (1);
}
