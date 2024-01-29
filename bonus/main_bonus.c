/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:38:39 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/26 15:02:17 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
}

void	pipe_init(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_handling(2, NULL);
	pid = fork();
	if (pid == -1)
		error_handling(3, NULL);
	if (!pid)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		run_cmd(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
	}
}

int	here_doc(char **argv)
{
	char	*input;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_handling(2, NULL);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		input = ft_get_next_line(0);
		if (input == NULL)
			break ;
		if (ft_strncmp(input, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(input);
			break ;
		}
		ft_putstr_fd(input, pipe_fd[1]);
		free(input);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd1;
	int	fd2;

	if (argc < 5)
		error_handling(1, NULL);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			error_handling(1, NULL);
		i = 3;
		fd1 = here_doc(argv);
		fd2 = check_open_fd(argv[argc - 1], 3);
	}
	else
	{
		i = 2;
		fd1 = check_open_fd(argv[1], 1);
		fd2 = check_open_fd(argv[argc - 1], 2);
	}
	dup2(fd1, 0);
	while (i < argc - 2)
		pipe_init(argv[i++], envp);
	dup2(fd2, 1);
	run_cmd(argv[argc - 2], envp);
}
