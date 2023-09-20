/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:35:34 by derblang          #+#    #+#             */
/*   Updated: 2022/11/07 09:45:03 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)str;
	i = 0;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (str);
}
/*int main(void)
{
    char b[10] = "hello";
  //memset(b, 'd', sizeof(char) * 3);
  ft_memset(b, 'd', sizeof(char) * 3);

    for(int i = 0; i < 6; i++)
    printf("%c", b[i]);
    printf("\n");
}*/
