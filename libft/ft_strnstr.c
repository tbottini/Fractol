/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:18:26 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:26:33 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] && i < (int)len)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (i > (int)len)
				return (NULL);
			else if (!needle[j])
				return ((char *)&haystack[i - j]);
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
