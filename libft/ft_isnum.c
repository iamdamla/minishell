/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:01:04 by derblang          #+#    #+#             */
/*   Updated: 2023/08/10 14:04:16 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] == '+' || str[i] == '-')
			{
				if (flag == 1)
					return (-1);
			}
			else
				return (-1);
		}
		i++;
		flag = 1;
	}
	return (1);
}
