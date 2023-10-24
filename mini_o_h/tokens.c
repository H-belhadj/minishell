/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:09:25 by omakran           #+#    #+#             */
/*   Updated: 2023/10/15 10:56:19 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_odd(int nbr)
{
	if (nbr % 2 == 0)
		return (1);
	return (0);
}

char	*get_elemnts(int start, int length, char *str)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (length + 1));
	if (!dst)
		exit (1);
	while (str[start] && (i < length))
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*split_redirections(int start, char *str)
{
	int 	i ;
	int 	length;
	int 	starttwo;
	char	*dst;

	starttwo = start;
	length = 0;
	i = 0;
	while (str[starttwo] && (str[starttwo] == '>' || str[starttwo] == '<'))
	{
		length ++;
		starttwo++;
	}
	dst = malloc(sizeof(char) * (length + 1));
	if (!dst)
		exit (1);
	while (str[start] && (str[start] == '>' || str[start] == '<')) {
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}


int	is_only_space_and_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	count_tokens(char *line)
{
	int		i;
	int		d_q;
	int		s_q;
	int		count_words;
	int		arg_size;
	char	*space_tab;
	char	*pip_redi;
	char	*token_str;

	d_q = 0;
	s_q = 0;
	i = 0;
	space_tab = "\t ";
	pip_redi = "<>|";
	arg_size = 0;
	count_words = 0;
	while (line[i])
	{
		arg_size = 0;
		if (line[i] == '\'')
		{
			arg_size++;
			s_q++;
		}
		if (line[i] == '\"')
		{
			arg_size++;
			d_q++;
		}
		while (1)
		{
			if (!line[i + arg_size])
				break;
			if (line[i + arg_size] && line[i + arg_size] == '\'')
				s_q++;
			else if (line[i + arg_size] && line[i + arg_size] == '\"')
				d_q++;
			if (line[i + arg_size] && ((ft_search(pip_redi, line[i + arg_size]) || ft_search(space_tab, line[i + arg_size])) && (is_odd(s_q) && is_odd(d_q))))
				break;
			arg_size++;
		}
		token_str = get_elemnts(i, arg_size, line);
		if (!is_only_space_and_tab(token_str))
			count_words++;
		if (ft_search("<>", line[i + arg_size]))
			count_words++;
		else if (ft_search("|", line[i + arg_size]))
			count_words++;
		i += arg_size;
		i++;
	}
	return (count_words);
}

char	**tokens(char *line)
{
	int		i;
	int		d_q;
	int		s_q;
	int		token_size;
	int		arg_size;
	int		dst_counter;
	char	*space_tab;
	char	*pip_redi;
	char	**new_tokens;
	char	*token_str;

	token_size = count_tokens(line);
	new_tokens = malloc(sizeof(char *) * ((token_size ) + 1));
	if (!new_tokens)
		exit (1);
	d_q = 0;
	s_q = 0;
	i = 0;
	space_tab = "\t ";
	pip_redi = "<>|";
	arg_size = 0;
	dst_counter = 0;
	while (line[i])
	{
		arg_size = 0;
		if (line[i] == '\'')
		{
			arg_size++;
			s_q++;
		}
		if (line[i] == '\"')
		{ 
			arg_size++;
			d_q++;
		}
		while (1) {
			if (!line[i + arg_size])
				break;
			if (line[i + arg_size] && line[i + arg_size] == '\'')
				s_q++;
			else if (line[i + arg_size] && line[i + arg_size] == '\"')
				d_q++;
			if (line[i + arg_size] && ((ft_search(pip_redi, line[i + arg_size]) || ft_search(space_tab, line[i + arg_size])) && (is_odd(s_q) && is_odd(d_q))))
				break;
			arg_size++;
		}
		token_str = get_elemnts(i, arg_size, line);
		if (!is_only_space_and_tab(token_str))
			new_tokens[dst_counter++] = token_str;
		if (ft_search("<>", line[i + arg_size]))
		{
			new_tokens[dst_counter++] = split_redirections(i + arg_size, line);
			arg_size += ft_strlen(split_redirections(i + arg_size, line)) - 1;
		}
		else if (ft_search("|", line[i + arg_size]))
			new_tokens[dst_counter++] = "|";
		i += arg_size;
		i++;
	}
	new_tokens[dst_counter] = 0;
	return (new_tokens);
}
