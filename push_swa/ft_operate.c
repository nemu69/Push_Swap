/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/29 16:02:10 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		topa(t_stack *a)
{
	int top;
	int i;

	top = -1;
	while (++top < a->nb)
	{
		i = a->indchunk - 1;
		while (++i < a->chunk + 1)
			if (a->stack[top] == a->sort[i])
				return (top);
	}
	a->indchunk = a->chunk;
	a->chunk += a->chunked;
	return (-1);
}

int		topb(t_stack *b)
{
	int top;
	int i;

	top = 0;
	i = 0;
	while (++i < b->nb)
		if (b->stack[top] < b->stack[i])
			top = i;
	return (top);
}

int		ft_pa(t_stack *a, t_stack *b)
{
	while (b->nb)
	{
		if (!(a->min = topb(b)))
			write(1, "pa\n", 3) && pa(a, b, 0);
		if (a->min == 1)
			write(1, "sb\n", 3) && sb(a, b, 0);
		else if (a->min > 1)
		{
			if (a->min <= b->nb / 2)
			{
				while (a->min-- != 1)
					write(1, "rb\n", 3) && rb(a, b, 0);
				write(1, "sb\n", 3) && sb(a, b, 0);
			}
			else
				while (a->min++ != b->nb)
					write(1, "rrb\n", 4) && rrb(a, b, 0);
		}
	}
	return (1);
}

int		ft_pushb(t_stack *a, t_stack *b, int nb)
{
	pb(a, b, 0);
	return (ft_operate(a, b, nb));
}

int		ft_operate(t_stack *a, t_stack *b, int nb)
{
	a->shell = -1;
	if (a->nb == 0)
		return (ft_pa(a, b));
	if (ft_sort(a, b->nb))
		return (1);
	if (!(a->min = topa(a)))
		return (write(1, "pb\n", 3) && ft_pushb(a, b, nb));
	if (a->min != -1 && a->min <= a->nb / 2)
	{
		while (a->min-- != 0)
			write(1, "ra\n", 3) && ra(a, b, 0);
	}
	else if (a->min != -1)
		while (a->min++ != a->nb)
			write(1, "rra\n", 4) && rra(a, b, 0);
	return (ft_operate(a, b, nb));
}
