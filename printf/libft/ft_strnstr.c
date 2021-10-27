/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:23 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:32:27 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	search_pos;
	size_t	needle_pos;

	if (*needle == '\0')
		return ((char *) haystack);
	search_pos = 0;
	while ((search_pos < len) && haystack[search_pos])
	{
		needle_pos = 0;
		while (needle[needle_pos]
			&& (needle[needle_pos] == haystack[search_pos + needle_pos])
			&& (search_pos + needle_pos < len))
			needle_pos++;
		if (!needle[needle_pos])
			return ((char *) haystack + search_pos);
		search_pos++;
	}
	return (NULL);
}
