/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:16:25 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/21 10:43:23 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>     // For standard input/output functions
#include <stdlib.h>    // For general-purpose functions such as memory allocation
#include <pthread.h>   // For thread creation and synchronization
#include <unistd.h>    // For sleep() function (optional)
#include <limits.h>    // For INT_MAX && INT_MIN
#include <sys/time.h>  // For Time in milisecond

typedef struct s_list{
    int out;
    char **arg;
}t_list;

typedef struct t_list {
    int exit;
}t_data;

#endif
