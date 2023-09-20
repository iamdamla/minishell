/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:27:26 by derblang          #+#    #+#             */
/*   Updated: 2023/08/21 12:17:23 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error_manage(int *flag)
{
	*flag = 1;
}

int	ft_atol(const char *str, int *flag)
{
	unsigned long long	res;
	int					sign;
	int					i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] && (str[i] >= 9 && str[i] <= 13)) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error_manage(flag);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res > 9223372036854775807 && sign == 1)
			|| (res > 9223372036854775807 && sign == -1))
			ft_error_manage(flag);
	}
	return (res * sign);
}
