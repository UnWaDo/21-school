/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:38 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:34:40 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	destination = dst;
	source = src;
	if (destination <= source || destination > source + len)
		return (ft_memcpy(dst, src, len));
	i = len;
	while (i > 0)
	{
		destination[i - 1] = source[i - 1];
		i--;
	}
	return (dst);
}
