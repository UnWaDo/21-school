#include "ft_printf_utils.h"

size_t	ptr_len(t_ptr_int ptr)
{
	size_t	len;

	len = 1;
	while (ptr / 16)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

size_t	uint_len(unsigned int value, unsigned int base)
{
	size_t	len;

	len = 1;
	while (value >= base)
	{
		value /= base;
		len++;
	}
	return (len);
}
