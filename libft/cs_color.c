/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:03:28 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_col			cs_color(t_color_stock cs, char color)
{
	if (color == 1)
		return (cs.color_stock[cs.color_s1]);
	else
		return (cs.color_stock[cs.color_s2]);
}
