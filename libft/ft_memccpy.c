/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:24:06 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:50:34 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (!dst || !src)
		return (NULL);
	i = 0;
	while (i != n && str2[i] != (unsigned char)c)
	{
		str1[i] = str2[i];
		i++;
	}
	if (str2[i] == (unsigned char)c)
	{
		str1[i] = str2[i];
		i++;
		return (dst + i);
	}
	return (NULL);
}
