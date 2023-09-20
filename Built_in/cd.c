/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:59:11 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/17 16:54:00 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd(t_mini *shell)
{
	t_lex	*current;
	int		i;

	i = 0;
	current = shell->args;
	while (i < shell->node_pos)
	{
		current = current->next;
		i++;
	}
	shell->tab = ft_split(current->str, ' ');
	if (ft_strncmp(shell->tab[0], "cd", 3) == 0 && shell->tab[1])
		change_directory(shell->tab[1], shell);
	free_arr(shell->tab);
	shell->tab = NULL;
}

void	change_env(char *cwd, t_mini *shell)
{
	char	*pwd;
	char	*oldpwd;

	oldpwd = ft_strjoin("OLDPWD=", cwd);
	cwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", cwd);
	add_var_export(pwd, shell);
	add_var_export(oldpwd, shell);
	add_var_env(pwd, shell);
	add_var_env(oldpwd, shell);
	free(pwd);
	free(oldpwd);
	free(cwd);
}

void	change_directory(char *dir, t_mini *shell)
{
	char	*cwd;
	char	*path;

	cwd = getcwd(NULL, 0);
	path = "";
	if (cwd == NULL)
	{
		perror("error current directory");
		return ;
	}
	too_much_line(&dir, &path, &cwd);
	if (chdir(path) == 0)
		change_env(cwd, shell);
	else
		perror("dir not found");
	free(cwd);
	free(path);
}

void	too_much_line(char **dir, char **path, char **cwd)
{
	if (*dir[0] == '/')
		*path = ft_strjoin(*path, *dir);
	else if (ft_strncmp(*dir, "~", 2) == 0)
		*path = ft_strjoin(getenv("HOME"), "");
	else
	{
		*path = ft_strjoin(*path, *cwd);
		*path = ft_strjoin(*path, "/");
		*path = ft_strjoin(*path, *dir);
	}
}
