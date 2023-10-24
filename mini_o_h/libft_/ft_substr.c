/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:38 by omakran           #+#    #+#             */
/*   Updated: 2022/10/22 00:11:37 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	n;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	n = 0;
	arr = malloc(len + 1 * sizeof(char));
	if (!arr)
		return (NULL);
	while (n < len && start < ft_strlen(s))
	{
		arr[n] = s[start];
		n++;
		start++;
	}
	arr[n] = '\0';
	return (arr);
}
// int main()
// {
// 	printf("%s\n", ft_substr("Omar MAkran1213", 2, 6));
// 	return (0);
// }
