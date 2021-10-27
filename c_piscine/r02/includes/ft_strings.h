#ifndef FT_STRINGS_H
# define FT_STRINGS_H

int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_atoi(char *str);
int		ft_isspace(char c);
int		ft_is_numeric(char *str);
char	*ft_trim_spaces(char *str);
int		ft_is_in_str(char *str, char *to_find);
char	*ft_strldup(char *str, int n);

#endif
