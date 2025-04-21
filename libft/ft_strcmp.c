/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:35 by ncheniou          #+#    #+#             */
/*   Updated: 2025/04/21 13:15:22 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	return (0);
}

// int main()
// {
//     char s1[] = "Miau Miau";
//     char s2[] = "Miao Miao";
//     printf("%d\n", strcmp(s1,s2));
//     printf("%d", ft_strcmp(s1,s2));
//     return(0);
// }
