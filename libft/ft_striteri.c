/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:36 by derblang          #+#    #+#             */
/*   Updated: 2022/11/18 15:57:00 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void my_func(unsigned int i, char *str)
{
    printf("My inner function: index = %d and the string is %s\n", i, str);
}

int main()
{
    char str[10] = "hello";
    printf("The result is %s\n", str);
    ft_striteri(str, my_func);
    printf("The result is %s\n", str);
    return 0;
}*/
