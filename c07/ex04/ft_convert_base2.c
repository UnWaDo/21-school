int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_is_number_from_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-'
			|| base[i] <= ' ' || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_process_number(char *str, char *base, int len)
{
	int	i;
	int	res;
	int	number;

	i = 0;
	res = 0;
	number = ft_is_number_from_base(str[i], base);
	while (number != -1)
	{
		res *= len;
		res -= number;
		i++;
		number = ft_is_number_from_base(str[i], base);
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base, int length)
{
	int		sign;
	int		i;

	sign = -1;
	if (!length)
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign * ft_process_number(str + i, base, length));
}
