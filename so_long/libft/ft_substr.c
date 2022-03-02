/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:42:04 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:42:06 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;

	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof (*s)));
	substr_len = 0;
	while (s[start + substr_len] && substr_len < len)
		substr_len++;
	substr = ft_calloc(substr_len + 1, sizeof (*s));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}
