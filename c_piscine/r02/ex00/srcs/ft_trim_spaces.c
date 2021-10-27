#include <stdlib.h>

static int	ft_trim_spaces_len(char *str)
{
	int	len;
	int	was_space;

	len = 0;
	was_space = 1;
	while (*str)
	{
		if (*str != ' ')
		{
			len++;
			was_space = 0;
		}
		else if (!was_space)
		{
			len++;
			was_space = 1;
		}
		str++;
	}
	if (was_space == 1)
		len--;
	return (len);
}

static int	ft_prepare_trimmer(char *str, char **res)
{
	int	len;

	len = ft_trim_spaces_len(str);
	*res = malloc(sizeof(**res) * (len + 1));
	(*res)[len] = 0;
	return (len);
}

char	*ft_trim_spaces(char *str)
{
	int		i;
	int		len;
	char	*res;
	int		was_space;

	len = ft_prepare_trimmer(str, &res);
	if (!len)
		return (0);
	was_space = 1;
	i = 0;
	while (i < len)
	{
		if (*str != ' ')
		{
			res[i++] = *str;
			was_space = 0;
		}
		else if (!was_space)
		{
			res[i++] = *str;
			was_space = 1;
		}
		str++;
	}
	return (res);
}
