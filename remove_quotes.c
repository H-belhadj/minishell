/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:55:08 by omakran           #+#    #+#             */
/*   Updated: 2023/10/16 16:41:21 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void remove_quotes(char **tokens)
{
    int     i;
    char    *token;
    int     len;

    i = 0;
    while (tokens[i])
    {
        token = tokens[i];
        len = ft_strlen(token);
        if (len >= 2)
        {
            if ((token[0] == '"' && token[len - 1] == '"') ||
                    (token[0] == '\'' && token[len - 1] == '\''))
                    {
                        ft_memmove(token, token + 1, len - 2);
                        token[len - 2] = '\0';
                    }
        }
        i++;
    }
}

