/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:53:17 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/24 19:29:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(t_cmd *cmd) {
    int i = 1; // Start from 1 to skip the command name
    int flag = 1;

    // Loop through the command arguments
    while (cmd->cmd_args[i]) {
        if (strcmp(cmd->cmd_args[i], "-n") == 0) {
            flag = 0;
        } else {
            break; // Exit the loop if an argument is not the -n option
        }
        i++;
    }

    // Output the remaining arguments
    while (cmd->cmd_args[i]) {
        ft_putstr_fd(cmd->cmd_args[i], 1); // Output the argument
        i++;

        // Add a space after each argument
        if (cmd->cmd_args[i]) {
            write(1, " ", 1);
        }
    }

    // Output a newline if the -n flag is not set
    if (flag) {
        write(1, "\n", 1);
    }
}