#include "ft_printf.h"
#include "ft_printf_utils.h"

static char	*stringify_void_ptr(t_ptr_int value)
{
	char		*line;
	size_t		len;

	len = ptr_len(value) + 2;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = 0;
	while (len-- > 1)
	{
		line[len] = HEX_BASE_LOWER[value % 16];
		value /= 16;
	}
	line[0] = '0';
	line[1] = 'x';
	return (line);
}

static t_arg	adjust_ptr_modifier(void *value, t_arg modifier)
{
	modifier.flags &= O_LEFT_JUSTIFICATION;
	return (modifier);
}

char	*stringify_pointer(void *value, t_arg modifier)
{
	char		*line;

	if (value == NULL)
		line = ft_strdup(NULL_POINTER_REPR);
	else if (modifier.type == 's')
		line = ft_strdup((char *) value);
	else
		line = stringify_void_ptr((t_ptr_int) value);
	modifier = adjust_ptr_modifier(value, modifier);
	if (line)
		line = apply_modifiers(line, modifier);
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

static t_arg	adjust_int_modifier(int value, t_arg modifier)
{
	if (value == 0)
		modifier.flags &= (~O_ALT_FORM);
	if ((modifier.type == 'd' || modifier.type == 'i') && value < 0)
		modifier.flags &= (~(O_SIGN_BLANK | O_MANDATORY_SIGN));
	return (modifier);
}

char	*stringify_integer(int value, t_arg modifier)
{
	char	*line;

	if (modifier.type == 'c')
		line = stringify_char((char) value);
	else if (modifier.type == 'd' || modifier.type == 'i')
		line = ft_itoa(value);
	else if (modifier.type == 'u')
		line = stringify_uint((unsigned int) value, 10, DECIMAL_BASE);
	else if (modifier.type == 'x')
		line = stringify_uint((unsigned int) value, 16, HEX_BASE_LOWER);
	else if (modifier.type == 'X')
		line = stringify_uint((unsigned int) value, 16, HEX_BASE_UPPER);
	else
		line = NULL;
	modifier = adjust_int_modifier(value, modifier);
	if (line)
		line = apply_modifiers(line, modifier);
	return (line);
}