/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/22 19:43:38 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
