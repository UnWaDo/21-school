#include <stdlib.h>

char	*ft_memory_redist(char *init, int init_len,
	int res_len, void (*free_f)(void *))
{
	char	*res;
	int		i;

	res = malloc(res_len);
	if (!res)
		return (0);
	i = 0;
	while (i < res_len && i < init_len)
	{
		res[i] = init[i];
		i++;
	}
	(*free_f)(init);
	return (res);
}
