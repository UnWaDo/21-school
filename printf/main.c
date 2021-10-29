/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:33:04 by lalex             #+#    #+#             */
/*   Updated: 2021/10/27 23:34:37 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	prf;
	int	ft_prf;
	
	prf = printf("Simple string with %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n", 'a', "bcdef", NULL, "NOT NULL", \
		123, 0x123, 100, 1303, 4221);
	ft_prf = ft_printf("Simple string with %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n", 'a', "bcdef", NULL, "NOT NULL", \
		123, 0x123, 100, 1303, 4221);
	printf("printf value: %d\nft_printf value: %d\n", prf, ft_prf);
	return (0);
}