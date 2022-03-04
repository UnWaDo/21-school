/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:31:51 by lalex             #+#    #+#             */
/*   Updated: 2022/03/04 11:47:27 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "pipex.h"

int	execute_cmd(int in_fd, int out_fd, const char *command)
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

int	execute_cmd1(const char *file, const char *command, int out_fd)
{
	int		fd;
	int		status;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf_err(INPUT_FILE_ERROR, file, strerror(errno));
		return (EXIT_FAILURE);
	}
	status = execute_cmd(fd, out_fd, command);
	close(fd);
	close(out_fd);
	return (status);
}

int	execute_cmd2(const char *file, const char *command, int in_fd)
{
	int		fd;
	int		status;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf_err(OUTPUT_FILE_ERROR, file, strerror(errno));
		return (EXIT_FAILURE);
	}
	status = execute_cmd(in_fd, fd, command);
	close(fd);
	close(in_fd);
	if (status != EXIT_SUCCESS)
		printf_err("Error in cmd2: %s\n", strerror(errno));
	return (status);
}
