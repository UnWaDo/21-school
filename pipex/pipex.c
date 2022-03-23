/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:26:41 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 23:26:53 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "pipex.h"

# define HERE_DOC	"here_doc\n"

static void	check_args(int argc, char **argv)
{
	if (argc >= 5)
		return ;
	printf_err(BAD_USAGE_ERROR, argv[0]);
	exit(EXIT_FAILURE);
}

static int	check_file(const char *filename, int flags, int code)
{
	int	fd;

	fd = open(filename, flags, code);
	if (fd < 0)
		printf_err(FILE_ERROR, strerror(errno), filename);
	else if ((flags & (O_RDONLY | O_RDWR)) && read(fd, NULL, 0) < 0)
		printf_err(FILE_ERROR, strerror(errno), filename);
	else if ((flags & (O_WRONLY | O_RDWR)) && write(fd, NULL, 0) < 0)
		printf_err(FILE_ERROR, strerror(errno), filename);
	else
		return (fd);
	if (fd > 0)
		close(fd);
	return (-1);
}

static int	here_doc(char *limiter)
{
	int		pipe_fds[2];
	char	*line;

	if (pipe(pipe_fds) == -1)
	{
		printf_err(PIPE_CREATION_ERROR, strerror(errno));
		return (-1);
	}
	line = get_next_line(0);
	while (line)	
	
	return (-1);
}

static int	check_files(int argc, char **argv, int fds[2])
{
	if (ft_strncmp(argv[1], HERE_DOC, sizeof(HERE_DOC)) == 0)
	{
		fds[0] = here_doc(argv[2]);
		fds[1] = check_file(argv[1], O_WRONLY | O_CREAT, 0644);
	}
	else
	{
		fds[0] = check_file(argv[1], O_RDONLY, 0);
		fds[1] = check_file(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (fds[0] == -1 || fds[1] == -1)
	{
		if (fds[0] != -1)
			close(fds[0]);
		if (fds[1] != -1)
			close(fds[1]);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	io_fds[2];

	check_args(argc, argv);
	check_files(argc, argv, io_fds);
	env_path(envp, PATH_INIT);
	status = execute_commands(io_fds[0], io_fds[1], argv + 2, argc - 3);
	env_path(envp, PATH_CLEAN);
	exit(status);
}
