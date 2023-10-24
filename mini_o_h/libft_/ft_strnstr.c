/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:47 by omakran           #+#    #+#             */
/*   Updated: 2022/10/13 21:16:28 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if ((!haystack) && len == 0)
	{
		return (0);
	}
	else if (needle[i] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i <= len)
	{
		if (haystack[i] == *needle && ft_strlen(needle) <= len - i)
		{
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
