/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:43:36 by omakran           #+#    #+#             */
/*   Updated: 2023/10/23 18:53:54 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_eligible_to_expand(char *token, int stop, int in)
{
	int i = 0;
	int s_q = 0;
	int d_q = 0;

	if (in)
	{
		while (token[i])
		{
			if (token[i] == '\'' && (d_q % 2 == 0))
				s_q++;
			if (token[i] == '\"' && (s_q % 2 == 0))
				d_q++;
			if (token[i] == '$' && s_q % 2 == 0)
				return (1);
			i++;
		}
	}
	else
	{
		while (token[i]) {
			if (token[i] == '\'' && (d_q % 2 == 0))
				s_q++;
			if (token[i] == '\"' && (s_q % 2 == 0))
				d_q++;
			if ((stop == i && token[i] == '$' ) && s_q % 2 == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

int var_size(char *token, int start)
{
	int size;

	size = 0;
	while (token[start] && ft_isalpha(token[start]))
	{
		start++;
		size++;
	}
	return (size);
}

char	*expand(char *token, t_data_cmd *vars)
{
	int i = 0;
	char *tmp;
	char *tmp2;
	char *var_name;
	char *var_value;
	while (token[i])
	{
		if (is_eligible_to_expand(token, i, 0))
		{
			tmp = ft_substr(token, 0, i);
			var_name = ft_substr(token, i + 1, var_size(token, i + 1));
			var_value = ft_getenv(var_name, vars); //change getenv to our fT_getenv version : haitam
			if (!var_value)
				var_value = "";
			tmp2 = ft_strjoin(var_value, (&token[i + 1 + var_size(token, i + 1)]));
			token = ft_strjoin(tmp, tmp2);
			i = 0;
		}
		else
			i++;
	}
	return (token);
}


char **expand_all_tokens(char **tokens, t_data_cmd *vars)
{
	int	i;


	i = 0;
	while (tokens[i])
	{
		if (is_eligible_to_expand(tokens[i], 0, 1))
			tokens[i] = expand(tokens[i], vars);
		i++;
	}
	return (tokens);
}