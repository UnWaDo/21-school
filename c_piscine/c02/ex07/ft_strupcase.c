int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_is_lower(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
