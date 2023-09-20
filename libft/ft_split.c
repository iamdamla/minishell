/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:43:32 by derblang          #+#    #+#             */
/*   Updated: 2023/09/11 11:07:00 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**freeall(char **liste, int n);

size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w += 1;
		while (s[i] != c && s[i + 1])
		i += 1;
		i += 1;
	}
	return (w);
}

size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
	i++;
	while (s[i] != c && s[i++])
	len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**w;

	i = 0;
	k = 0;
	w = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!s || !w)
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		w[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&s[k], c) + 1));
		if (!(w[i]))
			return (freeall(w, i));
		j = 0;
		while (s[k] == c)
		k++;
		while (s[k] != c && s[k])
		w[i][j++] = s[k++];
		w[i][j] = '\0';
		i++;
	}
	w[i] = NULL;
	return (w);
}

char	**freeall(char **liste, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(liste[i]);
		i++;
	}
	free(liste);
	return (NULL);
}
// int main(void)
// {
//     char **split;
// 	char c = ' ,';
//     char s[100] = "To be or not to be, that is the question.";
//     split = ft_split(s, c);
//     int i = 0;
//     while(split[i])
//     {
//         printf("%s\n", split[i]);
//         i++;
//     }
//     return 0;
// }
