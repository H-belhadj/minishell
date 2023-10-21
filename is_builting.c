/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:41:40 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 18:04:28 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_bultings(char **argv)
{
    if(argv[1] == "echo")
        return (1);
    else if(argv[1] == "cd")
        return(1);
    else if(argv[1] == "pwd")
        return (1);
    else if(argv[1] == "export")
        return(1);
    else if (argv[1] == "unset")
        return(1);
    else if(argv[1] == "env")
        return (1);
    else if(argv[1] == "exit")
        return (1);
    else
        return (0);
}

