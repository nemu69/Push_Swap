/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:55:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/29 16:20:36 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = 0;
	j = -1;
	tempa[i++] = a->nb;
	tempa[i++] = b->nb;
	tempa[i++] = a->doublon;
	while (++j < a->nb)
		tempa[i + j] = a->stack[j];
	i = -1;
	while (++i < b->nb)
		tempb[i] = b->stack[i];
	return (0);
}

int	ft_gars(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = 0;
	j = -1;
	a->nb = tempa[i++];
	b->nb = tempa[i++];
	a->doublon = tempa[i++];
	while (++j < a->nb)
		a->stack[j] = tempa[i + j];
	i = -1;
	while (++i < b->nb)
		b->stack[i] = tempb[i];
	return (0);
}

int	ft_sort(t_stack *a, int empty)
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

int	free_all(t_stack *a, t_stack *b, int ret)
{
	if (a->stack)
		free(a->stack);
	if (b->stack)
		free(b->stack);
	if (ret != -2 && a->sort)
		free(a->sort);
	if (a->tab)
	{
		while (ret > -1 && a->tab[ret])
		{
			ft_putstr(a->tab[ret]);
			free(a->tab[ret]);
			ret--;
		}
		free(a->tab);
	}
	return (1);
}

int	ft_init_fct(t_stack *a, int nb)
{
	int i;

	i = -1;
	if (!(a->sort = malloc(sizeof(int) * nb)))
		return (0);
	while (++i < nb)
		a->sort[i] = a->stack[i];
	return (1);
}
