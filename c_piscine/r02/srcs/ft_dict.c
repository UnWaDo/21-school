#include "ft_dict.h"
#include "ft_io.h"
#include "ft_strings.h"
#include <stdlib.h>

t_dict	*dict_create(char *val, char *txt)
{
	t_dict	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->val = val;
	new->txt = txt;
	new->order = ft_strlen(val);
	new->next = 0;
	return (new);
}

int	dict_append(t_dict **begin, char *val, char *txt)
{
	t_dict	*now;
	t_dict	*new;

	new = dict_create(val, txt);
	if (!new)
		return (-1);
	if (!(*begin))
	{
		*begin = new;
		return (0);
	}
	now = *begin;
	while (now->next)
		now = now->next;
	now->next = new;
	return (0);
}

void	dict_clear(t_dict *begin)
{
	t_dict	*next;

	while (begin)
	{
		next = begin->next;
		free(begin->val);
		free(begin->txt);
		free(begin);
		begin = next;
	}
}

void	dict_apply(t_dict *begin, void (*fun)(t_dict *))
{
	t_dict	*next;

	while (begin)
	{
		next = begin->next;
		(*fun)(begin);
		begin = next;
	}
}
