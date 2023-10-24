/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:04:15 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/23 15:40:23 by hbelhadj         ###   ########.fr       */
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


/*

    path ==> /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
    
    ls ===>
    1 / search for path 
    {
        split path ":"
        /usr/local/bin/ls
        /usr/bin/ls
        /bin/ls
        /usr/sbin/ls
        /sbin/ls
        /usr/local/munki/ls
        NULL;
    }
    fork()
    {
       if path == command not found
       else
            exeve("/bin/ls", args, env);
    }
*/