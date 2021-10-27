/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:50 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:36:55 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	search;
	char	*pos;

	search = (char) c;
	pos = NULL;
	while (*s)
	{
		if (*s == search)
			pos = (char *) s;
		s++;
	}
	if (*s == search)
		pos = (char *) s;
	return (pos);
}
