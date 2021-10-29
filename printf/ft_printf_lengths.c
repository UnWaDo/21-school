#include "ft_printf_utils.h"

size_t	ptr_len(uintptr_t ptr)
{
	size_t len;

	len = 1;
	while (ptr /= 16)
		len++;
	return (len);
}

size_t	uint_len(unsigned int value, int base)
{
	size_t	len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}
