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
		printf_min("%d: %s\n", i, args[i]);
		i++;
	}
}

int	execute_cmd(int in_fd, int out_fd, const char *command)
{
	char	**cmd_args;
	pid_t	child;
	int		child_status;

	cmd_args = parse_command(command);
	if (!cmd_args)
		return (ARG_PARSING_ERROR);
	if (dup2(in_fd, 0) == -1 || dup2(out_fd, 1) == -1)
	{
		clean_strings(cmd_args);
		return (FD_CHANGE_ERROR);
	}
	child = fork();
	if (child == -1)
		return (FORK_ERROR);
	else if (child == 0)
		execve(cmd_args[0], cmd_args, NULL);
	wait(&child_status);
	clean_strings(cmd_args);
	if (child_status != -1)
		return (0);
	return (CHILD_ERROR);
}

int	execute_cmd1(const char *file, const char *command, int out_fd)
{
	int		fd;
	int		status;
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		printf_min(FORK_CREATION_ERROR, strerror(errno));
		return (EXIT_FAILURE);
	}
	else if (child == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			perror("Error while opening file1");
			exit(EXIT_FAILURE);
		}
		status = execute_cmd(fd, out_fd, command);
		close(fd);
		if (status == 0)
			exit(EXIT_SUCCESS);
		perror("Error while executing cmd1");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	close(out_fd);
	return (status);
}

int	execute_cmd2(const char *file, const char *command, int in_fd)
{
	int		fd;
	int		status;
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		printf_min(FORK_CREATION_ERROR, strerror(errno));
		return (EXIT_FAILURE);
	}
	else if (child == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error while opening file2");
			exit(EXIT_FAILURE);
		}
		status = execute_cmd(in_fd, fd, command);
		close(fd);
		if (status == 0)
			exit(EXIT_SUCCESS);
		perror("Error while executing cmd2");
		exit(EXIT_FAILURE);
	}
	wait(&status);
	close(in_fd);
	return (status);
}

static void	check_args(int argc, char **argv)
{
	if (argc == 5)
		return ;
	printf_min(BAD_USAGE_ERROR, argv[0]);
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
		printf_min(INPUT_FILE_ERROR, input, strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (fd != -1)
		close(fd);
	fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || write(fd, NULL, 0) == -1)
	{
		if (fd != -1)
			close(fd);
		printf_min(OUTPUT_FILE_ERROR, output, strerror(errno));
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
		printf_min(PIPE_CREATION_ERROR, strerror(errno));
		exit(EXIT_FAILURE);
	}
	env_path(envp, PATH_INIT);
	if (execute_cmd1(argv[1], argv[2], pipe_fds[1]) != EXIT_SUCCESS)
	{
		env_path(envp, PATH_CLEAN);
		close(pipe_fds[0]);
		exit(EXIT_FAILURE);
	}
	if (execute_cmd2(argv[4], argv[3], pipe_fds[0]) != EXIT_SUCCESS)
	{
		env_path(envp, PATH_CLEAN);
		exit(EXIT_FAILURE);
	}
	env_path(envp, PATH_CLEAN);
	exit(EXIT_SUCCESS);
}
