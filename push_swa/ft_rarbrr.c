/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarbrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:22:27 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 18:12:29 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra(t_stack *a, t_stack *b, int nb)
{
	long long int	temp;
	int				i;

	if (a->nb > 1 && a->doublon != 7)
	{
		a->doublon = 5;
		temp = a->stack[0];
		i = 1;
		while (i != a->nb)
		{
			a->stack[i - 1] = a->stack[i];
			i++;
		}
		a->stack[a->nb - 1] = temp;
		if (nb && ft_test(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rb(t_stack *a, t_stack *b, int nb)
{
	long long int	temp;
	int				i;

	if (b->nb > 1 && a->doublon != 8)
	{
		a->doublon = 6;
		temp = b->stack[0];
		i = 1;
		while (i != b->nb)
		{
			b->stack[i - 1] = b->stack[i];
			i++;
		}
		b->stack[b->nb - 1] = temp;
		if (nb && ft_test(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rr(t_stack *a, t_stack *b, int nb)
{
	if (b->nb < 2 || a->nb < 2 || a->doublon == 8 || a->doublon == 7)
		return (0);
	rb(a, b, 0);
	ra(a, b, 0);
	if (nb == 1)
		return (0);
	if (ft_test(a, b, nb - 1))
		return (1);
	return (0);
}
