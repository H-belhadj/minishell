/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/26 16:37:52 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_compund(t_data_cmd *cmd)
{
    int pid;
    int save = -1;
    int i = -1;
    while (++i < cmd->cmd_size) 
    {
        int fd[2];
        char    *path;
        if(pipe(fd) == -1)
        {
            printf("Eroor a saatt\n");
            exit(127);
        }
        pid = fork();
        if (pid == 0)
        {
            if (i == 0) {
                dup2(fd[1], 1);
            } else if (i == cmd->cmd_size - 1) {
                dup2(save, 0);
            } else if (i < cmd->cmd_size - 1 && i > 0) {
                dup2(save, 0);
                dup2(fd[1], 1);
            }
            close(save);
            close(fd[0]);
            close(fd[1]);
            path = get_path(cmd->cmds[i].cmd_args[0], cmd);
            if (path) {
                if (execve(path, cmd->cmds[i].cmd_args, NULL) == -1) {
                }
            }
        }
        if (pid > 0)
        {
            save = -1;
            if (save > 2)
            {
                close(save);
            }
            else 
                save = dup(fd[0]);
            close(fd[0]);
            close(fd[1]);
            waitpid(pid, NULL, 0);
        }
    }
}