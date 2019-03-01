/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:11:57 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:24:20 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	**ft_calc(char const *s, char c)
{
	int		len;
	int		i;
	char	**b;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	if (!(b = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	b[len] = 0;
	return (b);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	**b;

	i = 0;
	len = 0;
	j = 0;
	if (!s || !(b = ft_calc(s, c)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (len)
			if (!(b[j] = ft_strsub(s, i, len)))
				return (NULL);
		i += len;
		len = 0;
		j++;
	}
	return (b);
}
