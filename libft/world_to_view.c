/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:28:15 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vct2		*world_to_view(t_vct2 *m, t_mlx_data mlx, t_camera c, t_vct3 w)
{
	t_vct3	delta;

	delta = *vct3_calc(&w, c.position, &sub);
	vct3_rotation(&delta, *c.rotation);
	if (delta.z < 0)
	{
		vct2_value(m, -1, -1);
	}
	else if (c.proj == 1)
	{
		m->x = (delta.x * 1000 / delta.z * tan(c.fov * PI / 360));
		m->x += mlx.sx / 2;
		m->y = (delta.y * 1000 / delta.z * tan(c.fov * PI / 360));
		m->y += mlx.sy / 2;
		if (m->x < 0 || m->y < 0 || m->x > mlx.sx
			|| m->y > mlx.sy)
			vct2_value(m, -1, -1);
	}
	else if (c.proj == 2)
	{
		m->x = delta.x * 10 + mlx.sx / 2;
		m->y = delta.y * 10 + mlx.sy / 2;
	}
	return (m);
}
