/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:37:46 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 19:56:45 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cd(t_cmd *cmd, t_data_cmd *vars)
{
    if(cmd->cmd_args[1])
       chdir(cmd->cmd_args[1]);
    else if(!cmd->cmd_args[1])
       chdir(ft_getenv("HOME", vars));
}