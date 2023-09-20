/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:32:31 by derblang          #+#    #+#             */
/*   Updated: 2022/11/14 14:46:12 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (!dest && !src)
		return (0);
	char_dest = (unsigned char *) dest;
	char_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    char src[] = "copy this";
    char dest[100];

    char *dest_ptr = ft_memcpy(dest, src, strlen(src) + 1);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);

    printf("dest: %p\n", dest);
    printf("dest_ptr: %p\n", dest_ptr);
    return 0;
} */
