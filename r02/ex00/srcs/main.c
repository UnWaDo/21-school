#include <stdlib.h>
#include "ft_io.h"
#include "ft_strings.h"
#include "ft_memory.h"

int	main(int argc, char **argv)
{
	unsigned int	val;
	char			*dict;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error: no args given\nUsage: rush-02 number [DictFile]\n");
		return (10);
	}
	val = ft_atoi(argv[1]);
	if (argc > 2)
		dict = argv[2];
	else
		dict = "numbers.dict";
	dict = ft_trim_spaces(argv[1]);
	if (!dict)
		return (0);
	dict = ft_memory_redist(dict, ft_strlen(dict), 100, &free);
	if (dict)
	{
		dict[99] = 0;
		ft_putstr(dict);
	}
	free(dict);
	return (0);
}
