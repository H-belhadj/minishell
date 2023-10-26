/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:18 by omakran           #+#    #+#             */
/*   Updated: 2023/10/26 12:14:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_tokens(char **tokens)
{
	int i = 0;
	while (tokens[i]) {
		printf("TOKEN => %s\n", tokens[i]);
		i++;
	}
}

void print_table_cmds(t_data_cmd *vars) {
	int i = 0;
	int c = 0;
	while (i < vars->cmd_size) {
		c = 0;
		printf("\n_____________________CMD [%d]_______________________\n", i);
		while (vars->cmds[i].cmd_args[c]) {
			printf("ARG[%d] => %s\n", c, vars->cmds[i].cmd_args[c]);
			c++;
		}
		c = 0;
		while (vars->cmds[i].operators[c]) {
			printf("OPERATOR[%d] => %s\nFILE[%d] => %s\n", c, vars->cmds[i].operators[c], c,  vars->cmds[i].files[c]);
			c++;
		}
		i++;
	}
}


int	main(int __unused argc, char __unused **argv, char	**envp)
{
	t_data_cmd	*vars;
	char		*line;
	char   		**_tokens;

	vars = malloc(sizeof(t_data_cmd));
	if (!vars)
		exit (1);
	vars->envp = ft_env(envp); //you need to add this
	while (1)
	{
		line = readline("minishell > ");
		if (!line)
			return (0);
		add_history(line);
		_tokens = tokens(line);
		_tokens = expand_all_tokens (_tokens, vars);
		remove_quotes(_tokens);
	// 	//handl errors
		vars->cmds = sort_cmds(_tokens, vars);
		// printf("%s", vars->cmds->operators);
		execut_all(vars, envp);
		// print_table_cmds(vars);
	}
	return (0);
}
