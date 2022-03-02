/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:40:52 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:40:56 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	str_len;
	char	*str;
	size_t	i;

	str_len = ft_numlen(n);
	str = ft_calloc(str_len + 1, sizeof (*str));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n > 0)
		n = -n;
	else
		str[0] = '0';
	i = 0;
	while (n)
	{
		str[str_len - i - 1] = '0' - (n % 10);
		n /= 10;
		i++;
	}
	return (str);
}
