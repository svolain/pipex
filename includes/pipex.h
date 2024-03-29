/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:17:04 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/26 12:44:42 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define CMDERROR "zsh: command not found: "
# define OPNERROR "zsh: no such file or directory: "
# define ARGERROR "zsh: < file1 cmd1 | cmd2 > file2\n"
# define PIPERROR "zsh: pipe failure\n"
# define FRKERROR "zsh: fork failure\n"
# define DUPERROR "zsh: dup failure\n"
# define FILERROR "zsh: permission denied: "

char	*find_path(char *cmd, char **envp);
void	free_matrix(char **arr);
void	error_handling(int error_nbr, char *error_str);
char	*parse_envp(char **envp);

#endif
