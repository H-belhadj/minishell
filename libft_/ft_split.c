/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:23:16 by omakran           #+#    #+#             */
/*   Updated: 2022/10/26 20:15:51 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	n;
	int	count;

	n = 0;
	count = 0;
	while (str[n])
	{
		while (str[n] == c)
		{
			n++;
		}
		if (str[n])
		{
			while (str[n] != c && str[n])
			{
				n++;
			}
			count++;
		}
	}
	return (count);
}

static int	count_characters(char *str, char c, int start)
{
	int	a;

	a = 0;
	while (str[start] && str[start] != c)
	{
		start++;
		a++;
	}
	return (a);
}

static char	**ft_copy(char **str, char *s, char c, int counter_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < counter_words)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = 0;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		tab = (char **)malloc((count_words((char *)s, c) + 1) * sizeof(char *));
		if (!tab)
			return (0);
		while (i < (count_words((char *)s, c)))
		{
			while (s[j] == c)
				j++;
			tab[i++] = (char *)malloc(count_characters((char *)s, c, j) + 1);
			if (!s[i - 1])
				return (0);
			j += count_characters((char *)s, c, j);
		}
		ft_copy(tab, (char *)s, c, (count_words((char *)s, c)));
		return (tab);
	}
	return (0);
}
// int	main()
// {
// 	char	**str;
// 	int		i = 0;
// 	str = ft_split("****************Omar******Makran*******", '*');
// 	while (str[i])
// 	{
// 		printf("%s", str[i]);
// 		i++;
// 	}
// 	return (0);
// }
