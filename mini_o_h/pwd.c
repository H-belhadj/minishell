/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:49:31 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/21 17:41:05 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_pwd(t_cmd *cmd)
{
    (void) cmd;
    char cwd[PATH_MAX];
    if(getcwd(cwd, sizeof(cwd)) == NULL)
        perror("getcwd");
    //get the current working directory and store in 'cwd'
    getcwd(cwd, sizeof(cwd));
    //write the current working directory to the specifice output
    ft_putstr_fd(cwd, 1);
    //add a newline character to the output for formatting
    write(1, "\n", 1);
    //set the global exit status to 0 to indicate sucsse
    s_help.exit_status = 0;
}