/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/21 22:47:46 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			img_pixel(t_mlx_data *mlx, t_vct2 vct, unsigned int color)
{
	if (vct.x < mlx->sx
		&& vct.y < mlx->sy
		&& vct.y > 0
		&& vct.x > 0)
		mlx->screen[vct.x + vct.y * mlx->sx] = color;
}
