/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:30:33 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/17 16:57:38 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sort_tab(char **tab)
{
	int	length;
	int	i;
	int	j;
	int	n;
	int	sign;

	length = find_length(tab);
	i = 0;
	j = 0;
	while (j < length - 1 && tab[i] && tab[i + 1])
	{
		while (tab[i])
		{
			if (tab[i] && tab[i + 1])
			{
				n = compare_length(tab[i], tab[i + 1]);
				sign = ft_strncmp(tab[i], tab[i + 1], n);
				if (sign > 0)
					swap_strings(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	swap_strings(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	compare_length(char *str1, char *str2)
{
	int	n1;
	int	n2;

	n1 = ft_strlen(str1);
	n2 = ft_strlen(str2);
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

void	declare_x(char **env_cpy)
{
	int		i;
	char	*str;

	i = 0;
	while (env_cpy[i])
	{
		str = env_cpy[i];
		env_cpy[i] = ft_strjoin("declare -x ", str);
		free(str);
		i++;
	}
}

void	insert_char(char **str, char c, int pos)
{
	int		length;
	char	*new_str;
	int		i;
	int		j;

	length = ft_strlen(*str);
	new_str = malloc(sizeof(char) * (length + 2));
	if (!new_str)
		norme_export();
	i = 0;
	j = 0;
	while (i < length)
	{
		if (i == pos)
		{
			new_str[j] = c;
			j++;
		}
		new_str[j] = (*str)[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	free(*str);
	*str = new_str;
}
