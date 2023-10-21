/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:13:39 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/10/21 11:07:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (i < ft_strlen(s1))
		s3[j++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

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

int ft_exit_short(t_list *cmd)
{
    int i;
    char *str;

    i = 0;
    //check if the argument is not a numeric value
    if(!all_digit(cmd->arg[1]))
    {
        str = ft_strjoin("bash not : exit: ", cmd->arg[1]);
        str = ft_strjoin(str, ": numeric argument required\n");
        ft_pustr_fd(str, 2);
        free(str);
        t_data.exit = 255;
    }

    //cheack if the argument is numerc and there are too many arguments
    else if(all_digit(cmd->arg[1]) && cmd->arg[2])
    {
        ft_pustr_fd("bash: exit: too many argument\n", 2);
        t_data.exit = 255;
        i = 1;
    }

    //if the argument is numeric and there are not extra argument set the exit status
    else if(all_digit(cmd->arg[1]) && cmd->arg[2])
        t_data.exit = atoi(cmd->arg[1]);
    
    return (i);
}

void ft_exit(t_list *cmd)
{
    int     i;

    i = 0;
    t_data.exit = 0;
    write(cmd->out, "exit\n", 5);
    
    if(cmd->arg[1])
        i = ft_exit_short(cmd);
    if(!i)
        exit(t_data.exit);
}

