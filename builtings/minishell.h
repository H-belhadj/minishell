/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:04:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 17:04:09 by hbelhadj         ###   ########.fr       */
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
void execut(t_data_cmd *vars);
int		str_cmp(char *s1, char *s2);
int		count_tokens(char *line);
char 	**tokens(char *line);
char	*expand(char *);
char	**expand_all_tokens(char **tokens);
void    remove_quotes(char **tokens);
void	*ft_calloc(size_t count, size_t size);
void ft_exit(t_cmd *cmd);
void ft_echo(t_cmd *cmd);
void ft_pwd(t_cmd *cmd);
Node *ft_env(char **env);
void    ft_print_env(Node *envp);


/*##############################################################################################*/

#endif