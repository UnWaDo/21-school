/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_bufferization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:01:45 by lalex             #+#    #+#             */
/*   Updated: 2022/01/05 16:27:07 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

// is_positive: > 0 for positive, < 0 for negative, 0 for unsigned
static int	check_if_positive(int value, t_arg arg_fmt)
{
	int	is_positive;

	is_positive = 0;
	if (arg_fmt.type == 'd' || arg_fmt.type == 'i')
	{
		if (value >= 0)
			is_positive = 1;
		else
			is_positive = -1;
	}
	return (is_positive);
}

size_t	total_num_length(int value, char *num_line, t_arg arg_fmt)
{
	size_t	num_length;
	int		is_positive;

	is_positive = check_if_positive(value, arg_fmt);
	num_length = ft_strlen(num_line);
	if (num_line[0] == '-')
		num_length--;
	if (arg_fmt.precision >= 0 && (size_t) arg_fmt.precision > num_length)
		num_length += arg_fmt.precision - num_length;
	if (arg_fmt.type == 'p' || ((arg_fmt.flags & O_ALT_FORM)
			&& (((arg_fmt.type == 'x') || (arg_fmt.type == 'X'))
				&& (value != 0))))
		num_length += 2;
	else if (is_positive < 0)
		num_length++;
	else if ((is_positive > 0)
		&& ((arg_fmt.flags & O_MANDATORY_SIGN)
			|| (arg_fmt.flags & O_SIGN_BLANK)))
		num_length++;
	return (num_length);
}

void	num_prefix_to_buffer(int value, t_arg arg_fmt,
	char *buffer, size_t *pos)
{
	int	is_positive;

	is_positive = check_if_positive(value, arg_fmt);
	if (value)
		alt_form_to_buffer(arg_fmt, buffer, pos);
	if (is_positive < 0)
		single_char_to_buffer('-', buffer, pos);
	else if (is_positive > 0)
	{
		if (arg_fmt.flags & O_MANDATORY_SIGN)
			single_char_to_buffer('+', buffer, pos);
		else if (arg_fmt.flags & O_SIGN_BLANK)
			single_char_to_buffer(' ', buffer, pos);
	}
}

void	num_to_buffer(char *line, t_arg arg_fmt, char *buffer, size_t *pos)
{
	size_t	num_length;
	size_t	leading_zeros;

	num_length = ft_strlen(line);
	if (line[0] == '-')
		num_length--;
	leading_zeros = 0;
	if (arg_fmt.precision >= 0 && (size_t) arg_fmt.precision > num_length)
		leading_zeros = arg_fmt.precision - num_length;
	while (leading_zeros--)
		single_char_to_buffer('0', buffer, pos);
	if (line[0] == '-')
		n_str_symbols_to_buffer(line + 1, num_length, buffer, pos);
	else
		n_str_symbols_to_buffer(line, num_length, buffer, pos);
}
