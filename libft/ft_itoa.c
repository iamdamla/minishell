/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:20:29 by derblang          #+#    #+#             */
/*   Updated: 2023/08/21 12:14:47 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_convert(char *x, unsigned int num, long int len)
{
	while (num > 0)
	{
		x[len--] = 48 + (num % 10);
		num = num / 10;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	num;
	int				sign;

	sign = 1;
	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
		str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		sign *= -1;
		num = n * -1;
		str[0] = '-';
	}
	else
	num = n;
	str = ft_convert(str, num, len);
	return (str);
}
