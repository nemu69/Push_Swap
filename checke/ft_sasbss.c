/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sasbss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:21:16 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/15 11:01:43 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		sa(t_stack *a, t_stack *b)
{
	long long int temp;

	(void)b;
	if (a->nb > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
		return (1);
	}
	return (0);
}

int		sb(t_stack *a, t_stack *b)
{
	long long int temp;

	(void)a;
	if (b->nb > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
		return (1);
	}
	return (0);
}

int		ss(t_stack *a, t_stack *b)
{
	sb(a, b);
	sa(a, b);
	return (1);
}
