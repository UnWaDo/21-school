/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:31:33 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:31:36 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while ((s1[pos] == s2[pos]) && (pos < n) && (s1[pos] != '\0'))
		pos++;
	if (pos >= n)
		return (0);
	return ((((unsigned char) s1[pos]) - ((unsigned char) s2[pos])));
}
