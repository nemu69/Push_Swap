/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:21:39 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:00:42 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memmset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	s = str;
	return (s);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*mallo;

	if (!(mallo = (void *)malloc(nmemb * size)))
		return (NULL);
	return (ft_memmset(mallo, 0, nmemb * size));
}
