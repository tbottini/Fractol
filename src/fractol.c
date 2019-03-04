/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/04 18:10:34 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractol_reinit(t_fractol *fractol)
{
	fractol->zoom = 0.5;
	fractol->pos.x = 0;
	fractol->pos.y = 0;
	fractol->imax = 250;
	fractol->mouse_active = 1;
}

t_fractol		*fractol_new(int fnb)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (0);
	if (!(fractol->data = mlx_data_get("fractol", 1920, 1080)))
	{
		free(fractol);
		return (0);
	}
	fractol->fnb = fnb - 1;
	fractol->fractal[0] = &julia;
	fractol->fractal[1] = &mandelbrot;
	fractol->fractal[2] = &burningship;
	fractol_reinit(fractol);
	return (fractol);
}

void			fractol_close(t_fractol *fractol)
{
	mlx_data_close(fractol->data);
	if (fractol->ct)
		free(fractol->ct);
	free(fractol);
	exit(0);
}

int				main(int ac, char **av)
{
	int			frct_choice;
	t_fractol	*fractol;

	if (!(frct_choice = fractol_parseur(ac, av)))
		return (0);
	if (!(fractol = fractol_new(frct_choice)))
		return (0);
	fractol->ct = NULL;
	if (!(fractol->ct = ct_get()))
		fractol_close(fractol);
	mlx_key_hook(fractol->data->win, &input_fractol, fractol);
	mlx_hook(fractol->data->win, MotionNotify, PointerMotionMask,
			&mouse_const, fractol);
	mlx_mouse_hook(fractol->data->win, &mouse_wheel, fractol);
	each_pixel(fractol, fractol->fractal[fractol->fnb]);
	mlx_loop(fractol->data->mlx);
	return (0);
}
