/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:39:29 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:40:28 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int n)
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
