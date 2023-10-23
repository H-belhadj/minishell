/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:00:44 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/23 16:19:53 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void execute_siple(t_data_cmd *cmd, char **env)
{
    int pid;
    char *path;
    if(execut_builting(cmd))
        return ;
    path = get_path(cmd->cmds[0].cmd_args[0], cmd);

    pid = fork();
    if(path == 0)
    {
        printf("Command Not Found\n");
        // exit(127);
    }
    if(pid == 0)
    {
        if(execve(path, cmd->cmds->cmd_args, env) == -1)
        {
            perror("execve\n");
            exit(126);
        }
    }else {
        wait(NULL);
    }
}

void execut_all(t_data_cmd *vars, char **env)
{
    if(vars->cmd_size == 1)
        execute_siple(vars, env);
            // else
    //     execute_compund();
}



int execut_builting(t_data_cmd *vars)
{
   
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
            export(vars->envp, vars->cmds[0].cmd_args[1]);
        else if(str_cmp(vars->cmds[0].cmd_args[0], "unset"))
            ft_unset(vars->envp, vars->cmds[0].cmd_args[1]);
        else
            return (0);
        return (1);
}