/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:59 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/26 15:02:47 by vsavolai         ###   ########.fr       */
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
		ft_putstr_fd(CMDERROR, 2);
		ft_putendl_fd(split_cmd[0], 2);
		free_matrix(split_cmd);
		free(path);
		exit(0);
	}
	free(path);
	free_matrix(split_cmd);
}

void	pipe_child(char **argv, int *pipe_fd, char **envp)
{
	int	fd1;

	if (access(argv[1], R_OK) != 0)
		error_handling(4, argv[1]);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		error_handling(6, argv[1]);
	if (dup2(fd1, 0) == -1)
		error_handling(5, NULL);
	if (dup2(pipe_fd[1], 1) == -1)
		error_handling(5, NULL);
	close(pipe_fd[0]);
	close(fd1);
	run_cmd(argv[2], envp);
}

void	pipe_parent(char **argv, int *pipe_fd, char **envp)
{
	int	fd2;

	if (access(argv[4], F_OK) == 0)
	{
		if (access(argv[4], W_OK) != 0 || access(argv[4], R_OK) != 0)
			error_handling(6, argv[4]);
	}
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd2 == -1)
		error_handling(4, argv[4]);
	if (dup2(fd2, 1) == -1)
		error_handling(5, NULL);
	if (dup2(pipe_fd[0], 0) == -1)
		error_handling(5, NULL);
	close(pipe_fd[1]);
	close(fd2);
	run_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	child_pid;

	if (argc != 5)
		error_handling(1, NULL);
	if (pipe(pipe_fd) == -1)
		error_handling(2, NULL);
	child_pid = fork();
	if (child_pid == -1)
		error_handling(3, NULL);
	if (!child_pid)
		pipe_child(argv, pipe_fd, envp);
	pipe_parent(argv, pipe_fd, envp);
	return (0);
}
