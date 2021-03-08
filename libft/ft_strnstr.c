/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:18:42 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 05:55:40 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && count <= len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0')
		{
			j++;
			count++;
		}
		if (s2[j] == '\0' && count <= len)
			return ((char*)s1 + i);
		i++;
		count++;
	}
	return (0);
}
