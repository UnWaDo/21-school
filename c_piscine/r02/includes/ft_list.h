#ifndef FT_LISTS_H
# define FT_LISTS_H

typedef struct s_list {
	struct s_list	*next;
	char			*str;
}	t_list;

t_list	*list_create(char *str);
void		list_clear(t_list *begin);
int			list_append(t_list **begin, char *str);
void		list_output(t_list *begin);

#endif
