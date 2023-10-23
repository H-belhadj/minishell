/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:59:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/23 13:59:59 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *get_path(char *cmd, t_data_cmd *vars)
{
    int     i;
    char    **arr;
    char *tmp;

    i = -1;
    char *path = ft_getenv("PATH", vars);
    arr = ft_split(path, ':');
    i = -1;
    while(arr[++i])
    {
        char *cmd_path = ft_strjoin(arr[i], "/");
        tmp = ft_strjoin(cmd_path, cmd);
        // printf("cmd ==> %s\n", tmp);
        if(access(tmp, F_OK) == 0)
            return (tmp);
    }
    return (NULL);
    // execute_cmd(cmd);
}