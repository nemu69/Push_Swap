/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:57:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:51:50 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_base(int *based, int size, char *base)
{
	while (size >= 0)
	{
		ft_putchar(base[based[size]]);
		size--;
	}
}

void	ft_putnbr_base(long int nbr, char *base)
{
	long int	intbase;
	int			i;
	int			based[100];

	if (nbr < 0)
		ft_putnbr_base(nbr - 4294967296, base);
	else
	{
		i = 0;
		intbase = 0;
		while (base[intbase] != '\0')
			intbase++;
		while (nbr >= intbase)
		{
			based[i++] = nbr % intbase;
			nbr /= intbase;
		}
		based[i] = nbr % intbase;
		ft_print_base(based, i, base);
	}
}
