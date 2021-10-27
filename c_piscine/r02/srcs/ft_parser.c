#include "ft_memory.h"
#include "ft_io.h"
#include "ft_strings.h"
#include "ft_list.h"
#include "ft_dict.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 10000

// int	ft_append_from_buf(char **dst, int dst_len, char *buf, int buf_len)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	while ((*dst)[i] && i < dst_len)
// 		i++;
// 	j = 0;
// 	while (j < buf_len)
// 	{
// 		if (i + j > dst_len)
// 		{
// 			tmp = ft_memory_redist(*dst, dst_len, 2 * dst_len + 10, &free);
// 			if (!tmp)
// 				return (0);
// 			*dst = tmp;
// 			dst_len = 2 * dst_len + 10;
// 		}
// 		(*dst)[i + j] = buf[j];
// 		j++;
// 	}
// 	tmp = ft_memory_redist(*dst, dst_len, i + j + 1, &free);
// 	if (!tmp)
// 		return (0);
// 	(*dst)[i + j] = 0;
// 	return (i + j);
// }

// int	ft_split_lines(t_strs *lines, char *str)
// {
// 	int	i;
// 	int	j;

// 	while (str[i])
// 	{
// 		while (str[j] != '\n')
// 			j++;
// 		i
// }

static int	ft_add_lines(t_list **begin, char *buff, int len)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	int		status;

	i = 0;
	while (i < len && buff[i] != 0)
	{
		j = 0;
		while (buff[i + j] && buff[i + j] != '\n')
			j++;
		if (j < 1)
		{
			i++;
			continue ;
		}
		tmp = ft_strldup(buff + i, j);
		if (!tmp)
			return (1);
		tmp2 = ft_trim_spaces(tmp);
		free(tmp);
		if (!tmp2)
			return (1);
		status = list_append(begin, tmp2);
		if (status)
		{
			free(tmp2);
			return (1);
		}
		i += j + 1;
	}
	return (0);
}

t_list	*ft_get_lines(char *file)
{
	int			fd;
	int			r_count;
	char		buff[BUFF_SIZE + 1];
	t_list		*begin;
	int			status;

	begin = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	r_count = read(fd, buff, BUFF_SIZE);
	while (r_count > 0)
	{
		buff[r_count] = 0;
		status = ft_add_lines(&begin, buff, r_count);
		if (status)
		{
			list_clear(begin);
			return (0);
		}
		r_count = read(fd, buff, BUFF_SIZE);
	}
	if (r_count == -1)
	{
		list_clear(begin);
		return (0);
	}
	return (begin);
}
int	ft_parse_line(char *str, t_dict **dict)
{
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;
	int		status;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	tmp1 = ft_strldup(str, i);
	if (!tmp1)
		return (1);
	while (str[i] && str[i] != ':')
		i++;
	if (str[i] != ':')
	{
		free(tmp1);
		return (1);
	}
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	j = 0;
	while (str[i + j])
		j++;
	tmp2 = ft_strldup(str + i, j);
	if (!tmp2)
	{
		free(tmp1);
		return (1);
	}
	status = dict_append(dict, tmp1, tmp2);
	ft_putstr((*dict)->val);
	ft_putchar('\n');
	ft_putstr((*dict)->txt);
	ft_putchar('\n');
	if (status)
		return (status);
	return (0);
}

t_dict	*ft_parse_lines(t_list *lines)
{
	t_list	*now;
	t_dict	*dict;
	int		status;

	now = lines;
	while (now)
	{
		status = ft_parse_line(now->str, &dict);
		if (status)
		{
			dict_clear(dict);
			return (0);
		}
		now = now->next;
	}
	return (dict);
}