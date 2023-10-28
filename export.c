/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:52:40 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/28 18:22:42 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_arr(char **arr)
{
    int i;

    i = -1;
    if (!arr)
        return ;
    while (arr[++i])
        printf("arr[%d]: %s\n", i, arr[i]);
}

char *get_key(Node *envp, char *key)
{
    while(envp)
    {
        if(strcmp(envp->key, key) == 0)
          return (key);          
        envp = envp->next;
    }
    return (NULL);
}

void    export(Node* envp, char **str)
{
    char **arr;
    
    if(!str[1])
    {
        get_env_export(envp);
        return;
    }
    int i = 0;
    while(str[++i])
    {
        arr = ft_split(str[i], '=');
        char *key = get_key(envp, arr[0]);
        if (key)
        {     
            while(envp)
            {
                if(strcmp(envp->key, key) == 0)
                {
                    free(envp->value);
                    if (arr[1])
                        envp->value = ft_strdup(arr[1]);
                    else
                        envp->value = arr[1];           
                }
                envp = envp->next;
            }
        }
        else
        {
            envp->key = ft_strdup(arr[0]);
            if (arr[1])
                envp->value = ft_strdup(arr[1]);
            else
                envp->value = arr[1]; 
            lstadd_back(&envp, lst_new(envp->key, envp->value));
        }
        _free(arr);
    }
    
}
