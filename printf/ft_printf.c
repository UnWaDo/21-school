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

int	ft_printf(const char *str, ...)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{

		}
		else
			ft_putchar_fd(str[count], 0);
		count++;
	}
	return (count);
}
