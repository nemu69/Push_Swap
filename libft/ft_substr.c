/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:56:56 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 17:43:12 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	if (!(str = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	return (str);
}
