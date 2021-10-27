/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:42:19 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:42:25 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	len;
	char	*joined;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	joined = ft_calloc(len + 1, sizeof (*joined));
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, len + 1);
	return (joined);
}
