#include <stdarg.h>
#include "pipex.h"

static int	print_s(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

static void	reverse_mem(char *mem, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = mem[i];
		mem[i] = mem[len - i];
		mem[len - i] = tmp;
		i++;
	}
}

#define MAX_INT_LEN	10

static int	print_d(int d)
{
	char	num[MAX_INT_LEN];
	size_t	len;

	if (d >= 0)
		d = -d;
	else
		write(1, "-", 1);
	len = 1;
	while (d / 10)
	{
		num[MAX_INT_LEN - len] = -(d % 10) + '0';
		d /= 10;
		len++;
	}
	num[MAX_INT_LEN - len] = -(d % 10) + '0';
	reverse_mem(num + MAX_INT_LEN - len, len);
	return (write(1, num + MAX_INT_LEN - len, len));
}

int	printf_min(const char *s, ...)
{
	va_list	args;
	size_t	len;
	size_t	last_out;
	int		out;

	va_start(args, s);
	len = 0;
	last_out = 0;
	out = 0;
	while (s[len])
	{
		if (s[len] == '%')
		{
			out += write(1, s + last_out, len - last_out);
			if (s[len + 1] == 's')
				out += print_s(va_arg(args, char *));
			if (s[len + 1] == 'd')
				out += print_d(va_arg(args, int));
			len += 1;
			last_out = len + 1;
		}
		len++;
	}
	out += write(1, s + last_out, len - last_out);
	return (out);
}
