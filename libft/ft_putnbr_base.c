/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/07 09:57:12 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 22:51:34 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
