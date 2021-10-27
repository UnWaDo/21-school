#include <stdlib.h>
#include "ft_io.h"
#include "ft_strings.h"
#include "ft_list.h"
#include "ft_memory.h"
#include "ft_dict.h"

t_list	*ft_get_lines(char *file);
t_dict	*ft_parse_lines(t_list *lines);

static char	*ft_not_null(char *str, int *n)
{
	int	i;

	i = 0;
	while (*str && i < *n)
	{
		if (*str != '0')
		{
			*n = *n - i;
			return (str);
		}
		str++;
		i++;
	}
	*n = 0;
	return (0);
}

static void	ft_output(char *str, int len, t_dict *srt_dict)
{
	t_dict	*cur;
	int		right_len;
	int		left_len;

	cur = srt_dict;
	str = ft_not_null(str, &len);
	while (cur
		&& (cur->order > len
			|| (cur->order == len && ft_strncmp(cur->val, str, len) > 0)))
		cur = cur->next;
	if (!cur)
		return ;
	if (ft_strncmp(cur->val, str, len) == 0 && len < 3)
	{
		ft_putstr(cur->txt);
		return ;
	}
	left_len = len - cur->order + 1;
	right_len = cur->order - 1;
	ft_output(str, left_len, srt_dict);
	ft_putchar(' ');
	ft_putstr(cur->txt);
	str = ft_not_null(str + left_len, &right_len);
	if (right_len)
	{
		ft_putchar(' ');
		ft_output(str, right_len, srt_dict);
	}
}

static int	ft_validate_input(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!len)
		return (-1);
	if (!ft_is_numeric(str))
		return (-1);
	return (len);	
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*num;
	char	*filename;
	int		len;
	t_list	*list;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error: invalid number of arguments\nUsage: rush-02 [DictFile] number\n");
		return (10);
	}
	if (argc == 2)
	{
		num = argv[1];
		filename = "numbers.dict";
	}
	else
	{
		num = argv[2];
		filename = argv[1];
	}
	len = ft_validate_input(num);
	if (len == -1)
	{
		ft_putstr("Error\n");
		return (20);
	}
	list = ft_get_lines(filename);
	if (!list)
	{
		ft_putstr("Dict error\n");
		return (30);
	}
	dict = ft_parse_lines(list);
	if (!dict)
	{
		list_clear(list);
		ft_putstr("Dict error\n");
		return (40);
	}
	dict_sort_by_val(&dict);
	ft_output(num, len, dict);
	ft_putchar('\n');
	dict_clear(dict);
	list_clear(list);
	return (0);
}
