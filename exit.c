/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:13:39 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/20 07:03:01 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int digit(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(is_digit(str[i]))
            return (1);
        i++;
    }
    return (0);
}