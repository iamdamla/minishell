/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:23:41 by derblang          #+#    #+#             */
/*   Updated: 2022/11/08 15:24:29 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
		i = 0;
		n = 0;
	while (s[i])
	{
		if (i >= start && n < len)
		{
			str[n] = s[i];
			n++;
		}
	i++;
	}
		str[n] = '\0';
	return (str);
}*/

//works
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
		tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}
/*int main()
{
    char src[] = "hello, how are you?";
    int start = 2;
    int len = 12;

    char *dest = ft_substr(src, start, len);
    printf("%s\n", dest);
    return 0;
}*/
