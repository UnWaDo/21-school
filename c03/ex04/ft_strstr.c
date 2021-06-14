char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	res = 0;
	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j] == 0)
				return (str + i);
			if (str[i + j] == 0)
				return (res);
			j++;
		}
		i++;
	}
	return (res);
}
