/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:13:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 17:19:21 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    cd(t_cmd *cmd)
{
    int i;
    char    cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));
    i = 0;
    if(cmd->args[1]);
    {
        i = chdir(cmd->args[1]);
        //case 1;
    }
    else if(!cmd->args[1])
        //case 2;
}