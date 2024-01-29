/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:33:36 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/26 12:42:34 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define CMDERROR "zsh: command not found: "
# define OPNERROR "zsh: no such file or directory: "
# define ARGERROR "zsh: wrong number of arguments\n"
# define PIPERROR "zsh: pipe failure\n"
# define FRKERROR "zsh: fork failure\n"
# define DUPERROR "zsh: dup failure\n"
# define FILERROR "zsh: permission denied: "

char	*find_path(char *cmd, char **envp);
void	free_matrix(char **arr);
void	error_handling(int error_nbr, char *error_str);
char	*parse_envp(char **envp);
int		check_open_fd(char *file, int fd_nbr);

#endif
