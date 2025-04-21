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


void	ft_exit(void);
void	ft_free(char **str);
int		openfd_infile(char *infile, int access);
char	*get_env(char *name, char **env);
char	*find_exec_in_path(char **path, char *cmd_name);
char	*get_path(char *cmd, char **env);
void	execute_cmds(char *av, char **env);
void	main_process(char **av,int *process_fd, char **env);
void	child_process(char **av,int *process_fd, char **env);

#endif