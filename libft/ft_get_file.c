/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:23:41 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/09 17:26:39 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_get_file(int fd)
{
	char		*file;
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (!(file = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(file = ft_strjoin_free(file, buffer, 1)))
			return (NULL);
	}
	return (file);
}
