/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:42:33 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:43:01 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_len;
	size_t	str_len;
	size_t	i;
	size_t	j;
	char	*trimmed;

	str_len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	trimmed_len = str_len - i;
	if (!trimmed_len)
		return (ft_calloc(1, sizeof (*trimmed)));
	j = 0;
	while (ft_strchr(set, s1[str_len - 1 - j]) != NULL)
		j++;
	trimmed_len -= j;
	trimmed = ft_calloc(trimmed_len + 1, sizeof (*trimmed));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + i, trimmed_len + 1);
	return (trimmed);
}
