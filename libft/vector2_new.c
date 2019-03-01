/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:04:56 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vct2		*vct2_new(int x, int y)
{
	t_vct2	*new_vector2;

	if (!(new_vector2 = (t_vct2 *)malloc(sizeof(t_vct2))))
		return (NULL);
	new_vector2->x = x;
	new_vector2->y = y;
	return (new_vector2);
}
