/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:06 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:39:18 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t			mandelbrot(t_fractol *fctl, t_vct2 cur)
{
	t_dvct2			c;
	t_dvct2			z;
	int				i;
	double			tmp;

	c.x = ((cur.x * 3.5 / 1920.0) - 1.75) / (fctl->zoom)
			+ fctl->pos.x - 0.75;
	c.y = ((cur.y * 2.0 / 1080.0) - 1) / (fctl->zoom) + fctl->pos.y;
	z.x = 0;
	z.y = 0;
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
