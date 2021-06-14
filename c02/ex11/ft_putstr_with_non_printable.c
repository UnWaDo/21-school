#include <unistd.h>

int	ft_is_printable(char c)
{
	return (!(c < ' ' || c > '~'));
}

void	ft_put_hex(int a)
{
	char	c;

	if (a >= 0 && a <= 9)
		c = '0' + a;
	else
		c = 'a' + a - 10;
	write(1, &c, 1);
}

void	ft_put_unprintable(char c)
{
	int		a;
	int		b;

	a = c / 16;
	b = c % 16;
	c = '\\';
	write(1, &c, 1);
	ft_put_hex(a);
	ft_put_hex(b);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_is_printable(str[i]))
			write(1, str + i, 1);
		else
			ft_put_unprintable(str[i]);
		i++;
	}
}
