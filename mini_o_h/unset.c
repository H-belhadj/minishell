/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:49:22 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 21:55:50 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    ft_unset(Node* envp, char *str)
{
    char **arr;
    Node *tmp;
    Node    *tmp1;

    tmp = envp;
    arr = ft_split(str, '=');
    envp = envp->next;
    while(envp)
    {
        if(strcmp(envp->key, arr[0]) == 0)
        {
            tmp1 = envp->next;
            free(envp->key);
            free(envp->value);
            free(envp);
            tmp->next = tmp1;
            break; 
        }
        tmp = tmp->next;
        envp = envp->next;
    }
    _free(arr);
}