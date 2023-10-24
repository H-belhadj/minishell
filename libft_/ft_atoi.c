/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:14:57 by omakran           #+#    #+#             */
/*   Updated: 2022/10/11 19:56:07 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_white_spaces(char c)
{
	if (c == 32 || c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	ck;

	number = 0;
	ck = 1;
	while (ft_white_spaces(*str))
	{
		str++;
	}
	if (*str == '-')
	{
		ck = -1;
		str++;
	}
	else if (*str == '+')
	{
		ck = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (number *= ck);
}
