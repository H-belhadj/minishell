/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:19:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/13 23:14:22 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *cwd;
    
    cwd = getcwd(NULL, 0);
    printf("old Directory to : %s\n", cwd);
    if(argc != 2)//Command-line argument check
        return(printf("usage : %s <directory>\n", argv[0]), 1);
    if(chdir(argv[1]) != 0)//changing the directory
        return(printf("cd"), 1);
    cwd = getcwd(NULL, 0);//getting the current working directory
    if(cwd == NULL)
        return(printf("getcwd"), 1);
    printf("Changed Directory to : %s\n", cwd);
    free(cwd);
}