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

void	ft_errors(void);
void	ft_exit(void);
void	ft_openfd_infile(int *fd, char *cmd1);

#endif