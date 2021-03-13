/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:55:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:58:53 by nepage-l         ###   ########lyon.fr   */
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

int		free_all(long long int *a, long long int *b, t_fct *fct)
{
	t_fct *temp;

	free(a);
	free(b);
	if (fct)
	{
		while (fct)
		{
			temp = fct;
			fct = fct->next;
			free(temp);
		}
	}
	return (1);
}

void	ft_new_fct(t_fct **fct, int (*fct_ptr)(t_stack*, t_stack*, int, t_fct*), char *name)
{
	t_fct *temp;

	temp = *fct;
	if (!(*fct))
	{
		(*fct) = malloc(sizeof(t_fct));
		(*fct)->fct_ptr = fct_ptr;
		(*fct)->name = ft_strdup(name);
		(*fct)->next = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_fct));
		temp->next->fct_ptr = fct_ptr;
		temp->next->name = ft_strdup(name);
		temp->next->next = NULL;
	}
}

void	ft_init_fct(t_fct **fct)
{
	ft_new_fct(fct, sa, "sa\n");
	ft_new_fct(fct, ra, "ra\n");
	ft_new_fct(fct, rra, "rra\n");
	ft_new_fct(fct, pb, "pb\n");
	ft_new_fct(fct, rr, "rr\n");
	ft_new_fct(fct, rrr, "rrr\n");
	ft_new_fct(fct, ss, "ss\n");
	ft_new_fct(fct, pa, "pa\n");
	ft_new_fct(fct, sb, "sb\n");
	ft_new_fct(fct, rb, "rb\n");
	ft_new_fct(fct, rrb, "rrb\n");
}