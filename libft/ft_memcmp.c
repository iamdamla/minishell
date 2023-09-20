/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:43:23 by derblang          #+#    #+#             */
/*   Updated: 2022/11/07 09:43:54 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;	

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	i = 0;
	while ((i < n) && p[i] == q[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (p[i] - q[i]);
}

/*int main()
{
    int res = 0;
    res = ft_memcmp("abc", "abc", 2);
    printf("res: %d\n", res);
    res = ft_memcmp("bca", "abc", 2);
    printf("res: %d\n", res);
    res = ft_memcmp("abc", "bca", 2);
    printf("res: %d\n", res);
    return 0;
}*/