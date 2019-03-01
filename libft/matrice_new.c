/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:25:39 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 18:20:00 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtrc			*matrice_new(int len_x, int len_y, int *nums)
{
	t_mtrc		*new;
	int			i;

	i = -1;
	if (!(new = (t_mtrc *)malloc(sizeof(t_mtrc))))
		return (NULL);
	if (!(new->num = (int *)malloc(sizeof(int) * (len_x * len_y))))
	{
		free(new);
		return (NULL);
	}
	while (++i < len_x * len_y)
		new->num[i] = nums[i];
	new->len_x = len_x;
	new->len_y = len_y;
	return (new);
}
