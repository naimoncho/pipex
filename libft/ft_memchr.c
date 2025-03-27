/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:48 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:32:48 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*str;

	find = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return (str + i);
		i ++;
	}
	if (find == '\0')
		return (0);
	return (NULL);
}
// int main()
// {
//     char str[] = "Hello, world!";
//     printf("Search 'o': %s\n", (char *)ft_memchr(str, 'o', 10));
//     printf("Search 'x': %s\n", (char *)ft_memchr(str, 'x', 10));
//     printf("Search '\\0': %s\n", (char *)ft_memchr(str, '\0', sizeof(str)));
//     return 0;
// }