/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:21:30 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/21 22:21:30 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(int n, int fd)
{
	char	character_n;
	int		number;

	number = n;
	if ((number / 10) != 0)
	{
		ft_recursive(number / 10, fd);
	}
	character_n = 48 + (n % 10);
	write(fd, &character_n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_recursive(-n, fd);
	}
	else
	{
		ft_recursive(n, fd);
	}
}
// int main()
// {
//     ft_putnbr_fd(12233);
//     ft_putnbr_fd(5603);
//     ft_putnbr_fd(-560);
//     ft_putnbr_fd(0);
//     ft_putnbr_fd(-2147483648);
//     return 0;
// }