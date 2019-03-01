/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:07:14 by tbottini          #+#    #+#             */
/*   Updated: 2019/02/08 16:59:23 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcut_free(char **s1, char **s2, char *buffer)
{
	char	*tmp;

	tmp = *s1;
	*s1 = ft_strndup(*s1, ft_strchr(*s1, '\n') - *s1);
	free(tmp);
	tmp = *s2;
	*s2 = ft_strdup((ft_strchr(buffer, '\n') + 1));
	free(tmp);
	if (!s1 || !s2)
	{
		ft_strdel(s1);
		ft_strdel(s2);
		return (0);
	}
	return (1);
}

int			ft_del(char **s1)
{
	ft_strdel(s1);
	return (-1);
}

int			gnl(int fd, char **line, char **buffer_past)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	if (*buffer_past && !(*line = ft_strdup(*buffer_past)))
	{
		free(*buffer_past);
		return (-1);
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = *line;
		*line = (*line) ? ft_strjoin(*line, buffer) : ft_strdup(buffer);
		free(tmp);
		if (!(*line))
			return (ft_del(buffer_past));
		if (ft_strchr(buffer, '\n'))
			return (ft_strcut_free(line, buffer_past, buffer));
	}
	ft_strdel(buffer_past);
	if (*line && *line[0] != '\0')
		return (1);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer_past = NULL;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (buffer_past && ft_strchr(buffer_past, '\n'))
	{
		tmp = *line;
		*line = ft_strndup(buffer_past, ft_strchr(buffer_past, '\n')
			- buffer_past);
		free(tmp);
		tmp = buffer_past;
		buffer_past = ft_strdup((ft_strchr(buffer_past, '\n') + 1));
		free(tmp);
		if (!(*line || buffer_past))
			return ((ft_del(line) && ft_del(&buffer_past)) + 1);
		return (1);
	}
	return (gnl(fd, line, &buffer_past));
}
