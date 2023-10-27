/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:47:38 by omakran           #+#    #+#             */
/*   Updated: 2023/10/27 11:39:40 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_cmds(char **tokens)
{
	int	i;
	int	count_cmds;

	i = 0;
	count_cmds = 0;
	while (tokens[i])
	{
		if (tokens[i + 1] && (ft_strncmp(tokens[i + 1], "|", ft_strlen(tokens[i + 1])) == 0))
			count_cmds++;
		else if (!tokens[i + 1])
			count_cmds++;
		i++;
	}
	return (count_cmds);
}

int is_redirection(char *str)
{
	if (str_cmp(str, ">") || str_cmp(str, ">>") || str_cmp(str, "<<") || str_cmp(str, "<"))
		return (1);
	return (0);
}


char	**fill_commads(char **dst, char **tokens, int start, int end) 
{
	int	i;

	i = 0;
	while (tokens[start] && start < end)
	{
		if (start == 0  || ((start - 1 >= 0 && !is_redirection(tokens[start - 1])) && !is_redirection(tokens[start])))
		{
			if (start == 0 && !is_redirection(tokens[start]))
			{
				dst[i] = tokens[start];
				i++;
			}
			else if ((start - 1 >= 0 && !is_redirection(tokens[start - 1])) && !is_redirection(tokens[start]))
			{
				dst[i] = tokens[start];
				i++;
			}
		}
		start++;
	}
	dst[i] = NULL;
	return (dst);
}


int count_opertors_and_file(char **tokens, int start, int end)
{
	int i = 0;
	while (tokens[start] && start < end)
	{
		if (is_redirection(tokens[start]))
			i++;
		start++;
	}
	return (i);
}

char	**fill_oprators(char **dst, char **tokens, int start, int end)
{
	int i;

	i = 0;
	while (tokens[start] && start < end)
	{
		if (is_redirection(tokens[start]))
		{
			dst[i] = tokens[start];
			i++;
		}
		start++;
	}
	dst[i] = NULL;
	return (dst);
}

char	**fill_files(char **dst, char **tokens, int start, int end)
{
	int	i;

	i = 0;
	while (tokens[start] && start < end)
	{
		if ((start - 1 >= 0 && is_redirection(tokens[start - 1])))
		{
			dst[i] = tokens[start];
			i++;	
		}
		start++;
	}
	dst[i] = NULL;
	return (dst);
}

t_cmd *sort_cmds(char **tokens, t_data_cmd  *vars)
{
	int		i;
	int		c;
	int		k;
	int		counter;
	int		tmp;
	int		cmd_size;
	t_cmd	*cmds;

	cmd_size = count_cmds(tokens);
	cmds = malloc(sizeof(t_cmd) * (cmd_size + 1));
	if (!cmds)
		exit (1);
	i = 0;
	c = 0;
	k = 0;
	counter = 0;
	tmp = 0;
	while (c < cmd_size)
	{
		tmp = counter;
		while (tokens[counter] && !str_cmp(tokens[counter], "|"))
		{
			if (counter == 0 || ((counter - 1 >= 0 && !is_redirection(tokens[counter - 1])) && !is_redirection(tokens[counter])))
			{
				if (counter == 0 && !is_redirection(tokens[counter]))
					i++;
				else if (counter - 1 >= 0 && !is_redirection(tokens[counter - 1]) && !is_redirection(tokens[counter]))
					i++;
			}
			counter++;
		}
		if (tokens[counter] && str_cmp(tokens[counter], "|"))
			cmds[k].next_is_pipe = 1;
		else 
			cmds[k].next_is_pipe = 0;
		cmds[k].fd_in = -1;
		cmds[k].fd_out = -1;
		cmds[k].cmd_args = malloc(sizeof(char *) * (i + 1));
		cmds[k].cmd_args = fill_commads(cmds[k].cmd_args, tokens, tmp, counter);
		cmds[k].operators = malloc(sizeof(char *) * (count_opertors_and_file(tokens, tmp, counter) + 1));
		cmds[k].files = malloc(sizeof(char *) * (count_opertors_and_file(tokens, tmp, counter) + 1));
		cmds[k].operators = fill_oprators(cmds[k].operators, tokens, tmp, counter);
		cmds[k].files = fill_files(cmds[k].files, tokens, tmp, counter);
		if (tokens[counter] && str_cmp(tokens[counter], "|"))
			counter+=1;
		i = 0;
		k++;
		c++;
	}
	vars->cmd_size = cmd_size;
	return (cmds);
}
