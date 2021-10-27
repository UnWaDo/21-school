#include "ft_memory.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_strs {
	struct s_strs	*next;
	char		*str;
}	t_strs;

typedef struct s_dict {
	struct s_dict	*next;
	char		*val;
	char		*txt;
	int			order;
}	t_dict;

void	ft_sort_dict(t_dict **begin)
{
	t_dict	*now;

	if (!(*begin))
		return ;
	now = *begin;
	ft_sort_dict(&(now->next));
	while (now->next && now->

int	ft_append_from_buf(char **dst, int dst_len, char *buf, int buf_len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while(*dst[i] && i < dst_len)
		i++;
	j = 0;
	while (j < buf_len)
	{
		if (i + j > dst_len)
		{
			tmp = ft_memory_redist(*dst, dst_len, 2 * dst_leni + 1, &free);
			if (!tmp)
				return (0);
			*dst = tmp;
			dst_len = 2 * dst_len + 1;
		}
		(*dst)[i + j] = buf[j];
		j++;
	}
	tmp = ft_memory_redist(*dst, dst_len, i + j + 1, &free);
	if (!tmp)
		return 0;
	(*dst)[i + j] = 0;
	return (i + j);
}

int	ft_split_lines(t_strs *lines, char *str)
{
	int	i;
	int	j;

	while (str[i])
	{
		while (str[j] != '\n')
			j++;
		i
}

char	**ft_get_lines(char *file)
{
	int	fd;
	int	r_count;
	char	**res;
	const int	BUFF_SIZE = 200;
	int	buf[BUFF_SIZE];
	int		shift;

	fd = open(file, O_RDONLY);
	if (fd != -1)
		return (0);
	shift = 0;
	r_count = read(fd, buf, BUFF_SIZE);
	while (r_count > 0)
	{
		i = 0;
		while (i < r_count)
		{
			if (buf[i] == '\n')
				ft_append_from_buf(res[k], ft_strlen(res[k]), buf + shift, i - shift);
		r_count = read(fd, buf, BUFF_SIZE);
		
}
