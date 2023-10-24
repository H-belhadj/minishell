/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:14:36 by omakran           #+#    #+#             */
/*   Updated: 2022/10/09 18:39:28 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cha;
	unsigned char	*str;
	int				i;

	cha = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (str[i] != cha)
	{
		if (str[i] == 0)
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}
