#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *begin, char *end)
{
	int	i;
	int	j;

	i = 0;
	while (begin[i])
		i++;
	j = 0;
	while (end[j])
	{
		begin[i + j] = end[j];
		j++;
	}
	begin[i + j] = 0;
	return (begin + i + j);
}

int	ft_get_space(int size, char **strs, char *sep)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	while (i < size)
	{
		space += ft_strlen(strs[i]);
		i++;
	}
	space += ft_strlen(sep) * (size - 1) + 1;
	return (space);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*res_end;
	int		i;

	if (size <= 0)
	{
		res = malloc(sizeof(char));
		if (res)
			*res = 0;
		return (res);
	}
	res = malloc(sizeof(char) * ft_get_space(size, strs, sep));
	if (!res)
		return (0);
	res_end = res;
	*res = 0;
	i = 0;
	while (i < size - 1)
	{
		res_end = ft_strcat(res_end, strs[i]);
		res_end = ft_strcat(res_end, sep);
		i++;
	}
	res_end = ft_strcat(res_end, strs[i]);
	return (res);
}
