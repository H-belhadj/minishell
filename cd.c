/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:19:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 18:09:38 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int cd(int argc, char **argv)
{
    char *cwd;
    
    if(argc != 3)//Command-line argument check
        return(printf("usage : %s <directory>\n", argv[0]), 1);
    if(strcmp(argv[1], "cd") != 0)
        return (1);
    if(chdir(argv[2]) != 0)//changing the directory
        return(printf("cd"), 1);
    cwd = getcwd(NULL, 0);//getting the current working directory
    if(cwd == NULL)
        return(printf("getcwd"), 1);
    printf("Changed Directory to : %s\n", cwd);
    free(cwd);
    return (0);
}

int main(int argc, char **argv)
{
    cd(argc, argv);
    return (0);
}