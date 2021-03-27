/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:23:47 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 18:27:23 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pa(t_stack *a, t_stack *b, int nb)
{
	int	i;

	if (b->nb > 0)
	{
		a->doublon = 3;
		i = a->nb;
		while (i > 0)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[0] = b->stack[0];
		a->nb++;
		i = 1;
		while (i != b->nb)
		{
			b->stack[i - 1] = b->stack[i];
			i++;
		}
		b->nb--;
		if (nb)
			return (lil_sort(a, b, nb - 1));
	}
	return (0);
}

int		pb(t_stack *a, t_stack *b, int nb)
{
	int	i;

	if (a->nb > 0)
	{
		a->doublon = 4;
		i = b->nb;
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = a->stack[0];
		b->nb++;
		i = 1;
		while (i != a->nb)
		{
			a->stack[i - 1] = a->stack[i];
			i++;
		}
		a->nb--;
		if (nb)
			return (lil_sort(a, b, nb - 1));
	}
	return (0);
}
