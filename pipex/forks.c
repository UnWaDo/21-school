/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:31:51 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 23:07:39 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "pipex.h"

static int	execute_cmd(int in_fd, int out_fd, const char *command)
{
	char	**cmd_args;
	pid_t	child;
	int		child_status;

	cmd_args = parse_command(command);
	if (!cmd_args)
		return (ARG_PARSING_ERROR);
	child = fork();
	if (child == -1)
		return (FORK_ERROR);
	else if (child == 0)
	{
		if (dup2(in_fd, 0) == -1 || dup2(out_fd, 1) == -1)
			exit(EXIT_FAILURE);
		execve(cmd_args[0], cmd_args, NULL);
	}
	wait(&child_status);
	clean_strings(cmd_args);
	return (child_status);
}

static int	execute_middle(int in_fd, char *command, int *status)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
	{
		printf_err(PIPE_CREATION_ERROR, strerror(errno));
		close(in_fd);
		return (-1);
	}
	*status = execute_cmd(in_fd, pipe_fds[1], command);
	close(pipe_fds[1]);
	close(in_fd);
	return (pipe_fds[0]);
}

int	execute_commands(int in_fd, int out_fd, char **commands, int cmdc)
{
	int	fd;
	int	status;
	int	i;

	i = 0;
	fd = in_fd;
	while (i < cmdc - 1 && fd != -1)
	{
		fd = execute_middle(fd, commands[i], &status);
		i++;
	}
	if (fd == -1)
	{
		close(out_fd);
		return (EXIT_FAILURE);
	}
	status = execute_cmd(fd, out_fd, commands[i]);
	close(fd);
	close(out_fd);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
