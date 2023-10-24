/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:18:12 by omakran           #+#    #+#             */
/*   Updated: 2022/10/03 18:31:22 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;	
	unsigned char	value;
	int				i;

	value = c;
	str = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		str[i] = value;
		i++;
		len--;
	}
	return (str);
}
