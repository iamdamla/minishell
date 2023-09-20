/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:21 by acaplat           #+#    #+#             */
/*   Updated: 2023/08/31 17:01:54 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_mini *shell)
{
	char	*cwd;
	int		i;
	t_lex	*current;

	i = 0;
	current = shell->args;
	while (i < shell->node_pos)
	{
		current = current->next;
		i++;
	}
	shell->tab = ft_split(current->str, ' ');
	if (ft_strncmp(shell->tab[0], "pwd", 4) == 0)
	{
		cwd = getcwd(NULL, 0);
		if (cwd == NULL)
		{
			perror("error current directory");
			return ;
		}
		printf("%s\n", cwd);
		free(cwd);
	}
	free_arr(shell->tab);
	shell->tab = NULL;
}
