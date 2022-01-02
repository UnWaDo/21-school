#include "ft_printf_utils.h"

static char	*apply_precision(char *line, t_arg modifier)
{
	char	*tmp;
	size_t	len;

	if (modifier.precision < 0)
		return (line);
	if (modifier.type == 's')
		return (ft_substr(line, 0, modifier.precision));
	if (modifier.type == 'c' || ft_strchr(INTEGER_TYPES, modifier.type) == NULL)
		return (line);
	// TODO: think about %.2p
	len = ft_strlen(line);
	if (len >= (size_t) modifier.precision)
		return (line);
	tmp = malloc(modifier.precision + 1);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, '0', modifier.precision - len);
	tmp[modifier.precision - len] = 0;
	ft_strlcat(tmp, line, modifier.precision + 1);
	return (tmp);
}

static char	*apply_flags(char *line, t_arg modifier)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(line);
	if ((modifier.type == 'x' || modifier.type == 'X')
		&& (modifier.flags & O_ALT_FORM))
	{
		tmp = malloc(len + 3);
		if (!tmp)
			return (NULL);
		tmp[0] = '0';
		tmp[1] = modifier.type;
		tmp[2] = '\0';
		ft_strlcat(tmp, line, len + 3);
		len += 2;
		return (tmp);
	}
	if ((modifier.type == 'd' || modifier.type == 'i')
		&& (modifier.flags & (O_SIGN_BLANK | O_MANDATORY_SIGN)))
	{
		tmp = malloc(len + 2);
		if (!tmp)
			return (NULL);
		if (modifier.flags & O_SIGN_BLANK)
			tmp[0] = ' ';
		else
			tmp[0] = '+';
		tmp[1] = '\0';
		ft_strlcat(tmp, line, len + 2);
		len += 1;
		return (tmp);
	}
	return (line);
}

static char	*apply_width(char *line, t_arg modifier)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(line);
	if (len > modifier.width)
		return (line);
	tmp = malloc(modifier.width + 1);
	tmp[modifier.width] = 0;
	if (modifier.flags & O_LEFT_JUSTIFICATION)
	{
		ft_strlcpy(tmp, line, modifier.width + 1);
		ft_memset(tmp + len, ' ', modifier.width - len);
		return (tmp);
	}
	if (modifier.flags & O_ZERO_PADDED)
		ft_memset(tmp, '0', modifier.width - len);
	else
		ft_memset(tmp, ' ', modifier.width - len);
	tmp[modifier.width - len] = 0;
	ft_strlcat(tmp, line, modifier.width + 1);
	return (tmp);
}

char	*apply_modifiers(char *line, t_arg modifier)
{
	char	*tmp;

	tmp = apply_precision(line, modifier);
	if (tmp != line)
		free(line);
	if (!tmp)
		return (NULL);
	line = tmp;
	tmp = apply_flags(line, modifier);
	if (tmp != line)
		free(line);
	if (!tmp)
		return (NULL);
	line = tmp;
	tmp = apply_width(line, modifier);
	if (tmp != line)
		free(line);
	return (tmp);
}
