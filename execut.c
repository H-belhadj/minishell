/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:32:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/29 19:05:06 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int get_redir_type(t_cmd *cmd)
{
    int i;

    i = 0;
    while (cmd->operators[i])
    {
        if (ft_strlen(cmd->operators[i]) == 2)
        {
            if (!ft_strncmp(cmd->operators[i], ">>",ft_strlen(cmd->operators[i])))
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
        i++;
    }
    return (-1);
}



int read_heredoc(char *sep)
{
    char    *tmp;
    int     fds[2];

    pipe(fds);
    while (1)
    {
        tmp = readline("herdoc> ");
        if (!tmp)
            break ;
        if (strcmp(tmp, sep) == 0)
            break ;
        ft_putendl_fd(tmp, fds[1]);
        free(tmp);
    }
    close(fds[1]);
    return (fds[0]);
}

int open_redir(t_cmd *cmd)
{
    int i;
    int fd;
    int redir_type;

    fd = -1;
    redir_type = get_redir_type(cmd);
    if (redir_type == INSERT)
    {
        i = 0;
        while (cmd->files[i])
        {
            fd = open(cmd->files[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
            i++;
        }
        cmd->fd_out = fd;
    }
    else if (redir_type == INSERT_FROM)
    {
        i = 0;
        while (cmd->files[i])
        {
            fd = open(cmd->files[i], O_RDONLY, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
            i++;
        }
        cmd->fd_in = fd;
    }
    else if (redir_type == APPEND)
    {
        i = 0;
        while (cmd->files[i])
        {
            fd = open(cmd->files[i], O_RDWR | O_CREAT | O_APPEND, 0644);
            if (cmd->files[i + 1] != NULL)
                close(fd);
            i++;
        }
        cmd->fd_out = fd;
    }
    else if (redir_type == HEREDOC)
    {
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
    if (cmd->cmds->cmd_args[0] == NULL)
        return ;
    path = get_path(cmd->cmds[0].cmd_args[0], cmd);
    pid = fork();
    if(pid == 0)
    {
        signal(SIGQUIT, SIG_DFL);
	    signal(SIGINT, SIG_DFL);
        if(path == 0)
        {
            printf("Command Not Found\n");
            exit(127);
        }
        if (cmd->cmds->fd_in > 0)
        {
            dup2(cmd->cmds->fd_in, 0);
            close(cmd->cmds->fd_in);
        }
        if (cmd->cmds->fd_out > 0)
        {
            dup2(cmd->cmds->fd_out, 1);
            close(cmd->cmds->fd_out);
        }
        if(execve(path, cmd->cmds->cmd_args, env) == -1)
        {
            perror("execve\n");
            exit(126);
        }
    }
    else
    {
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
   
    if (open_redir(vars->cmds) > 0)
        if (vars->cmds->fd_in > 0)
            dup2(vars->cmds->fd_in, 0);
        if (vars->cmds->fd_out > 0)
            dup2(vars->cmds->fd_out, 1);

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
    else 
    {
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
