/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:46 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:46 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	if (n <= 0)
		return (0);
	while (i < (unsigned int)n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			result = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (result);
		}
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i ++;
	}
	return (0);
}
// int main()
// {
//     char s1[] = "1234";
//     char s2[] = "1235";
//     printf("%d\n", strncmp(s1,s2, -1));
//     printf("%d", ft_strncmp(s1,s2, -1));
//     return(0);
// }