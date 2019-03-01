/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dtc_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:21:51 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 17:21:52 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_dtc_nb(char **dtc, int size_x)
{
	int x;
	int y;

	y = -1;
	while (dtc[++y] != NULL)
	{
		x = -1;
		while (++x != size_x)
		{
			ft_putnbr(dtc[y][x]);
			ft_putchar('\t');
		}
		ft_putchar('\n');
	}
}
