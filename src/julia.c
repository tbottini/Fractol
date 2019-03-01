/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/26 22:09:46 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t		julia(t_fractol *fctl, t_vct2 cur)
{
	t_fvct2		c;
	t_fvct2		z;
	int			i;
	float		tmp;

	c.x = fctl->mouse_pos.x / 1.7 - 0.55;
	c.y = fctl->mouse_pos.y / 1.0;
	z.x = (cur.x * 3.5 / 1920.0 - 1.75) / fctl->zoom + fctl->pos.x;
	z.y = (cur.y * 2.0 / 1080.0 - 1.0) / fctl->zoom + fctl->pos.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < fctl->imax)
	{
		tmp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp + c.x;
		i++;
	}
	if (i == fctl->imax)
		return (fractol_degr(fctl, i, 0));
	else if (i > fctl->imax / 4)
		return (fractol_degr(fctl, i, 1));
	else
		return (fractol_degr(fctl, i, 2));
}

int				each_pixel(t_fractol *fc, uint32_t (*f)(t_fractol*, t_vct2))
{
	t_vct2		cursor;

	vct2_value(&cursor, 0, 0);
	while (cursor.y != 1081)
	{
		img_pixel(fc->data, cursor, f(fc, cursor));
		cursor.x++;
		if (cursor.x == 1920)
		{
			cursor.x = 0;
			cursor.y++;
		}
	}
	mlx_put_image_to_window(fc->data->mlx, fc->data->win,
				fc->data->img, 0, 0);
	return (1);
}
