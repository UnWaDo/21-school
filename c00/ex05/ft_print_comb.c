/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:10:45 by lalex             #+#    #+#             */
/*   Updated: 2021/06/10 20:39:27 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	while (arr[0] <= '6')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				write(1, arr, 3);
				write(1, ", ", 2);
				arr[2] = arr[2] + 1;
			}
			arr[1] = arr[1] + 1;
		}
		arr[0] = arr[0] + 1;
	}
	write(1, "789", 3);
}
