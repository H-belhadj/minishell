/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 15:07:13 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_compund(t_data_cmd *cmd)
{
    int fd[2];
    int i = -1;
    int pid;
    
    while(++i < 2)
    {
        pid = fork();
        pipe(fd);
        if(pid == 0)
        {
            close(fd[0]);
            if(i + 1)
                dup2(fd[i], 1);
            execve(cmd->cmds[i].cmd_args[0], cmd->cmds[i].cmd_args, NULL);
        }
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
    }
}