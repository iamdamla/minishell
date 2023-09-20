/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:47:16 by derblang          #+#    #+#             */
/*   Updated: 2022/11/08 15:26:15 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str++)
			return (0);
	}
	return ((char *)str);
}

/*int main()
{
    char *str = "This Z is MY string!";
    char *first_M = strchr(str, 'Z');
    printf("first_M: %s\n", first_M);
    char *first_Z = ft_strchr(str, 'Z');
    if(first_Z == NULL)
    printf("No 'Z' found");
    return 0;
}*/
