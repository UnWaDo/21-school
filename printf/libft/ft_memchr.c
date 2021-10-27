/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:01 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:32:05 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			pos;

	bytes = (unsigned char *) s;
	pos = 0;
	while (pos < n)
	{
		if (bytes[pos] == (unsigned char) c)
			return (bytes + pos);
		pos++;
	}
	return (NULL);
}
