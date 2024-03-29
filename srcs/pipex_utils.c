/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:00:21 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/23 19:09:28 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
