/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:03:53 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*camera_del(t_camera *cam)
{
	if (cam->position)
		free(cam->position);
	if (cam->rotation)
		free(cam->rotation);
	free(cam);
	return (NULL);
}
