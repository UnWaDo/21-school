#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(max - min);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i + min < max)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (i);
}
