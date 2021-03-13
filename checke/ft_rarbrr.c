/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rarbrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:22:27 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 15:25:11 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ra(t_stack *a, t_stack *b)
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
		return (1);
	}
	return (0);
}

int		rb(t_stack *a, t_stack *b)
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
		return (1);
	}
	return (0);
}

int		rr(t_stack *a, t_stack *b)
{
	rb(a, b);
	ra(a, b);
	return (1);
}
