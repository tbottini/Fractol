/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:25:56 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 18:19:35 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				matrice_print(t_mtrc *mtrc)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < mtrc->len_y)
	{
		ft_putnbr(mtrc->num[x + y * mtrc->len_x]);
		ft_putchar('\t');
		if (x == mtrc->len_x - 1)
		{
			ft_putchar('\n');
			x = 0;
			y++;
		}
		else
			x++;
	}
}
