/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:26:12 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/12 15:05:57 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		vct3_print(char *msg, t_vct3 vct)
{
	ft_putstr(msg);
	ft_putstr(" x : ");
	ft_putnbr(vct.x);
	ft_putstr(" y : ");
	ft_putnbr(vct.y);
	ft_putstr(" z : ");
	ft_putnbrcr(vct.z);
}
