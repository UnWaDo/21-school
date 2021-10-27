#include "strings.h"
#include <stdlib.h>

char	*ft_strldup(char *str, int n)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	while (str[len] && len < n)
		len++;
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}