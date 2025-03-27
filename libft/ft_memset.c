/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:03 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:03 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = ((unsigned char *) b);
	while (i < len)
	{
		s[i] = c;
		i ++;
	}
	return (b);
}
// int main()
// {
// 	char b[6] = "";
// 	int c = 'A';
// 	ft_memset(b, c, 5);
// 	printf ("%s\n", b);
// 	return 0;
// }