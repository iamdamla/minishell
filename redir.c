/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:02:07 by acaplat           #+#    #+#             */
/*   Updated: 2023/08/26 16:44:16 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_output_append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("open error");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("open error");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_input(char *file, t_mini *shell)
{
	int	fd;

	(void)shell;
	if (access(file, F_OK) == -1)
	{	
		printf("minishell: %s: No such file or directory\n", file);
		shell->redir_input = 1;
		return ;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	else
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			close(fd);
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
}
