/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:06:42 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/19 10:23:32 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i += 1;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	safe_free(&s1);
	return (dest);
}

void	main_line(t_mini *shell)
{
	dup2(shell->stdout_cpy, STDOUT_FILENO);
	dup2(shell->stdin_cpy, STDIN_FILENO);
	shell->redir_input = 0;
	shell->flag_cote = 0;
	free_shell(shell);
}

void	fix_cote(t_mini *shell, t_lex *current)
{
	int		i;
	char	*newstr;

	newstr = ft_calloc(1, 1);
	i = 0;
	replace_char(current->str, ' ', 31, shell);
	while (current->str[i])
	{
		if (current->str[i] == '\'' || current->str[i] == '\"')
			i++;
		newstr = add_char(newstr, current->str[i]);
		i++;
	}
	free(current->str);
	current->str = newstr;
	shell->arg_bis = ft_split(current->str, 31);
}

int	return_node_position(t_lex **head, t_lex *target)
{
	t_lex	*current;
	int		i;

	i = 1;
	current = *head;
	while (current != target)
	{
		current = current->next;
		i++;
	}
	return(i);
}