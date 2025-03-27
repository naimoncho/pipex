/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:19 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:19 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;

	i = 0;
	d_len = 0;
	while (dest[d_len] != '\0')
	{
		d_len ++;
	}
	if (size <= d_len)
		return (ft_strlen(src) + size);
	while (src[i] && (d_len + i + 1) < size)
	{
		dest[d_len + i] = src[i];
		i ++;
	}
	dest[d_len + i] = '\0';
	return (ft_strlen(src) + d_len);
}
// int main()
// {
// 	char dest[20] = "hola";
// 	char src[] = "adios";
// 	printf("%d\n", ft_strlcat(dest, src, 7));
// 	printf("%s\n", dest);
// }