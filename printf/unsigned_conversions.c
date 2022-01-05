/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:23:27 by lalex             #+#    #+#             */
/*   Updated: 2022/01/05 15:23:47 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

size_t	ulong_length(unsigned long value, size_t base_length)
{
	size_t	value_length;

	value_length = 1;
	while (value / base_length)
	{
		value_length++;
		value /= base_length;
	}
	return (value_length);
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

size_t	uint_length(unsigned int value, size_t base_length)
{
	size_t	value_length;

	value_length = 1;
	while (value / base_length)
	{
		value_length++;
		value /= base_length;
	}
	return (value_length);
}

char	*uint_to_string(unsigned int value, char *base)
{
	char	*line;
	size_t	base_length;
	size_t	value_length;

	base_length = ft_strlen(base);
	if (base_length <= 1)
		return (NULL);
	value_length = uint_length(value, base_length);
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
