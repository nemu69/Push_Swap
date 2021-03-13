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
	t_fct	*temp;

	temp = fct;
	if (ft_sort(a, b->nb))
		return (1);
	if (nb == 0)
		return (0);
	ft_inittemp(&tempa, &tempb, a, b);
	ft_fill(taba, tabb, a, b);
	while (1)
	{
		if (!temp)
			break; 
		if (temp->fct_ptr(a, b, nb, fct))
		{
			a->tab[nb - 1] = ft_strdup(temp->name);
			return (1);
		}
		ft_restart(tempa, tempb, a, b);
		ft_gars(taba, tabb, a, b);
		temp = temp->next;
	}
	return (0);
}
