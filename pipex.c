/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:20:07 by ncheniou          #+#    #+#             */
/*   Updated: 2025/04/25 13:32:03 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*result;
	char	**cmd_split;

	result = NULL;
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split || !cmd_split[0])
		return (NULL);
	if (ft_strchr(cmd_split[0], '/'))
	{
		if (access(cmd_split[0], F_OK | X_OK) == 0)
			result = ft_strdup(cmd_split[0]);
		ft_free(cmd_split);
		return (result);
	}
	path = get_env("PATH", env);
	if (!path)
	{
		ft_free(cmd_split);
		ft_putstr_fd("pipex: PATH not set\n", 2);
		exit(EXIT_FAILURE);
	}
	result = find_in_split_path(path, cmd_split[0]);
	ft_free(cmd_split);
	return (result);
}

void	execute_cmds(char *av, char **env)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(av, ' ');
	path = get_path(cmds[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found\n", STDERR_FILENO);
		ft_putendl_fd(cmds[0], STDERR_FILENO);
		ft_free(cmds);
		exit(127);
	}
	if (execve(path, cmds, env) == -1)
		ft_error();
}

void	main_process(char **av, int *process_fd, char **env)
{
	int	outfile;

	outfile = openfd_infile(av[4], 1);
	dup2(outfile, 1);
	dup2(process_fd[0], 0);
	close(process_fd[1]);
	execute_cmds(av[3], env);
}

void	child_process(char **av, int *process_fd, char **env)
{
	int	infile;

	infile = openfd_infile(av[1], 0);
	dup2(infile, 0);
	dup2(process_fd[1], 1);
	close(process_fd[0]);
	execute_cmds(av[2], env);
}

int	main(int argc, char **av, char **env)
{
	int		process_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (ft_putstr_fd(
				"./pipex infile cmd cmd outfile\n", 2), EXIT_FAILURE);
	if (pipe(process_fd) == -1)
		return (perror("pipe:"), EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork:"), EXIT_FAILURE);
	if (pid1 == 0)
		child_process(av, process_fd, env);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork;"), EXIT_FAILURE);
	if (pid2 == 0)
		main_process(av, process_fd, env);
	close(process_fd[0]);
	close(process_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
