/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:07:55 by derblang          #+#    #+#             */
/*   Updated: 2022/11/02 14:12:48 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *) dst;
	ptr2 = (unsigned char *) src;
	i = 0;
	if (ptr == NULL && ptr2 == NULL)
		return (NULL);
	if (ptr2 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
				*(ptr++) = *(ptr2++);
	return (dst);
}
/*int main()
{
    int source[10] = {1,2,3,4,5,6,7,8,9,10};
    int destination[10];

    //memmove(source+2, source, sizeof(int) * 8);
    ft_memmove(destination, source, sizeof(int) * 10);
    for(int i = 0; i < 10; i++)
        printf("destination[%d]=%d\n", i, destination[i]);

    for(int i = 0; i < 10; i++)
        printf("source[%d]=%d\n", i, source[i]);
    
    return 0;
}*/
