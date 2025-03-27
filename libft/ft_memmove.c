/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:01 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:01 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*destiny;
	unsigned char	*source;

	destiny = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (destiny > source && destiny < source + len)
	{
		while (len--)
			destiny[len] = source[len];
	}
	else if (dst || src)
	{
		while (i < len)
		{
			destiny[i] = source[i];
			i ++;
		}
	}
	return (dst);
}
// int main()
// {
// 	char *src = NULL;
// 	char *dst = NULL;
// 	char *dst1 = NULL;
// 	ft_memmove(dst, src, 5);
// 	printf("mi ft_memmove: [%s]\n", dst);
// 	memmove(dst1, src, 5);
// 	printf("la ft_memmove normal: [%s]\n", dst1);
// 	return 0;
// }