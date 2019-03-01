/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:25:44 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 18:20:45 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					matrice_mul(t_mtrc *mtrc1, t_mtrc *mtrc2, int dx, int dy)
{
	int				x1;
	int				y2;
	int				res;

	x1 = 0;
	y2 = 0;
	res = 0;
	while (x1 != mtrc1->lenX)
	{
		res += mtrc1->num[x1 + dy * mtrc1->len_x] * mtrc2->num[dx + y2 *
			mtrc1->len_x];
		x1++;
		y2++;
	}
	return (res);
}
