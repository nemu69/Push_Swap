/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarbrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:22:27 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:47:47 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ra(t_stack *a, t_stack *b, int nb, int test)
{
	long long int	temp;
	int				i;

	(void)b;
	if (a->nb > 1)
	{
		temp = a->stack[0];
		i = 1;
		while (i != a->nb)
		{
			a->stack[i - 1] = a->stack[i];
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

int		rb(t_stack *a, t_stack *b, int nb, int test)
{
	long long int	temp;
	int				i;

	(void)a;
	if (b->nb > 1)
	{
		temp = b->stack[0];
		i = 1;
		while (i != b->nb)
		{
			b->stack[i - 1] = b->stack[i];
			i++;
		}
		b->stack[b->nb - 1] = temp;
		if (test && ft_sort(a, b->nb) == 2)
			return (1);
		if (test && ft_test(a, b, nb - 1))
			return (1);
	}
	return (0);
}

int		rr(t_stack *a, t_stack *b, int nb)
{
	if (b->nb < 2 || a->nb < 2)
		return (0);
	rb(a, b, nb, 0);
	ra(a, b, nb, 0);
	if (ft_sort(a, b->nb) == 2)
		return (1);
	if (nb == 1)
		return (0);
	if (ft_test(a, b, nb - 1))
		return (1);
	return (0);
}
