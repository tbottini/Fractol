/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:35:29 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:25:48 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*nv;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[end] == '\t' || s[end] == '\n' || s[end] == ' ')
		end -= 1;
	if (end == -1)
	{
		if (!(nv = (char *)malloc(sizeof(char))))
			return (NULL);
		nv[0] = '\0';
		return (nv);
	}
	if (!(nv = ft_strsub(s, i, end - i + 1)))
		return (NULL);
	return (nv);
}
