/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sasbss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:21:16 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:56:30 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	long long int temp;

	if (a->nb > 1 && a->doublon != 1)
	{
        a->doublon = 1;
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
		if (nb && ft_sort(a, b->nb))
            return (1);        
        if (nb && ft_test(a, b, nb - 1, fct))
            return (1);
	}
	return (0);
}

int		sb(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	long long int temp;

	if (b->nb > 1 && a->doublon != 2)
	{
        a->doublon = 2;
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
		if (nb && ft_test(a, b, nb - 1, fct))
            return (1);
	}
	return (0);
}

int		ss(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	if (b->nb < 2 || a->nb < 2 || a->doublon == 1 || a->doublon == 2)
		return (0);
	sb(a, b, 0, NULL);
	sa(a, b, 0, NULL);
	if (nb == 1)
		return (0);
	if (ft_test(a, b, nb - 1, fct))
		return (1);
	return (0);
}
