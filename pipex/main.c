#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char	**ft_split(char const *s, char c);
void	clean_strings(char **splitted);
extern char	**environ;

int	open_input(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (fd);
	if (dup2(fd, 0) == -1)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	starts_with(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (str2[i] == '\0')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	**get_paths()
{
	int		i;
	char	**paths;

	i = 0;
	while (environ[i] && starts_with(environ[i], "PATH=") == 0)
		i++;
	if (environ[i] == NULL)
		return (NULL);
	paths = ft_split(environ[i] + ft_strlen("PATH="), ':');
	return (paths);
}

char	*path_join(const char *dir, const char *file)
{
	size_t	i;
	size_t	len;
	char	*path;

	len = ft_strlen(dir) + ft_strlen(file);
	path = malloc((len + 2) * sizeof(*path));
	if (!path)
		return (NULL);
	path[len + 1] = '\0';
	i = 0;
	while (dir[i])
	{
		path[i] = dir[i];
		i++;
	}
	path[i] = '/';
	len = i + 1;
	while (file[len - i - 1])
	{
		path[len] = file[len - i - 1];
		len++;
	}
	return (path);
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf("%d: %s\n", i, args[i]);
		i++;
	}
}

char	**parse_command(const char *command)
{
	char	**args;
	char	**paths;
	char	*path;
	int		i;

	args = ft_split(command, ' ');
	if (!args)
		return (NULL);
	if (access(args[0], X_OK) != -1)
		return (args);
	paths = get_paths();
	if (!paths)
	{
		clean_strings(args);
		return (NULL);
	}
	i = 0;
	while (paths[i])
	{
		path = path_join(paths[i], args[0]);
		if (access(path, X_OK) != -1)
		{
			free(args[0]);
			args[0] = path;
			break ;
		}
		free(path);
		i++;
	}
	if (paths[i] == NULL)
	{
		clean_strings(args);
		clean_strings(paths);
		return (NULL);
	}
	clean_strings(paths);
	return (args);
}

void	close_pipe(int pipe_fds[2])
{
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

void	execute_cmd1(const char *file, const char *command, int out_fd)
{
	char	**cmd_args;
	int		fd;
	pid_t	child;
	int		child_status;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error while opening file1");
		exit(EXIT_FAILURE);
	}
	cmd_args = parse_command(command);
	if (!cmd_args)
	{
		perror("Error while parsing cmd1");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1 || dup2(out_fd, 1) == -1)
	{
		perror("Can't change descriptors");
		close(fd);
		clean_strings(cmd_args);
		exit(EXIT_FAILURE);
	}
	child = fork();
	if (child == -1)
	{
		perror("Fork creation failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
		execve(cmd_args[0], cmd_args, NULL);
	wait(&child_status);
	close(fd);
	clean_strings(cmd_args);
	if (child_status != -1)
		exit(EXIT_SUCCESS);
	perror("Error while executing cmd1");
	exit(EXIT_FAILURE);
}

void	execute_cmd2(const char *file, const char *command, int in_fd)
{
	char	**cmd_args;
	int		fd;
	pid_t	child;
	int		child_status;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("Error while opening file2");
		exit(EXIT_FAILURE);
	}
	cmd_args = parse_command(command);
	if (!cmd_args)
	{
		perror("Error while parsing cmd2");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (dup2(in_fd, 0) == -1 || dup2(fd, 1) == -1)
	{
		perror("Can't change descriptors");
		close(fd);
		clean_strings(cmd_args);
		exit(EXIT_FAILURE);
	}
	child = fork();
	if (child == -1)
	{
		perror("Fork creation failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
		execve(cmd_args[0], cmd_args, NULL);
	wait(&child_status);
	close(fd);
	clean_strings(cmd_args);
	if (child_status != -1)
		exit(EXIT_SUCCESS);
	perror("Error while executing cmd2");
	exit(EXIT_FAILURE);
}

int	main(int argc, char** argv)
{
	int		fd;
	pid_t	child;
	int		fork_status;
	int		pipe_fds[2];

	if (argc < 5)
	{
		printf("%s: bad usage\nTry '%s file1 cmd1 cmd2 file2'\n", argv[0], argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fds) == -1)
	{
		printf("%s: %s\n", argv[0], strerror(errno));
		exit(EXIT_FAILURE);
	}
	child = fork();
	if (child == -1)
	{
		printf("Fork is dropped: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
		execute_cmd1(argv[1], argv[2], pipe_fds[1]);
	wait(&fork_status);
	close(pipe_fds[1]);
	if (fork_status == -1)
	{
		close(pipe_fds[0]);
		exit(EXIT_FAILURE);
	}
	child = fork();
	if (child == -1)
	{
		printf("Fork is dropped: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
		execute_cmd2(argv[4], argv[3], pipe_fds[0]);
	wait(&fork_status);
	close(pipe_fds[0]);
	if (fork_status == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}