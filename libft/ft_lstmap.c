/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:35:21 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:54:57 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*curseur;

	if (!lst || !(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	curseur = new;
	while (lst->next)
	{
		lst = lst->next;
		curseur->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!curseur)
			return (NULL);
		curseur = curseur->next;
	}
	return (new);
}
