/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:59:10 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 19:59:15 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char *ft_getenv(char *str, t_data_cmd *vars)
{
    Node *envp_tmp;
    
    envp_tmp = vars->envp;
    while(envp_tmp)
    {
        if(!ft_strncmp(envp_tmp->key, str, ft_strlen(str)))
            return(envp_tmp->value);
        envp_tmp = envp_tmp->next;
    }
    return (0);
}