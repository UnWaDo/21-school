#include "ft_printf_utils.h"

int	print_all(t_list **buffer)
{
	t_list	*cur;
	t_list	*next;
	int		count;

	count = 0;
	cur = *buffer;
	while (cur)
	{
		count += ft_putstr_fd((char *) cur->content, 1);
		next = cur->next;
		ft_lstdelone(cur, &free);
		cur = next;
	}
	*buffer = NULL;
	return (count);
}
