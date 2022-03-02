/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:43:34 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:43:42 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	pos = 0;
	dstsize--;
	while (pos < len && pos < dstsize)
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
	return (len);
}
