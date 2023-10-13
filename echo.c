/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:46:55 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/13 22:12:55 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void echo(int argc,char **argv)
{
    int i;
    if(argc <= 1)
        printf("Enter Argement !!");
    else
    {
        i = 0;
        while(++i < argc)
        {
            printf("%s", argv[i]);
            if (i < argc - 1)
                printf(" ");
        }
        printf("\n");
    }
}
