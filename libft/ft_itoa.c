/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:27:18 by tbottini          #+#    #+#             */
/*   Updated: 2018/11/18 21:55:31 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_itoa2(int n)
{
	char	*str;
	int		i;
	int		div;
	int		nb;

	nb = n;
	div = 0;
	i = 0;
	if (n < 0)
		div++;
	while (n)
	{
		n /= 10;
		div++;
	}
	if (!(str = ft_strnew(div)))
		return (NULL);
	str[div] = '\0';
	if (nb != 0)
		ft_memset(str, '1', div - 1);
	else
		str[0] = '0';
	return (str);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!(str = ft_itoa2(n)))
		return (NULL);
	len = ft_strlen(str);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			n = -147483648;
			str[1] = '2';
		}
		n = -n;
	}
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
