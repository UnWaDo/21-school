/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2022/01/02 20:17:36 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdint.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_arg
{
	int		flags;
	size_t	width;
	int		precision;
	char	type;
}	t_arg;
typedef unsigned long	t_ptr_int;

char	*stringify_char(char value);
char	*stringify_uint(unsigned int value, int base, const char *symbols);
char	*stringify_integer(int value, t_arg modifier);
char	*stringify_pointer(void *value, t_arg modifier);
char	*stringify_percent(void);
int		print_all(t_list **buffer);
size_t	ptr_len(t_ptr_int ptr);
size_t	uint_len(unsigned int value, unsigned int base);
char	*apply_modifiers(char *line, t_arg modifier);

# define INTEGER_TYPES "cdiuxX"
# define DECIMAL_BASE "0123456789"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define NULL_POINTER_REPR "(null)"

# define PRINTF_FLAGS "#0- +"
# define O_ALT_FORM 0b1
# define O_ZERO_PADDED 0b10
# define O_LEFT_JUSTIFICATION 0b100
# define O_SIGN_BLANK 0b1000
# define O_MANDATORY_SIGN 0b1000

#endif