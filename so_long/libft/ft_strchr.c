/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:38 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:36:39 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	search;

	search = (char) c;
	while (*s)
	{
		if (*s == search)
			return ((char *) s);
		s++;
	}
	if (*s == search)
		return ((char *) s);
	return (NULL);
}
