int	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(ft_is_lower(str[i]) || ft_is_upper(str[i])))
			return (0);
		i++;
	}
	return (1);
}
