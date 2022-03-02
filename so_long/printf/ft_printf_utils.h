/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:24:44 by lalex             #+#    #+#             */
/*   Updated: 2022/01/03 21:06:01 by lalex            ###   ########.fr       */
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

int		print_buffer(char *buffer, size_t *pos, int is_last);

void	fill_width(t_arg arg_fmt, size_t val_length, char *buffer, size_t *pos);
void	alt_form_to_buffer(t_arg arg_fmt, char *buffer, size_t *pos);
void	num_to_buffer(char *line, t_arg arg_fmt, char *buffer, size_t *pos);
void	n_str_symbols_to_buffer(char *str, size_t n, char *buffer, size_t *pos);
void	single_char_to_buffer(char c, char *buffer, size_t *pos);
void	sign_to_buffer(int value, t_arg arg_fmt, char *buffer, size_t *pos);

char	*ulong_to_string(unsigned long value, char *base);
char	*uint_to_string(unsigned int value, char *base);
size_t	total_num_length(int value, char *num_line, t_arg arg_fmt);

int		parse_argument(char **str, va_list *args, char *buffer, size_t *pos);
int		int_to_buffer(int value, t_arg arg_fmt, char *buffer, size_t *pos);
int		char_to_buffer(char symbol, t_arg arg_fmt, char *buffer, size_t *pos);
int		string_to_buffer(char *str, t_arg arg_fmt, char *buffer, size_t *pos);
int		pointer_to_buffer(void *ptr, t_arg arg_fmt, char *buffer, size_t *pos);

# define INTEGER_TYPES			"diuxX"
# define DECIMAL_BASE			"0123456789"
# define HEX_BASE_LOWER			"0123456789abcdef"
# define HEX_BASE_UPPER			"0123456789ABCDEF"
# define NULL_POINTER_REPR		"(null)"

# define PRINTF_FLAGS 			"#0- +"
# define O_ALT_FORM 			0b1
# define O_ZERO_PADDED 			0b10
# define O_LEFT_JUSTIFICATION	0b100
# define O_SIGN_BLANK 			0b1000
# define O_MANDATORY_SIGN		0b10000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif