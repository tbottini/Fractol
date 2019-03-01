/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/20 15:56:52 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	color_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r * 256 * 256) + (g * 256) + b;
}
