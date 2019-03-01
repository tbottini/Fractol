/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/26 22:12:52 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_msg(void)
{
	ft_putendl("usage: fractol [julia\
/ mandelbrot / burningship]");
	exit(0);
}

int		fractol_parseur(int ac, char **av)
{
	if (ac > 2 || ac == 1)
		exit_msg();
	if (!ft_strcmp(av[1], "julia"))
		return (1);
	else if (!ft_strcmp(av[1], "mandelbrot"))
		return (2);
	else if (!(ft_strcmp(av[1], "burningship")))
		return (3);
	exit_msg();
	return (0);
}
