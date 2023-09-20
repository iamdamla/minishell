/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:03:18 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/19 14:22:36 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_my_path(t_mini *shell)
{
	int		i;
	char	*str;

	i = 0;
	while (shell->env[i])
	{
		str = ft_substr(shell->env[i], 5, ft_strlen(shell->env[i]) - 5);
		if (ft_strncmp("PATH", shell->env[i], 4) == 0)
		{
			shell->allpath = ft_split(str, ':');
			break ;
		}
		else
		{
			free_arr(shell->allpath);
			safe_free(&str);
			i++;
		}
	}
	safe_free(&str);
}

int	verify(t_mini *shell, int j)
{
	int		i;
	t_lex	*current;
	char	*path_part;

	i = 0;
	current = find_node(j, shell);
	find_node_position(current, shell->args, shell);
	if (get_nb_node(shell->args) > 1)
		check_built_in(shell);
	if (current == NULL)
		return (0);
	if (shell->arg_bis != NULL)
		free_arr(shell->arg_bis);
	fix_cote(shell,current);
	ft_exit_code(shell->arg_bis, shell);
	while (shell->allpath[i++])
	{
		path_part = ft_strjoin(shell->allpath[i], "/");
		shell->exe = ft_strjoin(path_part, shell->arg_bis[0]);
		free(path_part);
		if (access(shell->exe, F_OK | X_OK) == 0)
			return (1);
		free(shell->exe);
	}
	return (0);
}

int	execute(t_mini *shell)
{
	if (verif_built_in(shell) == 1)
	{
		shell->flag_exit = 1;
		return (0);
	}
	if (execve(shell->exe, shell->arg_bis, shell->env) == -1)
	{
		if (shell->arg_bis[0] == NULL)
			return (0);
		if (access(shell->arg_bis[0], F_OK | X_OK) == 0)
		{
			if (ft_strncmp("./minishell", shell->arg_bis[0], 12) == 0)
				shlvl(shell);
			execve(shell->arg_bis[0], shell->arg_bis, shell->env);
		}
		if (verif_built_in(shell) == 0)
		{
			dup2(shell->stdout_cpy, STDOUT_FILENO);
			dup2(shell->stdin_cpy, STDIN_FILENO);
			printf("minishell: %s: command not found\n", shell->arg_bis[0]);
		}
	}
	return (0);
}

t_lex	*find_node(int i, t_mini *shell)
{
	int		j;
	t_lex	*current;

	current = shell->args;
	j = 0;
	while (j < i)
	{
		current = current->next;
		j++;
	}
	return (current);
}

void	exec_all(t_mini *shell, int i)
{
	get_my_path(shell);
	verify(shell, i);
	if (shell->redir_input == 0)
		execute(shell);
	if (access(shell->arg_bis[0], F_OK) != 0)
	{
		if (shell->flag_exit == 1)
			exit(0);
		else
			exit(127);
	}
}
