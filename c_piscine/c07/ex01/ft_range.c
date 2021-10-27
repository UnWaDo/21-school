#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (0);
	array = malloc((max - min) * sizeof(int));
	if (array == 0)
		return (0);
	i = 0;
	while (i + min < max)
	{
		array[i] = i + min;
		i++;
	}
	return (array);
}
