/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:26:29 by tbottini          #+#    #+#             */
/*   Updated: 2019/01/17 21:58:45 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char *)src;
		dst++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		src++;
	}
	return (NULL);
}
