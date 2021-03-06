/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:12:57 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/29 16:18:08 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int			ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], 1);
	return (1);
}
