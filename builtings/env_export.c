/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:37:59 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/23 21:38:01 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void get_env_export(Node *envp)
{
    // Node    *head;
    // Node *tmp;
    // tmp = NULL;
    // Node *head;
    // *tmp = *envp;
    
    while(envp)
    {
        if(envp->value && envp->value[0])
            printf("declare -x %s = %s\n", envp->key, envp->value);
        else
            printf("declare -x %s\n", envp->key);
        envp = envp->next;
    }
    // head = NULL;
    // head = ft_env(env);
    // while(env[i])
    // {
    //     printf("declare -x %s = %s\n", ft_env(env), ft_env(env));
    //     i++;
    // }
    // printf("head == [%s]\n", head->key);
    // printf("head == [%s]\n", head->value);
}