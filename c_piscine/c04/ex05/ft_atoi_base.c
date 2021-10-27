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

int	ft_check_correct(char c, char *status)
{
	if (*status == 'b' && ft_isspace(c))
		return (1);
	else if (*status == 'b' && (c == '+' || c == '-'))
	{
		*status = 's';
		return (1);
	}
	else if (*status == 's' && (c == '+' || c == '-'))
		return (1);
	else
		return (0);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-')
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

int	ft_atoi_base(char *str, char *base)
{
	int		value[4];
	char	status;

	value[0] = -1;
	value[1] = 0;
	status = 'b';
	value[2] = ft_check_base(base);
	if (!value[2])
		return (0);
	while (*str)
	{
		value[3] = ft_is_number_from_base(*str, base);
		if (value[3] != -1)
		{
			status = 'n';
			value[1] *= value[2];
			value[1] -= value[3];
		}
		else if (!ft_check_correct(*str, &status))
			return (value[0] * value[1]);
		else if (*str == '-')
			value[0] *= -1;
		str++;
	}
	return (value[0] * value[1]);
}
