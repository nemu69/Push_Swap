/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:55:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 19:15:49 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	free_all(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a->stack)
		free(a->stack);
	if (b->stack)
		free(b->stack);
	if (a->sort)
		free(a->sort);
	if (a->tab)
	{
		
		while (a->tab[i])
		{
			dprintf(1, "%s\n", a->tab[i]);
			i++;
		}
		while (--i < 0)
		{
			ft_putstr(a->tab[i]);
			free(a->tab[i]);
		}
	}
	free(a->tab);
	return (1);
}

int	ft_init_tab(t_stack *a, int nb)
{
	int i;

	i = -1;
	if (!(a->sort = calloc(sizeof(int), nb)))
		return (0);
	while (++i < nb)
		a->sort[i] = a->stack[i];
	return (1);
}

int	ft_init_fct(t_stack *a, int nb)
{
	if (!ft_init_tab(a, nb))
		return (0);
	return (1);
}
