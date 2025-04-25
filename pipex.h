/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:17:37 by ncheniou          #+#    #+#             */
/*   Updated: 2025/04/25 10:02:33 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/wait.h>

char	*find_in_split_path(char *path, char *cmd);
void	ft_free(char **str);
int		openfd_infile(char *infile, int access);
char	*get_env(char *name, char **env);
char	*find_exec_in_path(char **path, char *cmd_name);
char	*get_path(char *cmd, char **env);
void	execute_cmds(char *av, char **env);
void	main_process(char **av, int *process_fd, char **env);
void	child_process(char **av, int *process_fd, char **env);

#endif