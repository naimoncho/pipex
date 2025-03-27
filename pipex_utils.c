/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:19:51 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/27 16:24:22 by ncheniou         ###   ########.fr       */
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