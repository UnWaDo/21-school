/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:01 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:41:47 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean_strings(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i] != NULL)
		free(splitted[i++]);
	free(splitted);
}

static size_t	count_strings(const char *s, char c)
{
	size_t	i;
	size_t	str_len;
	size_t	strings_c;

	i = 0;
	str_len = 0;
	strings_c = 0;
	while (s[i])
	{
		if (s[i] != c)
			str_len++;
		else if (str_len)
		{
			strings_c++;
			str_len = 0;
		}
		i++;
	}
	if (str_len != 0)
		strings_c++;
	return (strings_c);
}

static char	*next_string(const char *s, size_t *shift, char c)
{
	size_t	i;
	size_t	str_len;
	char	*new_str;

	i = *shift;
	str_len = 0;
	while (s[i])
	{
		if (s[i] != c)
			str_len++;
		else if (str_len)
			break ;
		i++;
	}
	new_str = ft_substr(s, i - str_len, str_len);
	*shift = i + 1;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	strings_c;
	size_t	i;
	char	**splitted;
	size_t	shift;

	strings_c = count_strings(s, c);
	splitted = ft_calloc(strings_c + 1, sizeof (*splitted));
	if (splitted == NULL)
		return (NULL);
	i = 0;
	shift = 0;
	while (i < strings_c)
	{
		splitted[i] = next_string(s, &shift, c);
		if (splitted[i] == NULL)
		{
			clean_strings(splitted);
			return (NULL);
		}
		i++;
	}
	return (splitted);
}
