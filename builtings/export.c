/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:02:19 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/23 21:37:23 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    export(Node* envp, char *str)
{
    char **arr;

    arr = ft_split(str, '=');
    if(!arr || !arr[0])
    {
        get_env_export(envp);
        return;
    }
    else if(!arr[1])
    {
        lstadd_back(&envp, lst_new(arr[0], ""));
        return;
    }
    while(envp)
    {
        if(strcmp(envp->key, arr[0]) == 0)
        {
            free(envp->value);
            envp->value = ft_strdup(arr[1]);        
            break; 
        }
        else if (envp->next == NULL)
            envp->next = lst_new(ft_strdup(arr[0]),ft_strdup(arr[1]));
        envp = envp->next;
    }
    _free(arr);
}