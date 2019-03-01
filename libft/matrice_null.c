/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:25:51 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 17:40:37 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtrc			*matrice_null(int len_x, int len_y)
{
	t_mtrc		*mtrc;

	if (!(mtrc = (t_mtrc *)malloc(sizeof(t_mtrc))))
		return (NULL);
	if (!(mtrc->num = (int *)malloc(sizeof(int) * (len_x * len_y))))
	{
		free(mtrc);
		return (NULL);
	}
	ft_bzero(mtrc->num, sizeof(int) * (len_x * len_y));
	mtrc->len_x = len_x;
	mtrc->len_y = len_y;
	return (mtrc);
}
