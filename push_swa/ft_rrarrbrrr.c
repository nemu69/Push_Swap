/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrarrbrrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:25:23 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:48:45 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		rra(t_stack *a, t_stack *b, int nb, int test)
{
	long long int	temp;
	int				i;

	(void)b;
	if (a->nb > 1)
	{
		i = 0;
		temp = a->stack[0];
		while (i != a->nb)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->stack[a->nb - 1] = temp;
		if (test && ft_sort(a, b->nb) == 2)
			return (1);
		if (test && ft_test(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rrb(t_stack *a, t_stack *b, int nb, int test)
{
	long long int	temp;
	int				i;

	(void)a;
	if (b->nb > 1)
	{
		i = 0;
		temp = b->stack[0];
		while (i != b->nb)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->stack[b->nb - 1] = temp;
		if (test && ft_test(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rrr(t_stack *a, t_stack *b, int nb)
{
	a->doublon = 6;
	rrb(a, b, nb, 0);
	rra(a, b, nb, 0);
	if (ft_sort(a, b->nb) == 2)
		return (1);
	if (nb == 1)
		return (0);
	if (ft_test(a, b, nb - 1))
		return (1);
	return (0);
}
