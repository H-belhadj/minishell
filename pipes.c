/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 20:49:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_compund(t_data_cmd *cmd)
{
    int pid;
    int fd[2];
    int stdin_fd = dup(0);
    if(pipe(fd) == -1)
    {
        printf("Eroor a saatt\n");
        exit(127);
    }
    pid = fork();
    if (!pid)
    {
        if(cmd->cmds->next_is_pipe == 1)
            dup2(fd[1], 1);
        execve(cmd->cmds->cmd_args[0], cmd->cmds->cmd_args, NULL);
    }
    else
    {
        wait(NULL);
        dup2(fd[0], 0);
        execve("cat" , ft_split("cat", ' '), NULL);
        close(fd[1]);
        close(fd[0]);
        close(0);
        dup2(stdin_fd, 0);
    }
}