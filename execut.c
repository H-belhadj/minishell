/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:32:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/27 12:45:24 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int get_redir_type(t_cmd *cmd) {
    for (int i = 0; cmd->operators[i]; i++) {
        if (ft_strlen(cmd->operators[i]) == 2)
        {
            if (!ft_strncmp(">>", cmd->operators[i], ft_strlen(cmd->operators[i])))
                return APPEND;
            else if (!ft_strncmp(cmd->operators[i], "<<", ft_strlen(cmd->operators[i])))
                return HEREDOC;
        }
        else
        {
            if (!ft_strncmp(cmd->operators[i], ">", ft_strlen(cmd->operators[i])))
                return INSERT;
            else if (!ft_strncmp(cmd->operators[i], "<", ft_strlen(cmd->operators[i])))
                return INSERT_FROM;
        }
    }
    return -1;
}

int read_heredoc(char *sep) {
    char    *tmp;
    char    *buf;
    int     fd, fds[2];

    pipe(fds);
    dprintf(2, "SEP: %s\n", sep);
    while (1) {
        tmp = readline("ktb a wldi >");
        if (!tmp || !ft_strncmp(tmp, sep, ft_strlen(tmp)))
            break ;
        tmp = ft_strjoin(tmp, "\n");
        buf = ft_strjoin(buf, tmp);
        if (!buf)
            break ;
    }
    ft_putstr_fd(buf, fds[1]);
    fd = dup(fds[0]);
    close(fds[1]);
    close(fds[0]);
    return fds[0];
}

int open_redir(t_cmd *cmd) {
    int fd;
    int redir_type;

    fd = -1;
    redir_type = get_redir_type(cmd);
    if (redir_type == INSERT) {
        for (int i = 0; cmd->files[i]; i++) {
            fd = open(cmd->files[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
        }
        cmd->fd_out = fd;
    }
    else if (redir_type == INSERT_FROM) {
        for (int i = 0; cmd->files[i]; i++) {
            fd = open(cmd->files[i], O_RDONLY, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
        }
        cmd->fd_in = fd;
    }
    else if (redir_type == APPEND) {
        for (int i = 0; cmd->files[i]; i++) {
            fd = open(cmd->files[i], O_RDWR | O_CREAT | O_APPEND, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
        }
        cmd->fd_out = fd;
    }
    else if (redir_type == HEREDOC) {
        fd = read_heredoc(cmd->files[0]);
        cmd->fd_in = fd;
        
    }
    return fd;
}

void execute_siple(t_data_cmd *cmd, char **env)
{
    int pid;
    char *path;
    if(execut_builting(cmd))
        return ;
    path = get_path(cmd->cmds[0].cmd_args[0], cmd);
    open_redir(cmd->cmds);
    pid = fork();
    if(pid == 0)
    {
        if(path == 0)
        {
            printf("Command Not Found\n");
            exit(127);
        }
        if (cmd->cmds->fd_in > 0) {
            dup2(cmd->cmds->fd_in, 0);
            close(cmd->cmds->fd_in);
        }
        if (cmd->cmds->fd_out > 0) {
            dup2(cmd->cmds->fd_out, 1);
            close(cmd->cmds->fd_out);
        }
        if(execve(path, cmd->cmds->cmd_args, env) == -1)
        {
            perror("execve\n");
            exit(126);
        }
    }
    else {
        if (cmd->cmds->fd_in > 0)
            close(cmd->cmds->fd_in);
        if (cmd->cmds->fd_out > 0)
            close(cmd->cmds->fd_out);
        waitpid(pid, NULL, 0);
    }
}

void execut_all(t_data_cmd *vars, char **env)
{
    if(vars->cmd_size == 1)
        execute_siple(vars, env);
    else
        execute_compund(vars);
}



int execut_builting(t_data_cmd *vars)
{
    
    int rfd = dup(0), wfd = dup(1);
   
    if (open_redir(vars->cmds) > 0) {
        if (vars->cmds->fd_in > 0) {
            dup2(vars->cmds->fd_in, 0);
        }
        if (vars->cmds->fd_out > 0)
            dup2(vars->cmds->fd_out, 1);
    }
    if (str_cmp(vars->cmds[0].cmd_args[0], "exit"))
        ft_exit(&vars->cmds[0]);
    else if(str_cmp(vars->cmds[0].cmd_args[0], "echo"))
        ft_echo(&vars->cmds[0]);
    else if(str_cmp(vars->cmds[0].cmd_args[0], "pwd"))
        ft_pwd(&vars->cmds[0]);
    else if(str_cmp(vars->cmds[0].cmd_args[0], "env"))
        ft_print_env(vars->envp);
    else if (str_cmp(vars->cmds[0].cmd_args[0], "cd"))
        cd(&vars->cmds[0], vars);
    else if(str_cmp(vars->cmds[0].cmd_args[0], "export"))
        export(vars->envp, vars->cmds[0].cmd_args);
    else if(str_cmp(vars->cmds[0].cmd_args[0], "unset"))
        ft_unset(vars->envp, vars->cmds[0].cmd_args[1]);
    else {
        dup2(rfd, 0);
        dup2(wfd, 1);
        close(rfd);
        close(wfd);
        return (0);
    }
    dup2(rfd, 0);
    dup2(wfd, 1);
    close(rfd);
    close(wfd);
    return (1);
}