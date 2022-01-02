/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:25:27 by lalex             #+#    #+#             */
/*   Updated: 2021/10/27 23:34:50 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

static void	add_line(char *line, t_list **buffer)
{
	t_list		*new;

	new = ft_lstnew(line);
	if (!new)
	{
		free(line);
		ft_lstclear(buffer, &free);
	}
	ft_lstadd_back(buffer, new);
}

static size_t	parse_string(const char *str, t_list **buffer)
{
	size_t	len;
	char	*line;

	len = 0;
	while (str[len] && str[len] != '%')
		len++;
	line = ft_substr(str, 0, len);
	if (!line)
		ft_lstclear(buffer, &free);
	else
		add_line(line, buffer);
	return (len);
}

static t_arg	read_arg_format(const char *str, size_t *pos)
{
	t_arg	arg_fmt;

	arg_fmt = (t_arg) {.flags = 0, .width = 0, .precision = -1, .type = 0};
	while (str[*pos])
	{
		if (str[*pos] == '#')
			arg_fmt.flags = arg_fmt.flags | O_ALT_FORM;
		else if (str[*pos] == '0')
			arg_fmt.flags = arg_fmt.flags | O_ZERO_PADDED;
		else if (str[*pos] == '-')
			arg_fmt.flags = arg_fmt.flags | O_LEFT_JUSTIFICATION;
		else if (str[*pos] == ' ')
			arg_fmt.flags = arg_fmt.flags | O_SIGN_BLANK;
		else if (str[*pos] == '+')
			arg_fmt.flags = arg_fmt.flags | O_MANDATORY_SIGN;
		else
			break ;
		(*pos)++;
	}
	if (ft_isdigit(str[*pos]))
		arg_fmt.width = ft_atoi(str + *pos);
	while (str[*pos] && ft_isdigit(str[*pos]))
		(*pos)++;
	if (str[*pos] == '.')
	{
		arg_fmt.precision = ft_atoi(str + *pos + 1);
		if (arg_fmt.precision < 0)
			arg_fmt.precision = 0;
		(*pos)++;
		if (str[*pos] == '+' || str[*pos] == '-')
			(*pos)++;
		while (ft_isdigit(str[*pos]))
			(*pos)++;
	}
	arg_fmt.type = str[*pos];
	(*pos)++;
	return (arg_fmt);
}
static size_t	parse_argument(const char *str, va_list *args, t_list **buffer)
{
	t_arg	arg_fmt;
	size_t	pos;
	char	*line;

	pos = 1;
	arg_fmt = read_arg_format(str, &pos);
	if (ft_strchr(INTEGER_TYPES, arg_fmt.type))
		line = stringify_integer(va_arg(*args, int), arg_fmt);
	else if (ft_strchr(POINTER_TYPES, arg_fmt.type))
		line = stringify_pointer(va_arg(*args, void *), arg_fmt);
	else if (arg_fmt.type == '%')
		line = stringify_percent();
	else
		line = NULL;
	if (!line)
		ft_lstclear(buffer, &free);
	else
		add_line(line, buffer);
	return (pos);	
}

int	ft_printf(const char *str, ...)
{
	t_list	*output;
	va_list	args;

	output = NULL;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			str += parse_argument(str, &args, &output);
		else
			str += parse_string(str, &output);
		if (!output)
			break ;
	}
	va_end(args);
	if (!output)
		return (-1);
	return (print_all(&output));
}
