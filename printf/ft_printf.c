/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:25:27 by lalex             #+#    #+#             */
/*   Updated: 2022/01/05 15:24:16 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

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

static int	init_buffer(char **buffer, size_t *pos, size_t buffer_size)
{
	if (buffer_size == 0)
		return (-1);
	*buffer = malloc(sizeof(*buffer) * buffer_size);
	if (!(*buffer))
		return (-1);
	*pos = 0;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	char	*buffer;
	size_t	pos;
	va_list	args;
	int		written;

	if (init_buffer(&buffer, &pos, BUFFER_SIZE) == -1)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			single_char_to_buffer(*(str++), buffer, &pos);
		else if (!parse_argument((char **) &str, &args, buffer, &pos))
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
