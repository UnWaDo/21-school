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
	printf("Values are:\nprintf %d\nft_printf: %d", \
		printf("Printf'd string\n"), ft_printf("Ft_printf'd string\n"));
	return (0);
}