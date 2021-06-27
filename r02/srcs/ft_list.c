#include "ft_list.h"
#include "ft_strings.h"
#include "ft_io.h"
#include <stdlib.h>

t_list	*list_create(char *str)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->str = str;
	new->next = 0;
	return (new);
}

void	list_clear(t_list *begin)
{
	t_list	*next;

	while (begin)
	{
		next = begin->next;
		free(begin->str);
		free(begin);
		begin = next;
	}
}

int	list_append(t_list **begin, char *str)
{
	t_list	*now;
	t_list	*new;

	new = list_create(str);
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

void	list_output(t_list *begin)
{
	while (begin)
	{
		ft_putstr(begin->str);
		ft_putchar('\n');
		begin = begin->next;
	}
}