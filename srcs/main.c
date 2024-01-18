/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:59 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/18 13:53:18 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	run_cmd(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = find_path(split_cmd[0], envp);
	if (execve(path, split_cmd, envp) == -1)
	{
		free_matrix(split_cmd);
	}
	free(path);
	free_matrix(split_cmd);
}

void	pipe_child(char **argv, int *pipe_fd, char **envp)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY, 0777);
	if (fd1 == -1)
	{
		perror("open: ");
		exit(-1);
	}
	if (dup2(fd1, 0) == -1)
	{
		perror("dup2: ");
		close(fd1);
		exit(-1);
	}
	if (dup2(pipe_fd[1], 1) == -1)
	{
		perror("dup2: ");
		close(fd1);
		exit(-1);
	}
	close(pipe_fd[0]);
	close(fd1);
	run_cmd(argv[2], envp);
}

void	pipe_parent(char **argv, int *pipe_fd, char **envp)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		perror("open: ");
		exit(-1);
	}
	if (dup2(fd2, 1) == -1)
	{
		perror("dup2: ");
		close(fd2);
		exit(-1);
	}
	if (dup2(pipe_fd[0], 0) == -1)
	{
		perror("dup2: ");
		close(fd2);
		exit(-1);
	}
	close(pipe_fd[1]);
	close(fd2);
	run_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	child_pid;
	int		status;

	if (argc != 5)
		return (1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe: ");
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork: ");
		return (1);
	}
	if (!child_pid)
	{
		waitpid(-1, &status, 0);
		pipe_child(argv, pipe_fd, envp);
	}
	pipe_parent(argv, pipe_fd, envp);
}
