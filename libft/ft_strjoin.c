/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:46:20 by derblang          #+#    #+#             */
/*   Updated: 2022/11/07 09:51:31 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i += 1;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
		dest[i] = '\0';
	return (dest);
}
/*int main()
{
    char *a = ft_strjoin("123", "abc");
    printf("\n");
    printf("a = %s, ft_strlen(a) = %zu\n", a, ft_strlen(a));
    free(a);
}*/
