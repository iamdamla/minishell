/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:30 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/17 17:22:25 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(t_mini *shell)
{
	int		i;
	int		length;
	int		res;
	int		res_bis;
	t_lex	*current;

	current = shell->args;
	i = 1;
	while (current)
	{
		shell->tab = ft_split(current->str, ' ');
		length = find_length(shell->tab);
		if (ft_strncmp(shell->tab[0], "unset", 6) == 0 && length > 1)
		{
			while (shell->tab[i])
			{
				res = check_dup_env(shell->env, shell->tab[i]);
				res_bis = check_dup(shell->env_cpy, shell->tab[i]);
				unset_helper(shell, res, res_bis);
				i++;
			}
		}
		unset_helper_helper(shell);
		current = current->next;
	}
}

void	unset_helper_helper(t_mini *shell)
{
	free_arr(shell->tab);
	shell->tab = NULL;
}

void	unset_helper(t_mini *shell, int res, int res_bis)
{
	if (res >= 0)
		remove_str_from_tab(shell, &shell->env, res);
	if (res_bis >= 0)
		remove_str_from_tab(shell, &shell->env_cpy, res_bis);
}
