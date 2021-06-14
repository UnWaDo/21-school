#include <unistd.h>

int	ft_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_output(int nb, char *base, int length)
{
	int	remainder;

	remainder = nb % length;
	remainder *= -1;
	nb /= length;
	if (nb != 0)
		ft_output(nb, base, length);
	write(1, base + remainder, 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		length;

	length = ft_is_valid(base);
	if (!length)
		return ;
	if (nb < 0)
		write(1, "-", 1);
	else
		nb = -nb;
	ft_output(nb, base, length);
}
