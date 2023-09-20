/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_custom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:14:38 by acaplat           #+#    #+#             */
/*   Updated: 2023/08/29 14:31:41 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_flag_4(char *line, t_mini *shell, int i)
{
	if (line[i] == '\"' && shell->flag == 0)
		shell->flag = 2;
	else if (line[i] == '\"' && shell->flag == 2)
		shell->flag = 0;
	else if (line[i] == '\'' && shell->flag == 0)
		shell->flag = 1;
	else if (line[i] == '\'' && shell->flag == 1)
		shell->flag = 0;
	i++;
}

void	replace_char(char *str, char target, char replacement, t_mini *shell)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		check_flag_4(str, shell, i);
		if (str[i] == target && shell->flag == 0)
			str[i] = replacement;
		i++;
	}
}

void	delete_char(char *str, char tg1, char tg2, int pos)
{
	int	len;
	int	ind_l;
	int	ind_e;
	int	inside_double_quotes;

	inside_double_quotes = 0;
	(void)pos;
	ind_l = 0;
	ind_e = 0;
	len = ft_strlen(str);
	while (ind_l < len)
	{
		if (str[ind_l] == tg2)
			inside_double_quotes = !inside_double_quotes;
		if (((str[ind_l] != tg1 || inside_double_quotes)) && str[ind_l] != tg2)
		{
			str[ind_e] = str[ind_l];
			ind_e++;
		}
		ind_l++;
	}
	str[ind_e] = '\0';
}
