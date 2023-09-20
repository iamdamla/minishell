/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:36:57 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/19 15:06:13 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_mini	shell;

	(void)argv;
	g_error_code = 0;
	if (argc != 1)
	{
		printf("retry without arguments\n");
		exit(0);
	}
	initialize(env, &shell);
	shell.env_cpy = do_export(&shell);
	rl_catch_signals = 0;
	do_signal(&shell);
	shell.term = dup(STDIN_FILENO);
	tcgetattr(shell.term, &shell.attr);
	minishell_loop(&shell);
}

void	minishell_loop(t_mini *shell)
{
	while (1)
	{
		tcsetattr(shell->term, 0, &shell->attr);
		shell->line = readline(">>");
		if (shell->line)
		{
			if (ft_strlen(shell->line) > 0)
				add_history(shell->line);
			if (count_quotes(shell->line, shell) == 1)
			{
				norme_main(shell);
				if (shell->args != NULL)
					do_the_pipe(shell);
			}
			do_signal(shell);
			main_line(shell);
		}
		else
		{
			free_arr(shell->env_cpy);
			exit(0);
		}
	}
}

void	norme_main(t_mini *shell)
{
	shell->add_char = ft_calloc(1, 2);
	replace_line(shell->line, shell);
	shell->lst = get_my_list(shell);
	shell->lst_bis = get_my_list(shell);
	shell->newline_bis = convert_to_str(shell->lst_bis);
	separate_command(shell->lst);
	shell->newline = convert_to_str(shell->lst);
	shell->simplecommand = get_my_element(shell);
	here_doc(shell->simplecommand, shell);
	erase(&shell->simplecommand, shell);
	redir(shell);
	shell->args = set_command(shell->simplecommand, shell);
	if (shell->flag_cote == 0)
		if (shell->newline_bis != NULL)
			parse_newline_bis(shell, shell->newline_bis);
	fix_echo(shell);
	if (get_nb_node(shell->args) == 1)
		check_built_in(shell);
}

void	parse_newline_bis(t_mini *shell, char *str)
{
	int		i;
	char	*newstr;

	(void)shell;
	i = 0;
	if (!str || ft_strlen(str) == 0)
		return ;
	newstr = ft_calloc(1, 2);
	while (str[i])
	{
		check_flag_4(str, shell, i);
		if (str[i] == ' ' && (str[i + 1] == '<' || str[i + 1] == '<')
			&& shell->flag == 0)
			i++;
		main_ter(shell, str, &i);
		newstr = add_char(newstr, str[i]);
		i++;
	}
	safe_free(&shell->newline_bis);
	shell->newline_bis = newstr;
}

void	main_ter(t_mini *shell, char *str, int *i)
{
	if ((str[*i] == '<' || str[*i] == '>') && shell->flag == 0)
	{
		(*i)++;
		if (str[*i] == '<' || str[*i] == '>')
			(*i)++;
		if (str[*i] != ' ')
			while (str[*i] != ' ' && str[*i])
				(*i)++;
		else if (str[*i] == ' ')
		{
			while (str[*i] == ' ' && str[*i])
			{
				check_flag_4(str, shell, *i);
				(*i)++;
			}
			while (str[*i] != ' ' && str[*i])
			{
				check_flag_4(str, shell, *i);
				(*i)++;
			}
		}
	}
}
