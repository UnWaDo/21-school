/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:33:24 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:33:25 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	unsigned char	*b_char;
	size_t			i;

	byte = (unsigned char) c;
	b_char = b;
	i = 0;
	while (i < len)
	{
		b_char[i] = byte;
		i++;
	}
	return (b);
}
