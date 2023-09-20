/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:49:47 by derblang          #+#    #+#             */
/*   Updated: 2022/11/02 13:51:41 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i] != '\0')
	i++;
	str2 = (char *)str;
	while (i >= 0)
	{
		if (str2[i] == (unsigned char)c)
			return (&str2[i]);
		i--;
	}
	return (0);
}
/*int main(void)
{
    char s[] = "some,data,in,commas";
    char *comma = ft_strrchr(s, ',');
    //char *comma = strrchr(s, ',');
    printf("%s\n", comma);

    char *fail = ft_strrchr(s, '@');
    //char *fail = strrchr(s, '@');
    if(fail == NULL)
    printf("Could not find @!\n");
    return 0;
} */
