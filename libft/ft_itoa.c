/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:38 by ncheniou          #+#    #+#             */
/*   Updated: 2025/01/25 18:30:40 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennumber(long int num)
{
	int	c;

	c = 0;
	if (num == 0)
		c ++;
	if (num < 0)
	{
		num = num * -1;
		c ++;
	}
	while (num > 0)
	{
		num = num / 10;
		c ++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		i;

	number = n;
	i = lennumber(number);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		str[i--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
// int main()
// {
//     int n = -12345;
//     char *str = ft_itoa(n);
//     if (str) {
//         printf("El número como cadena: %s\n", str);
//         free(str);
//     } else {
//         printf("Error al convertir el número.\n");
//     }
//     return 0;
// }