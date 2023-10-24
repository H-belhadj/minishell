/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:54:15 by omakran           #+#    #+#             */
/*   Updated: 2022/10/17 12:26:21 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = 0;
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (0);
	while (*s1)
	{
		arr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		arr[i] = *s2;
		s2++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
