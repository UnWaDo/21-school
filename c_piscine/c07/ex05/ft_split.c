#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_is_separator(str[i], charset))
		i++;
	return (i);
}

int	ft_string_amount(char *str, char *charset)
{
	int	i;
	int	amount;
	int	length;

	amount = 0;
	length = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_separator(str[i], charset))
		{
			if (length > 0)
				amount++;
			length = 0;
		}
		else
			length++;
		i++;
	}
	if (!ft_is_separator(str[i - 1], charset))
		amount++;
	return (amount);
}

char	*ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest + i);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		amount;
	int		j;
	int		len;

	amount = ft_string_amount(str, charset);
	res = malloc(amount * sizeof(char *) + 1);
	if (!res)
		return (0);
	res[amount] = 0;
	j = 0;
	while (j < amount && *str)
	{
		len = ft_strlen(str, charset);
		if (len > 0)
		{
			res[j] = malloc(len * sizeof(char) + 1);
			if (!res[j])
				return (0);
			ft_strlcpy(res[j], str, len);
			j++;
		}
		str += len + 1;
	}
	return (res);
}
