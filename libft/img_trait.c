/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_trait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:23:19 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			trait_id(t_mlx_data *mlx, t_vct2 vct1, t_vct2 vct2, t_col col)
{
	int			dx;
	int			dy;
	int			d;
	int			yi;

	dx = vct2.x - vct1.x;
	dy = vct2.y - vct1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy + dx;
	while (vct1.x != vct2.x)
	{
		vct1.x++;
		img_pixel(mlx, vct1, col.c);
		if (d > 0)
		{
			vct1.y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
	}
}

void			trait_iu(t_mlx_data *mlx, t_vct2 vct1, t_vct2 vct2, t_col col)
{
	int			dx;
	int			dy;
	int			d;
	int			xi;

	dy = vct2.y - vct1.y;
	dx = vct2.x - vct1.x;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx + dy;
	while (vct1.y != vct2.y)
	{
		vct1.y++;
		img_pixel(mlx, vct1, col.c);
		if (d > 0)
		{
			vct1.x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
	}
}

void			img_trait(t_mlx_data *mlx, t_vct2 vct1, t_vct2 vct2, t_col col)
{
	if (vct2.x != -1 && vct2.y != -1
		&& vct1.x != -1 && vct1.y != -1)
	{
		if (abs(vct2.y - vct1.y) < abs(vct2.x - vct1.x))
		{
			if (vct1.x > vct2.x)
				trait_id(mlx, vct2, vct1, col);
			else
				trait_id(mlx, vct1, vct2, col);
		}
		else
		{
			if (vct1.y > vct2.y)
				trait_iu(mlx, vct2, vct1, col);
			else
				trait_iu(mlx, vct1, vct2, col);
		}
	}
}
