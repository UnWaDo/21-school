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
#include "libft/libft.h"
#include "ft_printf_utils.h"

static void add_line(char *line, t_list **buffer)
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

int	ft_printf(const char *str, ...)
{
	t_list	*output;
	va_list	args;
	char	*line;

	output = NULL;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			line = NULL;
			if (ft_strchr(INTEGER_TYPES, str[1]))
				line = stringify_integer(va_arg(args, int), str[1]);
			else if (ft_strchr(POINTER_TYPES, str[1]))
				line = stringify_pointer(va_arg(args, void *), str[1]);
			else if (str[1] == '%')
				line = stringify_percent();
			if (!line)
				ft_lstclear(&output, &free);
			else
				add_line(line, &output);
			str += 2;
		}
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
