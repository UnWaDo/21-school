#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	out_char;

	if (nb < 0)
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			ft_putnbr(-nb);
		}
	}
	else
	{
		if (nb / 10)
			ft_putnbr(nb / 10);
		out_char = '0' + nb % 10;
		write(1, &out_char, 1);
	}
}
