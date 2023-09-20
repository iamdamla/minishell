/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:04:00 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/19 14:15:32 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize(char **env, t_mini *shell)
{
	shell->flag = 0;
	shell->lst_bis = NULL;
	shell->newline_bis = NULL;
	shell->echo_lst = NULL;
	shell->command = NULL;
	shell->env = env;
	shell->line = NULL;
	shell->simple_command = NULL;
	shell->newline = NULL;
	shell->length_command = 0;
	shell->lst = NULL;
	shell->simplecommand = NULL;
	shell->args = NULL;
	shell->env_cpy = NULL;
	shell->tab = NULL;
	shell->allpath = NULL;
	shell->arg_bis = NULL;
	shell->exe = NULL;
	shell->stdin_cpy = dup(STDIN_FILENO);
	shell->stdout_cpy = dup(STDOUT_FILENO);
	shell->redir_input = 0;
	shell->node_pos = 0;
	shell->flag_cote = 0;
	shell->flag_exit = 0;
}

char	*add_char(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	safe_free(&str);
	return (newstr);
}

int	find_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

void	lex_norme(t_lex *current, t_lex *newlist, t_mini *shell, char *test)
{
	if (current->next && ft_strncmp(current->next->str, "|", 2) == 0
		&& shell->flag == 0)
	{
		add_element_bis(&newlist, ft_strdup(test));
		current = current->next;
	}
}
