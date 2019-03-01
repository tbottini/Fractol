/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:51 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/27 18:17:55 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			color_decomp(uint8_t rgb[3], unsigned int color)
{
	rgb[0] = color / 256 / 256;
	rgb[1] = color / 256 % 256;
	rgb[2] = color % 256 % 256;
}

t_ct			*ct_get(void)
{
	t_ct		*ct;

	if (!(ct = (t_ct *)malloc(sizeof(t_ct))))
		return (NULL);
	color_decomp(ct->color[0], BLACK);
	color_decomp(ct->color[1], WHITE);
	color_decomp(ct->color[2], CYAN);
	color_decomp(ct->color[3], GREEN);
	color_decomp(ct->color[4], YELLOW);
	color_decomp(ct->color[5], RED);
	color_decomp(ct->color[6], PURPLE);
	color_decomp(ct->color[7], BEIGE);
	color_decomp(ct->color[8], BLUE);
	ct->select[0] = 1;
	ct->select[1] = 2;
	ct->select[2] = 3;
	return (ct);
}

void			ct_gestion(t_ct *ct, int key)
{
	int			s;

	s = 0;
	if (key == KEY_T || key == KEY_G)
		s = 0;
	else if (key == KEY_Y || key == KEY_H)
		s = 1;
	else if (key == KEY_U || key == KEY_J)
		s = 2;
	ct->select[s] += (key == KEY_U || key == KEY_T || key == KEY_Y) ? 1 : -1;
	if (ct->select[s] < 0 || ct->select[s] > 8)
		ct->select[s] = (ct->select[s] < 0) ? 8 : 0;
}

uint32_t		fractol_degr(t_fractol *f, int i, int select)
{
	uint8_t		rgb[3];

	rgb[0] = f->ct->color[f->ct->select[select]][0];
	rgb[1] = f->ct->color[f->ct->select[select]][1];
	rgb[2] = f->ct->color[f->ct->select[select]][2];
	return (color_rgb(rgb[0] * i / f->imax,
		rgb[1] * i / f->imax,
		rgb[2] * i / f->imax));
}
