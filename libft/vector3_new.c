/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:05:48 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vct3		*vct3_new(int x, int y, int z)
{
	t_vct3	*new_vct3;

	if (!(new_vct3 = (t_vct3 *)malloc(sizeof(t_vct3))))
		return (NULL);
	new_vct3->x = x;
	new_vct3->y = y;
	new_vct3->z = z;
	return (new_vct3);
}
