/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:39 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/19 15:04:06 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fix_echo(t_mini *shell)
{
	t_lex	*newlist;

	newlist = NULL;
	replace_char(shell->newline_bis, ' ', 31, shell);
	if (shell->newline_bis != NULL)
		newlist = echo_list(shell);
}

t_lex	*echo_list(t_mini *shell)
{
	int		i;
	char	*str;
	t_lex	*newlist;

	newlist = NULL;
	i = -1;
	str = ft_calloc(1, 1);
	while (shell->newline_bis[++i])
	{
		check_flag_4(shell->newline_bis, shell, i);
		str = add_char(str, shell->newline_bis[i]);
		if ((shell->newline_bis[i + 1] == '|' && shell->flag == 0
				&& shell->newline_bis[i + 1]) || (shell->newline_bis[i
					+ 1] == '\0' && shell->flag == 0))
		{
			add_element_bis(&newlist, str);
			str = ft_calloc(1, 1);
			i++;
		}
	}
	safe_free(&str);
	shell->echo_lst = newlist;
	return (newlist);
}
