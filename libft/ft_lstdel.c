/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:23:14 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/06 16:07:21 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nxt;

	while (*alst)
	{
		nxt = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = nxt;
	}
}
