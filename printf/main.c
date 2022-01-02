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

void	test_int(const char *line, int value)
{
	int	e;
	int	r;

	e = printf(line, value);
	r = ft_printf(line, value);
	if (e == r)
		printf("Values OK\n");
	else
		printf("printf value:\t%d\nft_printf value:\t%d\n", e, r);

}

void	test_all_int(int value)
{
	test_int("%c\n", value);
	test_int("%d\n", value);
	test_int("%i\n", value);
	test_int("%u\n", value);
	test_int("%x\n", value);
	test_int("%X\n", value);
}

int	main(void)
{
	// int	e;
	// int	r;

	/* e = printf("Simple string with %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n", \
	 	'a', "bcdef", NULL, "NOT NULL", 123, 0x123, 100, 1303, 4221);
	r = ft_printf("Simple string with %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n", \
		'a', "bcdef", NULL, "NOT NULL", 123, 0x123, 100, 1303, 4221);
	// printf("printf value: %d\nft_printf value: %d\n", e, r);*/

	// test_all_int(1303);
	// test_all_int(-1303);
	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// Bonus part

	// test_int("%#d\n", 1303);
	// test_int("%#i\n", 1303);
	// test_int("%#u\n", 1303);
	// test_int("%#x\n", 1303);
	// test_int("%#X\n", 1303);

	// test_int("%#d\n", 1303);
	// test_int("%#i\n", 1303);
	// test_int("%#u\n", 1303);
	// test_int("%#x\n", 1303);
	// test_int("%#X\n", 1303);
	printf("%+d\n", 123);
	ft_printf("%+d\n", 123);
	return (0);
}
