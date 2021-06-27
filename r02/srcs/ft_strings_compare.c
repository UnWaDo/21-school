int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != 0)
		i++;
	return (str1[i] - str2[i]);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != 0 && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
