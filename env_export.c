/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:05:27 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/24 22:01:03 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_env_export(Node *envp)
{
    while(envp)
    {
        if(envp->value && envp->value[0])
            printf("declare -x %s=%s\n", envp->key, envp->value);
        else
            printf("declare -x %s\n", envp->key);
        envp = envp->next;
    }
}