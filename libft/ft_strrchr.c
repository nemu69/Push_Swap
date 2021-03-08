/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:47:36 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 03:51:24 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		temp;

	i = 0;
	temp = -1;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == c)
			temp = i;
		i++;
	}
	if (c == 0)
		return (str + i);
	if (temp != -1)
		return (str + temp);
	return (0);
}
