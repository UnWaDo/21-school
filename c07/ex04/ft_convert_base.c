#include <unistd.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int base_length);

int	ft_check_base(char *base);

char	*ft_output(int nb, char *base, int length, char *place)
{
	int	remainder;

	remainder = nb % length;
	remainder *= -1;
	nb /= length;
	if (nb != 0)
		place = ft_output(nb, base, length, place);
	*place = base[remainder];
	place[1] = 0;
	return (place + 1);
}

int	ft_string_length(int nb, int base_length)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= base_length;
		i++;
	}
	return (i);
}

char	*ft_strnbr_base(int nb, char *base, int length)
{
	char	*res;
	int		number_len;
	int		shift;

	shift = 0;
	if (!length)
		return (0);
	number_len = ft_string_length(nb, length);
	res = malloc(number_len * sizeof(char) + 1);
	if (!res)
		return (0);
	if (nb < 0)
	{
		shift++;
		res[0] = '-';
	}
	else
		nb = -nb;
	ft_output(nb, base, length, res + shift);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;
	int		base_from_len;
	int		base_to_len;

	base_from_len = ft_check_base(base_from);
	base_to_len = ft_check_base(base_to);
	if (!base_from_len || !base_to_len)
		return (0);
	num = ft_atoi_base(nbr, base_from, base_from_len);
	res = ft_strnbr_base(num, base_to, base_to_len);
	return (res);
}
