/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 00:22:09 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:50:34 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strln(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	ind;
	size_t	i;

	i = 0;
	ind = ft_strln(dest);
	k = ft_strln((char*)src) + ft_strln(dest);
	if (ft_strln(dest) < size)
	{
		while (ind < size - 1 && src[i])
		{
			dest[ind] = src[i];
			ind++;
			i++;
		}
		dest[ind] = '\0';
	}
	else
		k = ft_strln((char*)src) + size;
	return (k);
}
