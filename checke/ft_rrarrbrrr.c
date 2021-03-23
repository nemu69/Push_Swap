/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrarrbrrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:25:23 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/22 11:29:15 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		rra(t_stack *a, t_stack *b)
{
	long long int	temp;
	long long int	temp2;
	int				i;

	(void)b;
	if (a->nb > 1)
	{
		i = 0;
		temp = a->stack[i];
		while (i != a->nb)
		{
			temp2 = temp;
			temp = a->stack[i + 1];
			a->stack[i + 1] = temp2;
			i++;
		}
		a->stack[0] = temp2;
		return (1);
	}
	return (0);
}

int		rrb(t_stack *a, t_stack *b)
{
	long long int	temp;
	int				i;

	(void)a;
	if (b->nb > 1)
	{
		i = 0;
		temp = b->stack[0];
		while (i != b->nb)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->stack[b->nb - 1] = temp;
		return (1);
	}
	return (0);
}

int		rrr(t_stack *a, t_stack *b)
{
	rrb(a, b);
	rra(a, b);
	return (1);
}
