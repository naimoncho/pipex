#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	char	*exec;
	char	**allpath;
	char	**cmd_split;
	
	allpath = ft_split(get_env("PATH", env), ':');
	if (!allpath)
		return (NULL);
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split || !cmd_split[0])
		return(ft_free(allpath), NULL);
	exec = find_exec_in_path(allpath, cmd_split[0]);
	ft_free(allpath);
	ft_free(cmd_split);
	return (exec);
}

void	execute_cmds(char *av, char **env)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(av, ' ');
	path = get_path(cmds[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex : command not found\n", STDERR_FILENO);
		ft_putendl_fd(cmds[0], STDERR_FILENO);
		ft_free(cmds);
		exit(0);
	}
	if (execve(path, cmds, env) == -1)
		ft_error();
}

void	main_process(char **av,int *process_fd, char **env)
{
	int	outfile;

	outfile = openfd_infile(av[4], 1);
	dup2(outfile, 1);
	dup2(process_fd[0], 0);
	close(process_fd[1]);
	execute_cmds(av[3], env);
}

void	child_process(char **av,int *process_fd, char **env)
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
	pid_t	PIDs;

	if (argc != 5)
	{
		ft_putstr_fd("Neccesary : ./pipex infile cmd cmd outfile\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if(pipe(process_fd) == -1)
		exit(-1);
	PIDs = fork();
	if (PIDs == -1)
		exit (-1);
	if (!PIDs)
		child_process(av, process_fd, env);
	main_process(av, process_fd, env);
}
