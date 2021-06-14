int	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_is_upper(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
