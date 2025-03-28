/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naimcheniounigomez <naimcheniounigomez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:51 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/27 22:00:10 by naimcheniou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errors(void)
{
	ft_putstr_fd("Unavailable path to search", STDERR_FILENO);
}

void	ft_exit(void)
{
	ft_errors();
	exit (0);
}

void	ft_openfd_infile(int *fd, char *cmd1)
{
	int miau;
	
	miau = open("infile", O_RDONLY);
	if (miau == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_exit();
	}
	dup2(miau, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(miau);
	access(cmd1, F_OK | X_OK);
}