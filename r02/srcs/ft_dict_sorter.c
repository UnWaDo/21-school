#include "ft_dict.h"
#include "ft_strings.h"

static void	dict_swap(t_dict **begin, t_dict **prev)
{
	t_dict	*now;
	t_dict	*next;

	if (!(*prev))
		now = *begin;
	else
		now = (*prev)->next;
	next = now->next;
	if (!*(prev))
	{
		*begin = next;
		now->next = next->next;
		next->next = now;
	}
	else
	{
		now->next = next->next;
		next->next = now;
		(*prev)->next = next;
	}
	*prev = next;
}

void	dict_sort_by_val(t_dict **begin)
{
	t_dict	*prev;
	t_dict	*now;
	t_dict	*next;

	if (!(*begin) || !((*begin)->next))
		return ;
	prev = 0;
	now = *begin;
	dict_sort_by_val(&(now->next));
	next = now->next;
	while (next)
	{
		if (now->order < next->order
			|| (now->order == next->order
				&& ft_strcmp(now->val, next->val) < 0))
			dict_swap(begin, &prev);
		else
			break ;
		next = now->next;
	}
}