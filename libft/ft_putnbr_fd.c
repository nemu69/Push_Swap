/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:55:48 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:51:15 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	int div;
	int mod;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n / -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}
