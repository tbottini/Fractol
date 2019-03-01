/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:04:16 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			input_mpers(int key, t_camera *cam)
{
	float x_dir;
	float z_dir;

	z_dir = cos(cam->rotation->y * PI / 180) * 15;
	x_dir = sin(cam->rotation->y * PI / 180) * 15;
	if (key == KEY_W)
	{
		cam->position->z += z_dir;
		cam->position->x -= x_dir;
	}
	else if (key == KEY_A)
	{
		cam->position->z -= x_dir;
		cam->position->x -= z_dir;
	}
	else if (key == KEY_S)
	{
		cam->position->z -= z_dir;
		cam->position->x += x_dir;
	}
	else if (key == KEY_D)
	{
		cam->position->z += x_dir;
		cam->position->x += z_dir;
	}
}
