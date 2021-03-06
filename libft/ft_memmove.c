/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:32:59 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:51:15 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!(dest) && !(src))
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = -1;
	if (str1 == str2)
		return (dest);
	if (str1 < str2)
		while (++i != (int)n)
			str1[i] = str2[i];
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			str1[i] = str2[i];
			i--;
		}
	}
	dest = str1;
	return (dest);
}
