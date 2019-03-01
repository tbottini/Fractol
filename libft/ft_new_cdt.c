/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_cdt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:20:19 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 17:21:40 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_new_cdt(int x, int y)
{
	char		**new_dt;
	int			i;

	i = -1;
	if (!(new_dt = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	new_dt[y] = NULL;
	while (++i != y)
		if (!(new_dt[i] = (char *)malloc(sizeof(char) * (x + 1))))
			return (NULL);
	return (new_dt);
}
