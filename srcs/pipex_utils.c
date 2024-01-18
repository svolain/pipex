/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:00:21 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/18 12:18:50 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    *find_path(char *cmd, char **envp)
{
    char    *whole_path;
    char    **split_paths;
    char    *temp_path;
    char    *final_path;
    int     i;

    whole_path = ft_substr(envp[13], 5, ft_strlen(envp[13]));
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
    int i;

    if (arr == NULL)
        return ;
    i = 0;
	while(arr[i++])
        free(arr[i]);
    free(arr);
}
