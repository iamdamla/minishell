/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:58:47 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/18 15:34:37 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_built_in(t_mini *shell)
{
	if (shell->flag_cote == 0)
	{
		if (shell->newline_bis != NULL && shell->echo_lst != NULL)
			export(shell);
		if (shell->newline_bis != NULL && shell->echo_lst != NULL)
			exec_echo(shell);
		cd(shell);
		unset(shell);
		print_env(shell);
		pwd(shell);
		ft_exit(shell);
	}
}

int	verif_built_in(t_mini *shell)
{
	if (ft_strncmp("export", shell->arg_bis[0], 7) == 0 || ft_strncmp("cd",
			shell->arg_bis[0], 3) == 0 || ft_strncmp("echo", shell->arg_bis[0],
			5) == 0 || ft_strncmp("pwd", shell->arg_bis[0], 4) == 0
		|| ft_strncmp("unset", shell->arg_bis[0], 6) == 0 || ft_strncmp("env",
			shell->arg_bis[0], 4) == 0 || ft_strncmp("exit", shell->arg_bis[0],
			5) == 0)
		return (1);
	else
		return (0);
}

void	norme_export_bis(t_mini *shell, char *cpy)
{
	free_arr(shell->tab);
	cpy = NULL;
	shell->tab = NULL;
}

void	find_node_position(t_lex *target, t_lex *head, t_mini *shell)
{
	t_lex	*current;
	int		i;

	i = 0;
	current = head;
	while (current != target)
	{
		current = current->next;
		i++;
	}
	shell->node_pos = i;
}

t_exp	norme_export_ter(t_mini *shell)
{
	t_exp	var;
	int		j;

	j = 0;
	var.current = shell->echo_lst;
	var.i = 1;
	while (j < shell->node_pos)
	{
		var.current = var.current->next;
		j++;
	}
	if(var.current->str != NULL)
		var.cpy = ft_strdup(var.current->str);
	replace_char(var.cpy, ' ', 31, shell);
	shell->tab = ft_split(var.cpy, 31);
	var.length = find_length(shell->tab);
	return (var);
}
