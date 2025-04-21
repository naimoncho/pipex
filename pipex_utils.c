/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:51 by ncheniou          #+#    #+#             */
/*   Updated: 2025/04/21 13:17:42 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(void)
{
	ft_putstr_fd("Unavailable path to search", STDERR_FILENO);
	exit (0);
}

void	ft_free(char **str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a ++;
	}
	free(str);
}

int	openfd_infile(char *infile, int mode)
{
	int	fd;

	if (mode == 0)
	{
		fd = open(infile, O_RDONLY);
	}
	else if (mode == 1)
	{
		fd = open(infile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
		exit(EXIT_FAILURE);
	if (fd == -1)
	{
		perror("pipex: open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j ++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i ++;
	}
	return (NULL);
}

char	*find_exec_in_path(char **path, char *cmd_name)
{
	int		i;
	char	*exec;
	char	*part;

	i = 0;
	while (path[i])
	{
		part = ft_strjoin(path[i], "/");
		exec = ft_strjoin(part, cmd_name);
		free(part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	return (NULL);
}
