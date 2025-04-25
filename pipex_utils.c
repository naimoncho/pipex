/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:51 by ncheniou          #+#    #+#             */
/*   Updated: 2025/04/25 13:34:27 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (!env || !name)
		exit(EXIT_FAILURE);
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
		{
			j ++;
		}
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
	int		err;
	char	*exec;
	char	*part;

	i = 0;
	err = access(cmd_name, X_OK);
	if (err == 0)
		return (cmd_name);
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

char	*find_in_split_path(char *path, char *cmd)
{
	char	**allpath;
	char	*exec_path;
	char	*result;

	allpath = ft_split(path, ':');
	if (!allpath)
		return (NULL);
	exec_path = find_exec_in_path(allpath, cmd);
	if (exec_path != NULL)
		result = ft_strdup(exec_path);
	else
		result = NULL;
	ft_free(allpath);
	return (result);
}
