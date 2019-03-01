/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:46:47 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 22:49:53 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int pow)
{
	long	nbr;

	nbr = nb;
	if (pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	while (pow > 1)
	{
		nbr *= nb;
		pow--;
	}
	return (nbr);
}
