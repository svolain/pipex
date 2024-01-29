/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:36:02 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/26 10:38:38 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*parse_envp(char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		tmp = ft_substr(envp[i], 0, j);
		if (ft_strncmp(tmp, "PATH", j) == 0)
		{
			free(tmp);
			return (ft_strdup(envp[i] + j + 1));
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	*whole_path;
	char	**split_paths;
	char	*temp_path;
	char	*final_path;
	int		i;

	whole_path = parse_envp(envp);
	split_paths = ft_split(whole_path, ':');
	i = -1;
	while (split_paths[++i])
	{
		temp_path = ft_strjoin(split_paths[i], "/");
		final_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free_matrix(split_paths);
			free(whole_path);
			return (final_path);
		}
		free(final_path);
	}
	free(whole_path);
	free_matrix(split_paths);
	return (cmd);
}

void	free_matrix(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i++])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	error_handling(int error_nbr, char *error_str)
{
	if (error_nbr == 1)
		ft_putstr_fd(ARGERROR, 2);
	else if (error_nbr == 2)
		ft_putstr_fd(PIPERROR, 2);
	else if (error_nbr == 3)
		ft_putstr_fd(FRKERROR, 2);
	else if (error_nbr == 4)
	{
		ft_putstr_fd(OPNERROR, 2);
		ft_putendl_fd(error_str, 2);
	}
	else if (error_nbr == 5)
		ft_putstr_fd(DUPERROR, 2);
	else if (error_nbr == 6)
	{
		ft_putstr_fd(FILERROR, 2);
		ft_putendl_fd(error_str, 2);
	}
	exit (EXIT_FAILURE);
}

int	check_open_fd(char *file, int fd_nbr)
{
	int	fd;

	fd = 0;
	if (fd_nbr == 1)
	{
		if (access(file, R_OK) != 0)
			error_handling(6, file);
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
			error_handling(4, file);
	}
	else if (fd_nbr == 2)
	{
		if (access(file, F_OK) == 0)
			if (access(file, R_OK) != 0)
				error_handling(6, file);
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1)
			error_handling(4, file);
	}
	else if (fd_nbr == 3)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	return (fd);
}
