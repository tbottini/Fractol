/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 22:56:52 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/06 15:01:36 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list *curseur;

	if (!new)
		return (NULL);
	curseur = *alst;
	while (curseur->next)
		curseur = curseur->next;
	curseur->next = new;
	return (*alst);
}
