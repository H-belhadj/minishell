/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:17:51 by omakran           #+#    #+#             */
/*   Updated: 2023/10/16 16:35:13 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}