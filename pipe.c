/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:55:14 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/06 09:55:15 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_nb_node(t_lex *head)
{
	t_lex	*current;
	int		i;

	i = 0;
	current = head;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	do_the_pipe(t_mini *shell)
{
	int		pipe_fd[2];
	pid_t	child_pid;
	t_pipe	var;

	var.prev_pipe_read = 0;
	var.nb_node = get_nb_node(shell->args);
	var.i = -1;
	while (++var.i < var.nb_node)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe error\n");
			return ;
		}
		child_pid = fork();
		if (error_child(child_pid) == 0)
			return ;
		if (child_pid == 0)
			norme_pipe(shell, pipe_fd, var);
		else
			handle_parent(pipe_fd, var.i, &var.prev_pipe_read);
	}
	close(var.prev_pipe_read);
	ft_wait(shell, var.nb_node, child_pid);
}

void	handle_parent(int pipe_fd[2], int i, int *prev_pipe_read)
{
	close(pipe_fd[1]);
	if (i > 0)
		close(*prev_pipe_read);
	*prev_pipe_read = pipe_fd[0];
}

void	norme_pipe(t_mini *shell, int pipe_fd[2], t_pipe var)
{
	(void)shell;
	close(pipe_fd[0]);
	if (var.i > 0)
	{
		dup2(var.prev_pipe_read, STDIN_FILENO);
		close(var.prev_pipe_read);
	}
	if (var.i < var.nb_node - 1)
		dup2(pipe_fd[1], STDOUT_FILENO);
	exec_all(shell, var.i);
}

void	ft_wait(t_mini *shell, int nb_node, pid_t child_pid)
{
	int	status;
	int	i;

	(void)shell;
	i = -1;
	while (++i < nb_node)
	{
		child_pid = wait(&status);
		if (child_pid == -1)
			perror("wait");
		else
		{
			if (WIFEXITED(status))
			{
				g_error_code = WEXITSTATUS(status);
			}
		}
	}
}
