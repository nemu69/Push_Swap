/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrarrbrrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:25:23 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 18:27:23 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_stack *a, t_stack *b, int nb)
{
	long long int	temp;
	long long int	temp2;
	int				i;

	if (a->nb > 1 && a->doublon != 5)
	{
		a->doublon = 7;
		i = 0;
		temp = a->stack[i];
		while (i != a->nb)
		{
			temp2 = temp;
			temp = a->stack[i + 1];
			a->stack[i + 1] = temp2;
			i++;
		}
		a->stack[0] = temp2;
		if (nb && lil_sort(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rrb(t_stack *a, t_stack *b, int nb)
{
	long long int	temp;
	long long int	temp2;
	int				i;

	if (b->nb > 1 && a->doublon != 6)
	{
		i = 0;
		temp = b->stack[i];
		while (i != b->nb)
		{
			temp2 = temp;
			temp = b->stack[i + 1];
			b->stack[i + 1] = temp2;
			i++;
		}
		b->stack[0] = temp2;
		if (nb && lil_sort(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rrr(t_stack *a, t_stack *b, int nb)
{
	if (a->doublon == 6 || a->doublon == 5 || b->nb < 2 || a->nb < 2)
		return (0);
	rrb(a, b, 0);
	rra(a, b, 0);
	if (ft_sort(a, b->nb))
		return (1);
	if (nb == 1)
		return (0);
	if (lil_sort(a, b, nb - 1))
		return (1);
	return (0);
}
