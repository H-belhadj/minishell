/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:03:22 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/22 20:41:43 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to add a new node to the back of a linked list
void lstadd_back(Node** head, char  *key, char *val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void    _free(char **array)
{
    int i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}
Node *ft_env(char **env)
{
    int i;
    Node    *head = NULL;
    char    **arr;

    i = 0;
    while(env[i])
    {
        arr = ft_split(env[i], '=');
        lstadd_back(&head, ft_strdup(arr[0]), ft_strdup(arr[1]));
        _free(arr);
        i++;
    }
    return (head);
}

void    ft_print_env(Node *envp)
{
    while (envp)
    {
        printf("%s=%s\n", envp->key, envp->value);
        envp = envp->next;
    }
}