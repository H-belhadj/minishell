/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:38:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/21 11:51:32 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int digit(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int ft_exit_short(t_cmd *cmd)
{
    int i;

    i = 0;
    //check if the argument is not a numeric value
    if(!digit(cmd->cmd_args[1]))
    {
        ft_putstr_fd("minishell : exit: numeric argument required", 2);
        s_help.exit_status = 255;
    }
    else if(digit(cmd->cmd_args[1]) && cmd->cmd_args[2])
    {
        ft_putstr_fd("bash: exit: too many argument\n", 2);
        s_help.exit_status = 255;
        i = 1;
    }
    //if the argument is numeric and there are not extra argument set the exit status
    else if(digit(cmd->cmd_args[1]) && cmd->cmd_args[2])
        s_help.exit_status = atoi(cmd->cmd_args[1]);
    
    return (i);
}

void ft_exit(t_cmd *cmd)
{
    int     i;

    i = 0;

    write(1, "exit\n", 5);
    
    if(cmd->cmd_args[1])
        i = ft_exit_short(cmd);
    if(!i)
        exit(s_help.exit_status);
}