/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:41:28 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:39:18 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	int		len;
	int		anti;
	size_t	i;

	anti = 0;
	i = 0;
	len = ft_strlen(dst);
	while (src[i] != '\0' && i + len + 1 < size)
	{
		dst[len + i] = src[i];
		if (src[i] == '\0')
			return (ft_strlen(src) + ft_strlen(dst));
		i++;
	}
	dst[len + i] = '\0';
	if (size >= (size_t)len)
		return (ft_strlen(src) + len);
	else
		return (ft_strlen(src) + size);
}
