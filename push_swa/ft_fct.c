/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:55:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 18:20:09 by nepage-l         ###   ########lyon.fr   */
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

int	free_all(long long int *a, long long int *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
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
