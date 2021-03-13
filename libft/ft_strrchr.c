/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:47:36 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:50:54 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
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
