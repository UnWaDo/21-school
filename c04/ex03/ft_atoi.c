int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_check_correct(char c, char *status)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (ft_isspace(c) && *status == 'b')
		return (1);
	if (*status == 'b' && (c == '+' || c == '-'))
	{
		*status = 's';
		return (1);
	}
	else if (*status == 's' && (c == '+' || c == '-'))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int				sign;
	int				res;
	char			status;
	unsigned int	i;

	sign = -1;
	res = 0;
	status = 'b';
	i = 0;
	while (str[i])
	{
		if (!ft_check_correct(str[i], &status))
			return (sign * res);
		else if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			status = 'n';
			res *= 10;
			res -= str[i] - '0';
		}
		i++;
	}
	return (sign * res);
}
