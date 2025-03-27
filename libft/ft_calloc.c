/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:13 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/14 13:32:13 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*copy;

	copy = malloc(nmemb * size);
	if (copy == NULL)
		return (NULL);
	ft_bzero(copy, nmemb * size);
	return (copy);
}
