#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

# define BUFFER_SIZE	500

static char	*pop_line(char *buffer, size_t max)
{
	char	*res;
	size_t	i;

	res = malloc((max + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && i < max)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static ssize_t	start;
	static ssize_t	end;
	char			*res;
	char			*tmp;

	if (end < BUFFER_SIZE)
		end += read(fd, buff + end, BUFFER_SIZE - end);
	res = pop_line(buff + start, end - start);
	if (!res)
	{
		start = 0;
		end = 0;
		return (NULL);
	}
	start += ft_strlen(res);
	if (start == end)
	{
		end = read(fd, buff, BUFFER_SIZE);
		tmp = pop_line(buff, end);
	}
}