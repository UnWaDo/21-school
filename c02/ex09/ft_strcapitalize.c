int	ft_is_alpha(char c)
{
	int	lower;
	int	upper;

	lower = (c >= 'a' && c <= 'z');
	upper = (c >= 'A' && c <= 'Z');
	return (lower || upper);
}

void	ft_char_upcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	ft_char_lowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

int	ft_is_alpha_or_num(char c)
{
	int		alpha;
	int		num;

	num = (c >= '0' && c <= '9');
	alpha = ft_is_alpha(c);
	return (num || alpha);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		new_word;

	new_word = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (new_word && ft_is_alpha_or_num(str[i]))
		{
			ft_char_upcase(str + i);
			new_word = 0;
		}
		else if (!new_word && ft_is_alpha_or_num(str[i]))
			ft_char_lowcase(str + i);
		else if (!ft_is_alpha_or_num(str[i]))
			new_word = 1;
		i++;
	}
	return (str);
}
