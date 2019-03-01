/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:24:40 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vct3			*vct3_rotation(t_vct3 *pos, t_vct3 rot)
{
	t_vct3		tmp;

	rot.x = rot.x * PI / 180;
	rot.y = rot.y * PI / 180;
	rot.z = rot.z * PI / 180;
	vct3_cpy(&tmp, pos);
	pos->x = tmp.x * cos(rot.z) - tmp.y * sin(rot.z);
	pos->y = tmp.x * sin(rot.z) + tmp.y * cos(rot.z);
	vct3_cpy(&tmp, pos);
	pos->x = tmp.x * cos(rot.y) + tmp.z * sin(rot.y);
	pos->z = tmp.x * -sin(rot.y) + pos->z * cos(rot.y);
	vct3_cpy(&tmp, pos);
	pos->y = tmp.y * cos(rot.x) - tmp.z * sin(rot.x);
	pos->z = tmp.y * sin(rot.x) + tmp.z * cos(rot.x);
	return (pos);
}
