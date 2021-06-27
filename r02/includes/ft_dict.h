#ifndef FT_DICT_H
# define FT_DICT_H

typedef struct s_dict {
	struct s_dict	*next;
	char		*val;
	char		*txt;
	int			order;
}	t_dict;

t_dict	*dict_create(char *val, char *txt);
int		dict_append(t_dict **begin, char *val, char *txt);
void	dict_clear(t_dict *begin);
void	dict_apply(t_dict *begin, void (*fun)(t_dict *));
void	dict_sort_by_val(t_dict **begin);

#endif