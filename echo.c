/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:46:55 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 18:04:52 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
void echo(int argc,char **argv)
{
    int i;
    int supper;
    
    if(argc <= 1)
        printf("Enter Argement !!");

    else
    {
        i = 1;
        supper = 0;
        if(strcmp(argv[i], "-n") == 0)
        {
            supper = 1;
            i++;
        }
        while(i < argc)
        {
            printf("%s", argv[i]);
            if (i < argc - 1)
                printf(" ");
            i++;
        }
        if(!supper)
            printf("\n");
    }
}
int main(int argc, char **argv)
{
    echo(argc, argv);
    return (0);
}