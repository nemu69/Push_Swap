/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:54:40 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_sort(t_stack *a, int empty)
{
	int i;

	i = -1;
	if (empty != 0)
		return (0);
	while (++i < a->nb - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
	}
	return (1);
}

void    ft_restart(t_stack tempa, t_stack tempb, t_stack *a, t_stack *b)
{
	a->instruct = tempa.instruct;
	a->doublon = tempa.doublon;
	a->nb = tempa.nb;
	b->nb = tempb.nb;
}
void    ft_inittemp(t_stack *tempa, t_stack *tempb, t_stack *a, t_stack *b)
{
	tempa->nb = a->nb;
	tempa->instruct = a->instruct;
	tempa->doublon = a->doublon;
	tempb->nb = b->nb;
}

void    ft_gars(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	while (++i < a->nb)
		a->stack[i] = tempa[i];
	i = -1;
	while (++i < b->nb)
		b->stack[i] = tempb[i];
}
void    ft_fill(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	while (++i < a->nb)
		tempa[i] = a->stack[i];
	i = -1;
	while (++i < b->nb)
		tempb[i] = b->stack[i];

}

int     ft_test(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	t_stack tempa;
	t_stack tempb;
	int     taba[a->nb];
	int     tabb[b->nb];

	if (ft_sort(a, b->nb))
		return (1);
	if (nb == 0)
		return (0);
	ft_inittemp(&tempa, &tempb, a, b);
	ft_fill(taba, tabb, a, b);
	if (a->doublon != 1 && sa(a, b, nb, 1))
	{
		a->instruct++;
		write(1, "sa\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 7 && ra(a, b, nb, 1))
	{
		a->instruct++;
		write(1, "ra\n", 3);
		return (1);
	}

	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 5 && rra(a, b, nb, 1))
	{
		a->instruct++;
		write(1, "rra\n", 4);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 2 && sb(a, b, nb , 1))
	{
		a->instruct++;
		write(1, "sb\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 8 && rb(a, b, nb, 1))
	{
		a->instruct++;
		write(1, "rb\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 7 && a->doublon != 8 && rr(a, b, nb))
	{
		a->instruct++;
		write(1, "rr\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 1 && a->doublon != 2 && ss(a, b, nb))
	{
		a->instruct++;
		write(1, "ss\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 6 && rrb(a, b, nb, 1))
	{
		a->instruct++;
		write(1, "rrb\n", 4);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (a->doublon != 6 && a->doublon != 5 && rrr(a, b, nb))
	{
		a->instruct++;
		write(1, "rrr\n", 4);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (pa(a, b, nb))
	{
		a->instruct++;
		write(1, "pa\n", 3);
		return (1);
	}
	ft_restart(tempa, tempb, a, b);
	ft_gars(taba, tabb, a, b);
	if (pb(a, b, nb))
	{
		a->instruct++;
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}
