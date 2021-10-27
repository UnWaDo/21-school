char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	while (dest[i] != 0)
		i++;
	l = i;
	while (src[i - l] != 0)
	{
		dest[i] = src[i - l];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
