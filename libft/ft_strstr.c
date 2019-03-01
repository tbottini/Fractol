/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:12:20 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:27:12 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j])
				return ((char *)&haystack[i - j]);
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
