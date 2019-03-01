/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:25:20 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 18:19:03 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtrc	*mtrc_calc(t_mtrc *m1, t_mtrc *m2, int (*f)(t_mtrc*, t_mtrc*, int, int))
{
	int		x;
	int		y;
	t_mtrc	*mtrc_prod;

	mtrc_prod = matrice_null(m1->len_x, m1->len_y);
	x = 0;
	y = 0;
	while (y < m1->len_y)
	{
		mtrc_prod->num[x + y * mtrc_prod->len_x] = f(m1, m2, x, y);
		if (x == m1->len_x - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (mtrc_prod);
}
