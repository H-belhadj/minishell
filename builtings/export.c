/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:02:19 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 22:02:21 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    export(Node* envp, char *str)
{
    char **arr;

    arr = ft_split(str, '=');
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