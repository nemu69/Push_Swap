/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:54:10 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 20:52:21 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strln(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	int		check_charset(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*str;

	i = 0;
	start = 1;
	end = ft_strln((char*)s1) - 1;
	while (start && end != 0)
		check_charset(s1[end], (char*)set) ? end-- : start--;
	start = 0;
	while (check_charset(s1[start], (char*)set) && start < end)
		start++;
	if (end == 0)
		end = -1;
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
