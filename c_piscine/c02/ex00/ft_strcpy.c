char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	dest[0] = src[0];
	i = 1;
	while (src[i - 1] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
