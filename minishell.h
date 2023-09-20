/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:50:26 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/18 17:06:02 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

int					g_error_code;

typedef struct s_elem
{
	char			data;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct s_lex
{
	char			*str;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

typedef struct s_mini
{
	t_elem			*lst_bis;
	char			*newline_bis;
	t_lex			*echo_lst;
	char			*line;
	char			*newline;
	char			**env;
	int				flag;
	char			**command;
	int				length_command;
	char			*add_char;
	t_elem			*lst;
	char			**simple_command;
	t_lex			*simplecommand;
	t_lex			*args;
	char			**env_cpy;
	char			**tab;
	char			**allpath;
	char			**arg_bis;
	char			*exe;
	int				stdout_cpy;
	int				stdin_cpy;
	int				redir_input;
	int				node_pos;
	int				flag_cote;
	int				flag_exit;
	struct termios	attr;
	int				term;
}					t_mini;

typedef struct s_compteur
{
	int				i;
	int				j;
	int				length;
}					t_compteur;

typedef struct s_pipe
{
	int				nb_node;
	int				prev_pipe_read;
	int				i;
}					t_pipe;

typedef struct s_here
{
	int				fd;
	char			*del;
	t_lex			*current;
	t_lex			*next;
}					t_here;

typedef struct s_redir
{
	t_lex			*current;
	t_lex			*next;
	char			*redir;
}					t_redir;

typedef struct s_exp
{
	int				length;
	int				i;
	char			*cpy;
	t_lex			*current;
}					t_exp;

//Main

void				minishell_loop(t_mini *shell);
void				norme_main(t_mini *shell);
void				parse_newline_bis(t_mini *shell, char *str);
void				main_ter(t_mini *shell, char *str, int *i);

//Utils

void				initialize(char **env, t_mini *shell);
char				*add_char(char *str, char c);
int					find_length(char **str);
void				print_tab(char **tab);
void				lex_norme(t_lex *current, t_lex *newlist, t_mini *shell,
						char *test);

//Utils_bis

char				*ft_strjoin_bis(char *s1, char *s2);
void				fix_cote(t_mini *shell, t_lex *current);
void				main_line(t_mini *shell);
int					return_node_position(t_lex **head, t_lex *target);

//Signal

void				handle_sigint(int signal);
void				handle_sigquit(int signal);
void				do_signal(t_mini *shell);

//Parsing

int					count_quotes(char *line, t_mini *shell);
int					find_matching_quote(char *line, int i, int *nb_del,
						int del);
t_elem				*get_my_list(t_mini *shell);
void				separate_command(t_elem *lst);
t_elem				*get_my_list(t_mini *shell);

//Dollar

void				replace_line(char *line, t_mini *shell);
void				set_flag(char *line, t_mini *shell, int i);
char				*compare_line(char *line, int i);
int					compare_with_env(char *compare, t_mini *shell);
void				norme_dollar(t_compteur *var, t_mini *shell);

//Linked_list

void				add_element(t_elem **head, char data);
void				printlist(t_elem *head);
t_elem				*create_elem(char data);
void				insert_after(t_elem *lst, char newdata);
void				processlist(t_elem *head, char targetchar, char newdata);

//Linked_list_bis1

void				processlist_chevron(t_elem *head, char targetchar,
						char newdata);
char				*convert_to_str(t_elem *head);
void				delete_node(t_lex **head, t_lex *node_to_del);

//Free

void				free_shell(t_mini *shell);
void				free_arr(char **arr);
void				free_list(t_elem *head);
void				free_list_bis(t_lex *head);
void				safe_free(char **str);

//Lex

void				add_element_bis(t_lex **head, char *simple_command);
void				printlist_bis(t_lex *head);
t_lex				*get_my_element(t_mini *shell);
t_lex				*set_command(t_lex *head, t_mini *shell);
void				check_flag_bis(t_lex *current, t_mini *shell);

// Parse_redir

void				do_redir(t_mini *shell);
void				do_redir_output(t_mini *shell);
void				do_redir_input(t_mini *shell);
void				redir(t_mini *shell);
void				norme_parse_redir(char *redir);

//Redir

void				redir_output_append(char *file);
void				redir_output(char *file);
void				redir_input(char *file, t_mini *shell);

//Heredoc

void				here_doc(t_lex *simplecommand, t_mini *shell);
int					too_much(int fd, char *del);
void				too_much_bis(int fd);
void				norme_heredoc_bis(void);
void				erase(t_lex **simplecommand, t_mini *shell);

//Pipe

int					get_nb_node(t_lex *head);
void				do_the_pipe(t_mini *shell);
void				ft_wait(t_mini *shell, int nb_node, pid_t child_pid);
void				handle_parent(int pipe_fd[2], int i, int *prev_pipe_read);
void				norme_pipe(t_mini *shell, int pipe_fd[2], t_pipe var);
int					error_child(pid_t child_pid);

//Exec

void				get_my_path(t_mini *shell);
int					verify(t_mini *shell, int j);
int					execute(t_mini *shell);
t_lex				*find_node(int i, t_mini *shell);
void				exec_all(t_mini *shell, int i);

//Exit_code

void				ft_exit_code(char **tab, t_mini *shell);

//Norme

void				norme_export(void);
int					parse_export(char **tab);
void				check_flag_ter(t_lex *current, t_mini *shell);

//Fix_echo

void				fix_echo(t_mini *shell);
t_lex				*echo_list(t_mini *shell);

//Split_custom

void				delete_char(char *str, char tg1, char tg2, int pos);
void				check_flag_4(char *line, t_mini *shell, int i);
void				replace_char(char *str, char target, char replacement,
						t_mini *shell);

// BUILT-IN

// Env

void				print_env(t_mini *shell);
void				env_cpy(t_mini *shell);
void				shlvl(t_mini *shell);

// Export

void				sort_tab(char **tab);
void				swap_strings(char **str1, char **str2);
int					compare_length(char *str1, char *str2);
void				declare_x(char **env_cpy);
void				insert_char(char **str, char c, int pos);
char				*insert_char_bis(char **str, char c, int pos);

//Export_bis

int					find_character(char *str, char c);
void				add_quotes(char **env_cpy);
char				**do_export(t_mini *shell);
void				add_var_export(char *str, t_mini *shell);
void				export(t_mini *shell);

//Add_var_export

char				**add_str_to_tab(t_mini *shell, char **tab, char *str);
void				remove_str_from_tab(t_mini *shell, char ***tab,
						int position);
int					check_dup(char **tab, char *compare);
int					check_dup_env(char **tab, char *compare);
void				add_var_env(char *str, t_mini *shell);

// Unset

void				unset(t_mini *shell);
void				unset_helper_helper(t_mini *shell);
void				unset_helper(t_mini *shell, int res, int res_bis);

//Cd

void				change_env(char *cwd, t_mini *shell);
void				change_directory(char *dir, t_mini *shell);
void				too_much_line(char **dir, char **path, char **cwd);
void				cd(t_mini *shell);

//Pwd

void				pwd(t_mini *shell);

//Echo

int					check_n(char **compare);
void				echo(char **compare, t_mini *shell);
void				exec_echo(t_mini *shell);
int					echo_help(char *compare, int k, char cote);
void				echo_norme(int i, int k, char **compare);

//Exit

void				ft_exit(t_mini *shell);
void				exec_exit(char **tab, t_mini *shell);
int					ft_is_digit_str(const char *str);
void				norme_exit(char **tab, t_mini *shell);

//Check_built_in

void				check_built_in(t_mini *shell);
int					verif_built_in(t_mini *shell);
void				norme_export_bis(t_mini *shell, char *cpy);
void				find_node_position(t_lex *target, t_lex *head,
						t_mini *shell);
t_exp				norme_export_ter(t_mini *shell);

#endif