/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2021/10/27 23:29:36 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdint.h>
# include <stddef.h>
# include "libft/libft.h"

char	*stringify_char(char value);
char	*stringify_uint(unsigned int value, int base, const char *symbols);
char	*stringify_integer(int value, char modifier);
char	*stringify_pointer(void *value, char modifier);
char	*stringify_percent();
int		print_all(t_list **buffer);
size_t	ptr_len(uintptr_t ptr);
size_t	uint_len(unsigned int value, int base);


# define INTEGER_TYPES "cdiuxX"
# define POINTER_TYPES "sp"
# define DECIMAL_BASE "0123456789"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define NULL_POINTER_REPR "(nil)"

#endif