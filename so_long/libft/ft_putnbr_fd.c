/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:29:22 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:30:59 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_length(int n)
{
	size_t	str_len;

	if (!n)
		return (1);
	str_len = 0;
	if (n < 0)
		str_len = 1;
	else
		n = -n;
	while (n)
	{
		str_len++;
		n /= 10;
	}
	return (str_len);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	char	buff[12];
	size_t	str_len;
	size_t	i;

	str_len = number_length(n);
	ft_bzero(buff, 12);
	if (n < 0)
		buff[0] = '-';
	else if (n > 0)
		n = -n;
	else
		buff[0] = '0';
	i = 0;
	while (n)
	{
		buff[str_len - i - 1] = '0' - (n % 10);
		n /= 10;
		i++;
	}
	return (ft_putstr_fd(buff, fd));
}
