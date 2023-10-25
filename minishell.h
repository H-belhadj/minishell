/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:21 by omakran           #+#    #+#             */
/*   Updated: 2023/10/25 15:11:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft_/libft.h"

struct s_help
{
	int exit_status;
}s_help;

typedef struct s_cmd
{
	char	**cmd_args;
	char	**operators;
	char	**files;
	int		next_is_pipe;
	int out;
	
} t_cmd;

typedef struct Node {
    char    *key;
    char    *value;
    struct Node* next;
} Node;

typedef struct s_data_cmds 
{
	t_cmd	*cmds;
	Node	*envp;
	int		cmd_size;
} t_data_cmd;



/*#################################### Helpers Functions: #####################################*/

t_cmd	*sort_cmds(char **args, t_data_cmd *);
int		str_cmp(char *s1, char *s2);
int		count_tokens(char *line);
char 	**tokens(char *line);
char	*expand(char *str, t_data_cmd *vars);
char	**expand_all_tokens(char **tokens, t_data_cmd *vars);
void    remove_quotes(char **tokens);
void	*ft_calloc(size_t count, size_t size);
int execut_builting(t_data_cmd *vars);
void ft_exit(t_cmd *cmd);
void ft_echo(t_cmd *cmd);
void ft_pwd(t_cmd *cmd);
Node *ft_env(char **env);
void    ft_print_env(Node *envp);
void    cd(t_cmd *cmd, t_data_cmd *vars);
char *ft_getenv(char *str, t_data_cmd *vars);
Node *lst_new(char *key, char *value);
void    _free(char **array);
void    ft_unset(Node* envp, char *str);
void    export(Node* envp, char **str);
char *get_path(char *cmd, t_data_cmd *vars);
void execut_all(t_data_cmd *vars, char **env);
void execute_cmd(t_data_cmd *cmd);
Node *lst_new(char *key, char *value);
void get_env_export(Node *envp);
void lstadd_back(Node** head,Node *new_node);
void execute_compund(t_data_cmd *cmd);
/*##############################################################################################*/

#endif