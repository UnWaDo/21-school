/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:25:27 by lalex             #+#    #+#             */
/*   Updated: 2022/01/02 20:37:40 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

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

static t_arg	read_arg_format(char **str)
{
	t_arg	arg_fmt;

	arg_fmt = (t_arg) {
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
	return (arg_fmt);
}

void	fill_width(t_arg arg_fmt, size_t value_length, char *buffer, size_t *pos)
{
	char	filler;

	if (arg_fmt.flags & O_ZERO_PADDED & (~O_LEFT_JUSTIFICATION))
		filler = '0';
	else
		filler = ' ';
	while (arg_fmt.width > value_length)
	{
		if (*pos == (size_t) BUFFER_SIZE)
			print_buffer(buffer, &pos, 0);
		buffer[(*pos++)] = filler;
		arg_fmt.width -= 1;
	}
	if (*pos == (size_t) BUFFER_SIZE)
		print_buffer(buffer, &pos, 0);
}

int	char_to_buffer(char symbol, t_arg arg_fmt, char *buffer, size_t *pos)
{
	if (arg_fmt.width <= 1)
	{
		buffer[(*pos)++] = symbol;
		return ;
	}
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
		buffer[(*pos++)] = symbol;
	fill_width(arg_fmt, 1, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
		buffer[(*pos++)] = symbol;
	return (1);
}

void	n_str_symbols_to_buffer(char *str, size_t n, char *buffer, size_t *pos)
{
	while (*str && (n--))
	{
		buffer[(*pos)++] = *str;
		str++;
		if (*pos == (size_t) BUFFER_SIZE)
			print_buffer(buffer, &pos, 0);
	}
}

size_t	ulong_length(unsigned long value, size_t base_length)
{
	size_t	value_length;

	value_length = 1;
	while (value / base_length)
	{
		value_length++;
		value /= base_length;
	}
	return(value_length);
}

char	*ulong_to_string(unsigned long value, char *base)
{
	char	*line;
	size_t	base_length;
	size_t	value_length;

	base_length = ft_strlen(base);
	if (base_length <= 1)
		return (NULL);
	value_length = ulong_length(value, base_length);
	line = malloc(value_length + 1);
	if (!line)
		return (NULL);
	line[value_length] = 0;
	while (value_length--)
	{
		line[value_length] = base[value % base_length];
		value /= base_length;
	}
	return (line);
}

int string_to_buffer(char *str, t_arg arg_fmt, char *buffer, size_t *pos);
void	alt_form_to_buffer(t_arg arg_fmt, char *buffer, size_t *pos)
{
	if (arg_fmt.type == 'p' ||
		(arg_fmt.type == 'x' && (arg_fmt.flags & O_ALT_FORM)))
		n_str_symbols_to_buffer("0x", 2, buffer, pos);
	if (arg_fmt.type == 'X' && (arg_fmt.flags & O_ALT_FORM))
		n_str_symbols_to_buffer("0X", 2, buffer, pos);
}

int num_to_buffer(char *line, t_arg arg_fmt, char *buffer, size_t *pos)
{
	size_t	num_length;
	size_t	precision;

	num_length = ft_strlen(line);
	if (arg_fmt.precision >= 0)
		precision = arg_fmt.precision;
	
}

int pointer_to_buffer(void *ptr, t_arg arg_fmt, char *buffer, size_t *pos)
{
	char	*line;
	size_t	length;

	line = ulong_to_string((unsigned long) ptr, HEX_BASE_LOWER);
	if (!line)
		return (0);
	length = ft_strlen(line);
	if (arg_fmt.flags & O_LEFT_JUSTIFICATION)
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		num_to_buffer(line, arg_fmt, buffer, pos);
	}
	fill_width(arg_fmt, length + 2, buffer, pos);
	if (!(arg_fmt.flags & O_LEFT_JUSTIFICATION))
	{
		alt_form_to_buffer(arg_fmt, buffer, pos);
		num_to_buffer(line, arg_fmt, buffer, pos);
	}
	free(line);
	return (1);
}

int string_to_buffer(char *str, t_arg arg_fmt, char *buffer, size_t *pos)
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

static int	parse_argument(char **str, va_list *args, char *buffer, size_t *pos)
{
	t_arg	arg_fmt;
	int		is_ok;

	arg_fmt = read_arg_format(str);
	if (ft_strchr(INTEGER_TYPES, arg_fmt.type))
		is_ok = int_to_buffer(va_arg(*args, int), arg_fmt, buffer, pos);
	else if (arg_fmt.type == 's')
		is_ok = string_to_buffer(va_arg(*args, char *), arg_fmt, buffer, pos);
	else if (arg_fmt.type == 'p')
		is_ok = pointer_to_buffer(va_arg(*args, void *), arg_fmt, buffer, pos);
	else if (arg_fmt.type == '%')
		is_ok = char_to_buffer('%', arg_fmt, buffer, pos);
	else
		is_ok = invalid_specifier(arg_fmt, buffer, pos);
}

int	print_buffer(char *buffer, size_t *pos, int is_last)
{
	static int	written = 0;
	int			total_written;

	written += write(1, buffer, *pos);
	*pos = 0;
	total_written = written;
	if (is_last)
		written = 0;
	return (total_written);
}

int	ft_printf(const char *str, ...)
{
	char	*buffer;
	size_t	pos;
	va_list	args;
	int		written;

	if ((size_t) BUFFER_SIZE == 0)
		return (-1);
	buffer = malloc(sizeof(*buffer) * ((size_t) BUFFER_SIZE));
	if (!buffer)
		return (-1);
	pos = 0;
	va_start(args, str);
	while (*str)
	{
		if (pos == ((size_t) BUFFER_SIZE))
			print_buffer(buffer, &pos, 0);
		if (*str != '%')
		{
			buffer[pos++] = *str;
			str++;
		}
		else if (!parse_argument(&str, &args, buffer, &pos))
		{
			free(buffer);
			return (-1);
		}
	}
	va_end(args);
	written = print_buffer(buffer, &pos, 1);
	free(buffer);
	return (written);
}
