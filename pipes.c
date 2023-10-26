/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/26 13:16:14 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_compund(t_data_cmd *cmd)
{
    int pid;
    int save = -1;
    for (int i = 0; i < cmd->cmd_size; i++) {
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
            dprintf(2, "save fd %d\n", save);
            close(save);
            close(fd[0]);
            close(fd[1]);
            path = get_path(cmd->cmds[i].cmd_args[0], cmd);
            if (path) {
                if (execve(path, cmd->cmds[i].cmd_args, NULL) == -1) {
                    dprintf(2, "%s\n", strerror(errno));
                }
            }
        }
        if (pid > 0)
        {
            if (save > 2)
            {
                close(save);
                save = -1;
            }
            else 
                save = dup(fd[0]);
            close(fd[0]);
            close(fd[1]);
            waitpid(pid, NULL, 0);
            printf("Command int i = %d | size = %d\n", i, cmd->cmd_size);
        }
    }

    
    // else
    // {
    //     wait(NULL);
    //     dup2(fd[0], 0);
    //     execve("/bin/cat" , ft_split("/bin/cat", ' '), NULL);
    //     close(fd[1]);
    //     close(fd[0]);
    //     close(0);
    //     dup2(stdin_fd, 0);
    // }
}