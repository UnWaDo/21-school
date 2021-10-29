#include "ft_printf.h"
#include "ft_printf_utils.h"

char	*stringify_pointer(void *value, char modifier)
{
	uintptr_t	ptr;
	size_t		len;
	char		*line;
	char		*symbols;

	symbols = HEX_BASE_LOWER;
	if (modifier == 's')
		return (ft_strdup((char *) value));
	if (value == NULL)
		return (ft_strdup(NULL_POINTER_REPR));
	ptr = (uintptr_t) value;
	len = ptr_len(ptr);
	len += 2;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = 0;
	while (len-- > 1)
	{
		line[len] = symbols[ptr % 16];
		ptr /= 16;
	}
	line[0] = '0';
	line[1] = 'x';
	return (line);
}

char	*stringify_char(char value)
{
	char	*line;

	line = malloc(2);
	if (!line)
		return (NULL);
	line[0] = value;
	line[1] = 0;
	return (line);
}

char	*stringify_uint(unsigned int value, int base, const char *symbols)
{
	size_t		len;
	char		*line;

	len = uint_len(value, base);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = 0;
	while (len--)
	{
		line[len] = symbols[value % base];
		value /= base;
	}
	return (line);
}

char	*stringify_integer(int value, char modifier)
{
	if (modifier == 'c')
		return (stringify_char((char) value));
	if (modifier == 'd' || modifier == 'i')
		return (ft_itoa(value));
	if (modifier == 'u')
		return (stringify_uint((unsigned int) value, 10, DECIMAL_BASE));
	if (modifier == 'x')
		return (stringify_uint((unsigned int) value, 16, HEX_BASE_LOWER));
	if (modifier == 'X')
		return (stringify_uint((unsigned int) value, 16, HEX_BASE_UPPER));
	return (NULL);

}

char	*stringify_percent()
{
	return (ft_strdup("%"));
}