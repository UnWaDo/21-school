/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:52 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:32:57 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	res;
	long long	new_value;
	size_t		pos;
	int			mltp;

	pos = 0;
	while (ft_isspace(str[pos]) && str[pos])
		pos++;
	mltp = 1;
	if (str[pos] == '-')
		mltp = -1;
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	res = 0;
	while (ft_isdigit(str[pos]))
	{
		new_value = res * 10 + mltp * (str[pos] - '0');
		if (mltp < 0 && new_value > res)
			return (0);
		if (mltp > 0 && new_value < res)
			return (-1);
		res = new_value;
		pos++;
	}
	return ((int) res);
}
