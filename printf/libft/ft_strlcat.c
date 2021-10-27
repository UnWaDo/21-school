/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:43:53 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:43:55 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if ((!dstsize) || (dstsize <= dst_len))
		return (dstsize + src_len);
	dst += dst_len;
	dstsize -= dst_len + 1;
	pos = 0;
	while (src[pos] && pos < dstsize)
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = '\0';
	return (dst_len + src_len);
}
