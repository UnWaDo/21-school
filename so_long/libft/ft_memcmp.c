/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:55 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:35:09 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_byte;
	const unsigned char	*s2_byte;
	size_t				i;

	if (!n)
		return (0);
	s1_byte = s1;
	s2_byte = s2;
	i = 0;
	while (i < n && s1_byte[i] == s2_byte[i])
		i++;
	if (i == n)
		return (0);
	return (s1_byte[i] - s2_byte[i]);
}
