/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:10:54 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:30:45 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *d;

	if (!s)
		return (0);
	if (!(d = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(d, &s[start], len);
	d[len] = '\0';
	return (d);
}
