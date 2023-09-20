/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:49:55 by derblang          #+#    #+#             */
/*   Updated: 2022/11/07 09:43:13 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == (unsigned char) c)
		{
			string = &string[i];
			return ((void *)string);
		}
		i++;
	}
	return (0);
}
/*int main(void)
{
    char data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
    char *pos = ft_memchr(data, 't', 7);
    printf("pos[0] = %c\n", pos[0]);
    printf("pos[1] = %c\n", pos[1]);
    return (0);
} */
