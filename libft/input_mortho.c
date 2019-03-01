/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mortho.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:04:11 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			input_mortho(int key, t_camera *cam)
{
	cam->position->y += (key == KEY_S || key == KEY_A) ? 5 : -5;
	cam->position->x += (key == KEY_S || key == KEY_D) ? 5 : -5;
}
