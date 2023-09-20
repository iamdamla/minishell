/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:33:42 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/20 10:46:31 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n(char **compare)
{
	int	i;
	int	j;

	i = 0;
	while (compare[++i])
	{
		j = 0;
		if (compare[i][j++] == '-' && compare[i][j] && compare[i][j] == 'n')
		{
			while (compare[i][j] == 'n')
				j++;
			if (compare[i][j] && compare[i][j] != 'n' && compare[i][j
				+ 1] != '\0')
				return (i);
			if (compare[i][j] && compare[i][j] != 'n')
				return (1);
		}
		else
			return (i);
	}
	return (i);
}

void	echo(char **compare, t_mini *shell)
{
	int	i;
	int	j;
	int	k;
	int	flag;

	k = 0;
	i = check_n(compare);
	j = find_length(compare);
	flag = i;
	ft_exit_code(compare, shell);
	while (compare[i])
	{
		echo_norme(i, k, compare);
		if (i < j - 1)
			ft_putchar_fd(' ', 1);
		i++;
		k = 0;
	}
	if (flag == 1)
		ft_putchar_fd('\n', 1);
}

void	exec_echo(t_mini *shell)
{
	t_lex	*current;
	int		i;

	i = 0;
	current = shell->echo_lst;
	while (i < shell->node_pos)
	{
		current = current->next;
		i++;
	}
	shell->tab = ft_split(current->str, 31);
	if (ft_strncmp(shell->tab[0], "echo", 5) == 0)
		echo(shell->tab, shell);
	free_arr(shell->tab);
	shell->tab = NULL;
}

int	echo_help(char *compare, int k, char cote)
{
	int	i;
	int	j;

	i = 0;
	j = k;
	k++;
	while (compare[k] && compare[k] != cote)
	{
		ft_putchar_fd(compare[k], 1);
		k++;
	}
	k++;
	return (k - j);
}

void	echo_norme(int i, int k, char **compare)
{
	if (compare[i])
	{
		while (compare[i][k])
		{
			if (compare[i][k] == '\'')
			{
				k += echo_help(compare[i], k, '\'');
				if (compare[i][k] == '\'')
					continue ;
			}
			if (compare[i][k] == '\"')
			{
				k += echo_help(compare[i], k, '\"');
				if (compare[i][k] == '\"')
					continue ;
			}
			if (compare[i][k])
			{
				ft_putchar_fd(compare[i][k], 1);
				k++;
			}
		}
	}
}
