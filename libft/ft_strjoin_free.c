/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:24:45 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 17:24:50 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, char option)
{
	char *d;

	if (!s1 || !s2)
		return (0);
	d = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!d)
		return (NULL);
	ft_strcpy(d, s1);
	ft_strcat(d, s2);
	if (option == 1 || option == 3)
		free(s1);
	else if (option == 2 || option == 3)
		free(s2);
	return (d);
}
