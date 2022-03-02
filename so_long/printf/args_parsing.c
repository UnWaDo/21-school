/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:07:02 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 21:06:19 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static int	read_arg_flags(char **str)
{
	int	flags;

	flags = 0;
	while (**str)
	{
		if (**str == '#')
			flags = flags | O_ALT_FORM;
		else if (**str == '0')
			flags = flags | O_ZERO_PADDED;
		else if (**str == '-')
			flags = flags | O_LEFT_JUSTIFICATION;
		else if (**str == ' ')
			flags = flags | O_SIGN_BLANK;
		else if (**str == '+')
			flags = flags | O_MANDATORY_SIGN;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

static int	read_arg_precision(char **str)
{
	int	precision;

	precision = ft_atoi(*str);
	if (precision < 0)
			precision = 0;
	if (**str == '+' || **str == '-')
		(*str)++;
	while (**str && ft_isdigit(**str))
		(*str)++;
	return (precision);
}

static t_arg	fix_arg_format(t_arg arg_fmt)
{
	if (arg_fmt.precision >= 0 || (arg_fmt.flags & O_LEFT_JUSTIFICATION)
		|| (!ft_strchr(INTEGER_TYPES, arg_fmt.type)))
		arg_fmt.flags = arg_fmt.flags & (~O_ZERO_PADDED);
	if (arg_fmt.flags & O_MANDATORY_SIGN)
		arg_fmt.flags = arg_fmt.flags & (~O_SIGN_BLANK);
	return (arg_fmt);
}

static t_arg	read_arg_format(char **str)
{
	t_arg	arg_fmt;

	arg_fmt = (t_arg){
		.flags = read_arg_flags(str),
		.width = 0,
		.precision = -1
	};
	if (ft_isdigit(**str))
		arg_fmt.width = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
	{
		(*str)++;
		arg_fmt.precision = read_arg_precision(str);
	}
	arg_fmt.type = **str;
	(*str)++;
	arg_fmt = fix_arg_format(arg_fmt);
	return (arg_fmt);
}

int	parse_argument(char **str, va_list *args, char *buffer, size_t *pos)
{
	t_arg	arg_fmt;
	int		is_ok;

	if (**str)
		(*str)++;
	arg_fmt = read_arg_format(str);
	if (ft_strchr(INTEGER_TYPES, arg_fmt.type))
		is_ok = int_to_buffer(va_arg(*args, int), arg_fmt, buffer, pos);
	else if (arg_fmt.type == 'c')
		is_ok = char_to_buffer(va_arg(*args, int), arg_fmt, buffer, pos);
	else if (arg_fmt.type == 's')
		is_ok = string_to_buffer(va_arg(*args, char *), arg_fmt, buffer, pos);
	else if (arg_fmt.type == 'p')
		is_ok = pointer_to_buffer(va_arg(*args, void *), arg_fmt, buffer, pos);
	else if (arg_fmt.type == '%')
		is_ok = char_to_buffer('%', arg_fmt, buffer, pos);
	else
		is_ok = char_to_buffer(arg_fmt.type, arg_fmt, buffer, pos);
	return (is_ok);
}
