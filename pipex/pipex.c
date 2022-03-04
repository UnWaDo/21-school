/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:26:41 by lalex             #+#    #+#             */
/*   Updated: 2022/03/04 11:47:53 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "pipex.h"

// TO BE DELETED
void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf_err("%d: %s\n", i, args[i]);
		i++;
	}
}

static void	check_args(int argc, char **argv)
{
	if (argc == 5)
		return ;
	printf_err(BAD_USAGE_ERROR, argv[0]);
	exit(EXIT_FAILURE);
}

static void	check_files(const char *input, const char *output)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) < 0)
	{
		if (fd != -1)
			close(fd);
		printf_err(INPUT_FILE_ERROR, input, strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (fd != -1)
		close(fd);
	fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || write(fd, NULL, 0) == -1)
	{
		if (fd != -1)
			close(fd);
		printf_err(OUTPUT_FILE_ERROR, output, strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (fd != -1)
		close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];

	check_args(argc, argv);
	check_files(argv[1], argv[argc - 1]);
	if (pipe(pipe_fds) == -1)
	{
		printf_err(PIPE_CREATION_ERROR, strerror(errno));
		exit(EXIT_FAILURE);
	}
	env_path(envp, PATH_INIT);
	execute_cmd1(argv[1], argv[2], pipe_fds[1]);
	if (execute_cmd2(argv[4], argv[3], pipe_fds[0]) != EXIT_SUCCESS)
	{
		env_path(envp, PATH_CLEAN);
		exit(EXIT_FAILURE);
	}
	env_path(envp, PATH_CLEAN);
	exit(EXIT_SUCCESS);
}
