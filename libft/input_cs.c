/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:04:06 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				input_cs(int input, t_color_stock *cs)
{
	if (input == KEY_Y)
		cs->color_s1++;
	if (input == KEY_H)
		cs->color_s1--;
	if (input == KEY_U)
		cs->color_s2++;
	if (input == KEY_J)
		cs->color_s2--;
	if (cs->color_s1 > 10)
		cs->color_s1 = 0;
	if (cs->color_s1 < 0)
		cs->color_s1 = 10;
	if (cs->color_s2 > 10)
		cs->color_s2 = 0;
	if (cs->color_s2 < 0)
		cs->color_s2 = 10;
	return (1);
}
