/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:54:34 by derblang          #+#    #+#             */
/*   Updated: 2022/11/07 14:19:50 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ischar(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
		if (*(set + i++) == c)
			return (1);
	return (0);
}

char	*trimming(const char *s1, const char *set, size_t *k, size_t i)
{
	size_t	j;
	size_t	len;
	char	*dest;

	j = 0;
	len = ft_strlen(s1);
	while (ischar(*(s1 + len - j - 1), set))
		j++;
		dest = ft_calloc(sizeof(char), len - (j + i) + 1);
	if (!dest)
		return (0);
	while (*k < len - (j + i))
	{
		*(dest + *k) = *(s1 + i + *k);
		*k += 1;
	}
	return (dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ischar(*(s1 + i), set))
			i++;
		k = 0;
	if (i == len)
		dest = malloc(1);
	else
		dest = trimming(s1, set, &k, i);
	if (dest != NULL)
		*(dest + k) = '\0';
	return (dest);
}
/*int main()
{
	char s[30] = "...This is string...";
	char set[10] = ".";
	printf("The result is %s\n", s);
	char *result = ft_strtrim(s, set);
	printf("The result is %s\n", result);

	return 0;
}*/
