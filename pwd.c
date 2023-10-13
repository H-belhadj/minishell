/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:46:50 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/13 23:52:55 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void pwd()
{
    char wd[1000];
    printf("Current Working Directory: %s ", getcwd(wd, sizeof(wd)));
}