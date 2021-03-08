/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:24:06 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 17:09:26 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
