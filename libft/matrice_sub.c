/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:26:03 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 18:17:48 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				matrice_sub(t_mtrc *mtrc1, t_mtrc *mtrc2, int dx, int dy)
{
	return (mtrc1->num[dx + dy * mtrc1->len_x]
		- mtrc2->num[dx + dy * mtrc2->len_x]);
}
