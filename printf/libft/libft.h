/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:02:42 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:40:16 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Check whether `c` is alphabetical symbol
// Returns 1 if `c` is 'a'-'z' or 'A'-'Z' and 0 otherwise
int		ft_isalpha(int c);

// Check whether `c` is digit
// Returns 1 if `c` is '0'-'9' and 0 otherwise
int		ft_isdigit(int c);

// Check whether `c` is alphabetical symbol or digit
// Returns 1 if `c` is 'a'-'z' or 'A'-'Z' or '0'-'9' and 0 otherwise
int		ft_isalnum(int c);

// Check whether `c` is ASCII symbol
// Returns 1 if `c` is below 128 and 0 otherwise
int		ft_isascii(int c);

// Check whether `c` is printable character
// Returns 1 if `c` is >= 32 and < 127 and 0 otherwise
int		ft_isprint(int c);

// Calculates the length of the zero-terminated string
// Returns the length of string without terminating null character
size_t	ft_strlen(const char *str);

// Sets `len` bytes starting from `b` with unsigned char `c`
void	*ft_memset(void *b, int c, size_t len);

// Sets `n` bytes starting from `b` with zeros
void	ft_bzero(void *s, size_t n);

// Copies `n` bytes from `src` to `dst`
// If `src` and `dst` overlap, the behaviour is undefined
// Returns original `dst` value
void	*ft_memcpy(void *dst, const void *src, size_t n);

// Moves `n` bytes from `src` to `dst` in non-destructive manner
// Returns original `dst` value
void	*ft_memmove(void *dst, const void *src, size_t len);

// Copy not more than `dstsize` - 1 symbols from 
// null-terminated string `src` to `dst`
// Terminates dst with '\0'
// Returns the size of string it tried to create (i.e. size of `src`)
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Concatenate string `src` to `dst`
// Resulting string is null-terminated and 
// has length not more than `dstsize` - 1
// Returns the size of the string it tried to create
// (i.e. size of `dst` and `src` combined)
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// Converts letter to upper case
// Returns corresponding uppercase letter or unchanged value of `c`
int		ft_toupper(int c);

// Converts letter to lower case
// Returns corresponding lowercase letter or unchanged value of `c`
int		ft_tolower(int c);

// Returns pointer to first location of character `c` in string `s`
// Returns NULL if character does not appear in string
char	*ft_strchr(const char *s, int c);

// Returns pointer to last location of character `c` in string `s`
// Returns NULL if character does not appear in string
char	*ft_strrchr(const char *s, int c);

// Compares not more than `n` symbols from strings `s1` and `s2`
// Returns value above zero, zero or value below zero
// if `s1` is greater than, equal or less than `s2`
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Returns pointer to first location of unsigned char `c` in byte sequence `s`
// Returns NULL if `c` does not appear in first `n` bytes of `s`
void	*ft_memchr(const void *s, int c, size_t n);

// Compares not more than `n` bytes from sequences `s1` and `s2`
// Returns value above zero, zero or value below zero
// if `s1` is greater than, equal or less than `s2`
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Locates the position of substring `needle` in string `haystack`
// not more than `len` symbols of `haystack` are searched
// Returns pointer to first symbol of `needle` in `haystack`
// or NULL pointer if `needle` does not appear in `haystack`
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Transforms the decimal integer in `str` to corresponding int value
// Return int value located in string
// Returns 0 if underflow and -1 if overflow (overflow with long long)
int		ft_atoi(const char *str);

// Allocates memory for count objects of given size and filles it with zeros
// Returns pointer to allocated memory or NULL if allocation fails
void	*ft_calloc(size_t count, size_t size);

// Allocates memory for given string and makes its copy
// Returns pointer to string copy or NULL if allocation fails
char	*ft_strdup(const char *s1);

// Allocates and returns a substring of given string
// starting from start with length `len`
// Returns pointer to substring or NULL if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Join two given string
// Returns pointer to resulting string or NULL if allocation fails
char	*ft_strjoin(char const *s1, char const *s2);

// Trimms characters from `set` from beginning and end of string `s1`
// Return pointer to trimmed copy or NULL if allocation fails
char	*ft_strtrim(char const *s1, char const *set);

// Splits string by character `c`. Ignores zero length strings
// Returns resulting NULL-terminated array or NULL if allocation fails
char	**ft_split(char const *s, char c);

// Put number to newly allocated string
// Returns pointer to string or NULL if allocation fails
char	*ft_itoa(int n);

// Creates new string, generated by applying function `f` to each
// symbol of the initial one
// Returns pointer to new string or NULL if allocation fails
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Applies function `f` to each symbol of string `s`
// Function is given a pointer, so if can modify the initial string
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Returns 1 if `c` is a space character according to isspace(3)
// and 0 otherwise
int		ft_isspace(int c);

// Returns the length of number represented as string
size_t	ft_numlen(int n);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Creates new element with content `content`
// Returns pointer to allocated element or NULL if allocation fails
t_list	*ft_lstnew(void *content);

// Adds element `new` to the beginning of the list
// Does nothing if `new` is NULL
void	ft_lstadd_front(t_list **lst, t_list *new);

// Counts the length of the list
// (its first element and amount of its successors)
int		ft_lstsize(t_list *lst);

// Returns pointer to last element of the list
// (i.e. an element with `next` property equal to NULL)
// Returns NULL if `lst` is NULL
t_list	*ft_lstlast(t_list *lst);

// Adds element `new` to the end of the list
// Does nothing if `new` is NULL
// Preserves `new->next`
void	ft_lstadd_back(t_list **lst, t_list *new);

// Frees the memory of element's content with function `del`
// and frees the element's memory
// `lst->next` is not freed
// If `lst` is NULL, does nothing
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Frees the memory of element and all its successors
// using functions `del` and `free`
// If `lst` is NULL, does nothing
// The pointer to list is set to NULL afterwards
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Applies function `f` to content of all elements in the list
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Maps all elements of `lst` to create new list
// Content of elements is created by applying function `f`
// Function `del` is required to clear input if error occures
// Returns pointer to first element or NULL if allocation fails
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif