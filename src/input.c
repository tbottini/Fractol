/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:22 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/04 18:15:36 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		input_move(int key, t_fractol *fractol)
{
	if (key == KEY_W)
		fractol->pos.y -= 0.2 / fractol->zoom;
	else if (key == KEY_S)
		fractol->pos.y += 0.2 / fractol->zoom;
	else if (key == KEY_A)
		fractol->pos.x -= 0.2 / fractol->zoom;
	else if (key == KEY_D)
		fractol->pos.x += 0.2 / fractol->zoom;
	return (1);
}

int		zoom(t_fractol *fctl, int x, int y, float sens)
{
	(void)sens;
	fctl->pos.x = ((x * 3.5 / 1920.0) - 1.75) / fctl->zoom + fctl->pos.x;
	fctl->pos.y = ((y * 2.0 / 1080.0) - 1) / fctl->zoom + fctl->pos.y;
	if (sens > 0)
		fctl->zoom *= 2 * sens;
	else if (sens < 0)
		fctl->zoom /= 2 * fabs(sens);
	return (0);
}

int		input_fractol(int key, t_fractol *fractol)
{
	if (key == KEY_T || key == KEY_G || key == KEY_H || key == KEY_Y
		|| key == KEY_U || key == KEY_J)
		ct_gestion(fractol->ct, key);
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		input_move(key, fractol);
	else if ((key == KEY_R || key == KEY_F) && fractol->imax > 25)
		fractol->imax += (key == KEY_R) ? 25 : -25;
	else if (key >= KEY_1 && key <= KEY_3)
	{
		fractol->fnb = key - KEY_1;
		fractol_reinit(fractol);
	}
	else if (key == KEY_Q)
		fractol_reinit(fractol);
	else if (key == KEY_E)
		fractol->mouse_active = (fractol->mouse_active) ? 0 : 1;
	else if (key == KEY_ESC)
		fractol_close(fractol);
	each_pixel(fractol, fractol->fractal[fractol->fnb]);
	return (0);
}

int		mouse_const(int x, int y, t_fractol *fctl)
{
	if (fctl->mouse_active)
	{
		fctl->mouse_pos.x = ((x * 3.5 / 1920.0) - 1.75);
		fctl->mouse_pos.y = ((y * 2.0 / 1080.0) - 1);
		if (fctl->fnb == 0)
			each_pixel(fctl, fctl->fractal[fctl->fnb]);
	}
	return (1);
}

int		mouse_wheel(int key, int x, int y, t_fractol *fractol)
{
	if (key == WHEEL_UP || key == WHEEL_DOWN)
		zoom(fractol, x, y, (key == WHEEL_DOWN) ? 1 : -1);
	each_pixel(fractol, fractol->fractal[fractol->fnb]);
	return (1);
}
