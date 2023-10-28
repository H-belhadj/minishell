/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:04:15 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/28 18:27:41 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_path(char *cmd, t_data_cmd *vars)
{
    int     i;
    char    **arr;
    char *tmp;

    i = -1;
    char *path = ft_getenv("PATH", vars);
    if(!path)
        return (NULL);
    arr = ft_split(path, ':');
    i = -1;
    while(arr[++i])
    {
        char *cmd_path = ft_strjoin(arr[i], "/");
        tmp = ft_strjoin(cmd_path, cmd);
        if(access(tmp, F_OK) == 0)
            return (tmp);
    }
    return (NULL);
}
