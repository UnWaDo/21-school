/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:32:54 by lalex             #+#    #+#             */
/*   Updated: 2022/03/04 11:55:35 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_path(const char *dir, const char *file)
{
	char	*path;

	path = path_join(dir, file);
	if (path == NULL)
		return (NULL);
	if (access(path, X_OK) != -1)
		return (path);
	free(path);
	return (NULL);
}

static char	*get_full_path(const char *command)
{
	char	**paths;
	char	*path;
	int		i;

	paths = env_path(NULL, PATH_READ);
	if (!paths)
		return (NULL);
	i = 0;
	path = NULL;
	while (paths[i])
	{
		path = check_path(paths[i], command);
		if (path)
			break ;
		i++;
	}
	return (path);
}

char	**parse_command(const char *command)
{
	char	**args;
	char	*path;

	args = split_args(command);
	if (!args)
		return (NULL);
	if (access(args[0], X_OK) != -1)
		return (args);
	path = get_full_path(args[0]);
	if (path == NULL)
	{
		printf_err(INVALID_COMMAND_ERROR, args[0]);
		clean_strings(args);
		return (NULL);
	}
	free(args[0]);
	args[0] = path;
	return (args);
}
