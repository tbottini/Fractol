/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:40 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:17:21 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t			burningship(t_fractol *fctl, t_vct2 cur)
{
	t_fvct2			c;
	t_fvct2			z;
	int				i;
	float			tmp;

	c.x = (cur.x * 3.5 / 1920.0 - 1.75) / fctl->zoom + fctl->pos.x;
	c.y = (cur.y * 2.0 / 1080.0 - 1.0) / fctl->zoom + fctl->pos.y;
	z.x = c.x;
	z.y = c.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < fctl->imax)
	{
		tmp = z.x * z.x - z.y * z.y;
		z.y = fabs(2 * z.x * z.y + c.y);
		z.x = fabs(tmp + c.x);
		i++;
	}
	if (i == fctl->imax)
		return (fractol_degr(fctl, i, 0));
	else if (i > fctl->imax / 4)
		return (fractol_degr(fctl, i, 1));
	else
		return (fractol_degr(fctl, i, 2));
}
