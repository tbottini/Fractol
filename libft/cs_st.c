/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:22:58 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			color_stock_set(t_color_stock *cs)
{
	cs->color1.c = WHITE;
	cs->color2.c = WHITE;
	cs->color_s1 = 0;
	cs->color_s2 = 0;
	cs->color_stock[0].c = WHITE;
	cs->color_stock[1].c = RED;
	cs->color_stock[2].c = PURPLE;
	cs->color_stock[3].c = BLUE;
	cs->color_stock[4].c = CYAN;
	cs->color_stock[5].c = GREEN;
	cs->color_stock[6].c = YELLOW;
	cs->color_stock[7].c = PCHARRIE;
	cs->color_stock[8].c = FRATARDI;
	cs->color_stock[9].c = BEIGE;
	cs->color_stock[10].c = BLACK;
}
