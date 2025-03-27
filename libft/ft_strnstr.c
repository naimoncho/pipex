/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:50 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:50 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big,	const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len && little[j])
				j ++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i ++;
	}
	return (NULL);
}
// int main() {
// 	const char *big = "Hello world, welcome!";
// 	const char *little = "yes";
// 	size_t len = 15;
// 	char *result = ft_strnstr(big, little, len);
// 	if (result) {
// 		printf("Little is: '%s'\n", result);
// 	} else {
// 		printf("little not found in limits of %zu caracters.\n", len);
// 	}
// 	return 0;
// }