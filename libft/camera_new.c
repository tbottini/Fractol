/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:04:00 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_camera		*camera_new(int fov)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	camera->rotation = NULL;
	if (!(camera->position = (t_vct3 *)malloc(sizeof(t_vct3))))
		return (camera_del(camera));
	if (!(camera->rotation = (t_vct3 *)malloc(sizeof(t_vct3))))
		return (camera_del(camera));
	camera->fov = fov;
	camera->proj = 2;
	return (camera);
}
