char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (dest);
	dest[0] = src[0];
	i = 1;
	while (i < n && src[i - 1] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
