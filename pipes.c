/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:18:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 16:25:38 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_compund(t_data_cmd *cmd)
{
    int pid;
    int fd[2];
    pipe(fd);
    if(pipe(fd) == -1)
    {
        printf("Eroor a saatt\n");
        exit(127);
    }
    pid = fork();
    if(cmd->cmds->next_is_pipe == 1)
    {
        dup2(fd[1], 1);
        pipe(&fd[1]);
    }
    else
        pipe(&fd[0]);
    printf("ana makhadamchi \n");
    close(fd[1]);
    close(fd[0]);
    wait(NULL);
}