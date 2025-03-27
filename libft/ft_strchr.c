/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:11 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:11 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char *)&s[i]);
		i ++;
	}
	if (to_find == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
// int main()
// {
//     const char *s = "Hello, world!";
//     printf("Result (search 'o'): %s\n", ft_strchr(s, 'o'));
//     printf("Result (search 'x'): %s\n", ft_strchr(s, 'x'));
// 	printf("Result (search '\\0'): %s\n", ft_strchr(s, '\0'));
//     return 0;
// }