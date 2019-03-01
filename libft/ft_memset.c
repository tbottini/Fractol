/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:54:30 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:43:16 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	if (len == 0)
		return (b);
	d = (unsigned char *)b;
	while (len--)
	{
		*(unsigned char*)b = c;
		b++;
	}
	return (d);
}
