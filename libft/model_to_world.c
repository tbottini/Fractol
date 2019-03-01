/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_to_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:06:08 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vct3			*model_to_world(t_vct3 l_pos, t_vct3 tran, t_vct3 rot, int sca)
{
	t_vct3		*w_pos;
	t_vct3		*tmp;

	if (!(w_pos = (t_vct3 *)malloc(sizeof(t_vct3))))
		return (NULL);
	if (!(tmp = (t_vct3 *)malloc(sizeof(t_vct3))))
	{
		free(w_pos);
		return (NULL);
	}
	vct3_cpy(w_pos, vct3_calc(&l_pos, &tran, &add));
	vct3_rotation(w_pos, rot);
	vct3_mul(w_pos, sca);
	return (w_pos);
}
