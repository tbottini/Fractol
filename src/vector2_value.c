/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/04 16:38:27 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vct2			*vct2_value(t_vct2 *vct, int x, int y)
{
	vct->x = x;
	vct->y = y;
	return (vct);
}

void			img_pixel(t_mlx_data *mlx, t_vct2 vct, unsigned int color)
{
	if (vct.x < mlx->sx
		&& vct.y < mlx->sy
		&& vct.y > 0
		&& vct.x > 0)
		mlx->screen[vct.x + vct.y * mlx->sx] = color;
}

unsigned int	color_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r * 256 * 256) + (g * 256) + b;
}
