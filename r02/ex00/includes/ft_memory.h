#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# include <stdlib.h>

void    *ft_memory_redist(char *init, int init_len, int res_len, void (*free_f)(void *));

#endif
