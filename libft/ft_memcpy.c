/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:59:19 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:50:34 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!(dest) && !(src))
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	while (i != n)
	{
		str1[i] = str2[i];
		i++;
	}
	dest = str1;
	return (dest);
}
