/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:17 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:17 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[j] = s1[i];
		j ++;
		i ++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}
