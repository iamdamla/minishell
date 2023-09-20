/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:40:18 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/13 15:10:57 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	norme_export(void)
{
	perror("Memory alloc failed\n");
	return ;
}

int	error_child(pid_t child_pid)
{
	if (child_pid == -1)
	{
		perror("fork error\n");
		return (0);
	}
	return (1);
}

int	parse_export(char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((65 <= tab[i][j] && tab[i][j] <= 90) || (91 <= tab[i][j]
			&& tab[i][j] <= 122) || tab[i][j] == '$' || tab[i][j] == '\''
		|| tab[i][j] == '\"' || ((tab[i][j] >= '0' && tab[i][j] <= '9'
		&& j > 0)) || (tab[i][j] == '+' && tab[i][j + 1] == '=' && j > 0))
	{
		return (1);
		j++;
		i++;
	}
	else
	{
		printf("minishell: export: `%s': not a valid identifier\n", tab[i]);
		return (0);
	}
	return (1);
}

void	check_flag_ter(t_lex *current, t_mini *shell)
{
	int	i;

	i = 0;
	while (current->str[i])
	{
		if (current->str[i] == '\"' && shell->flag == 0)
			shell->flag = 2;
		else if (current->str[i] == '\"' && shell->flag == 2)
			shell->flag = 0;
		else if (current->str[i] == '\'' && shell->flag == 0)
			shell->flag = 1;
		else if (current->str[i] == '\'' && shell->flag == 1)
			shell->flag = 0;
		i++;
	}
}
