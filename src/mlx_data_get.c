/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/03/04 16:33:14 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx_data		*mlx_data_init(t_mlx_data *ml, int sx, int sy)
{
	ml->mlx = NULL;
	ml->win = NULL;
	ml->img = NULL;
	ml->screen = NULL;
	ml->sx = sx;
	ml->sy = sy;
	return (ml);
}

t_mlx_data		*mlx_data_connection(t_mlx_data *ml, char *name)
{
	int			b;
	int			e;
	int			w;

	if (!(ml->mlx = mlx_init()))
		return (mlx_data_close(ml));
	if (!(ml->win = mlx_new_window(ml->mlx, ml->sx, ml->sy, name)))
		return (mlx_data_close(ml));
	if (!(ml->img = mlx_new_image(ml->mlx, ml->sx, ml->sy)))
		return (mlx_data_close(ml));
	ml->screen = (unsigned int *)mlx_get_data_addr(ml->img, &b, &w, &e);
	if (!ml)
		return (mlx_data_close(ml));
	return (ml);
}

t_mlx_data		*mlx_data_get(char *screen_name, int sx, int sy)
{
	t_mlx_data	*ml;

	if (!(ml = (t_mlx_data *)malloc(sizeof(t_mlx_data))))
		return (NULL);
	ml = mlx_data_init(ml, sx, sy);
	return (mlx_data_connection(ml, screen_name));
}

void			*mlx_data_close(t_mlx_data *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx)
		free(mlx);
	return (NULL);
}
