/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:02:33 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 22:02:34 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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