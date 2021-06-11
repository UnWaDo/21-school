/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:44:09 by lalex             #+#    #+#             */
/*   Updated: 2021/06/10 22:58:53 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_array(char *arr, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		arr[i] = '0' + i;
		i++;
	}
}

void	ft_justify_array(char *arr, int n)
{
	int		i;
	int		j;

	j = n;
	i = n - 1;
	while (i > 0)
	{
		if (arr[i] > '9' - (n - i) + 1)
		{
			arr[i - 1]++;
			j = i;
		}
		i--;
	}
	i = j;
	while (i < n)
	{
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	value[9];

	ft_init_array(value, n);
	while (value[0] <= '9' - n)
	{
		write(1, value, n);
		write(1, ", ", 2);
		value[n - 1]++;
		ft_justify_array(value, n);
	}
	write(1, value, n);
}
