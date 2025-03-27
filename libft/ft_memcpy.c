/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:58 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:32:58 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destiny;
	unsigned char	*source;

	destiny = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		destiny[i] = source[i];
		i ++;
	}
	return (dst);
}
// int main()
// {
//     char src[] = "Hola mundo";
//     char dest[20];

//     ft_memcpy(dest, src, strlen(src) + 1);
//     printf("Fuente: %s\n", src);
//     printf("Destino: %s\n", dest);
//     return 0;
// }