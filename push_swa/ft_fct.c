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

void	ft_new_fct(t_fct **fct, int (*fct_ptr)(t_stack*, t_stack*))
{
	t_fct *temp;

	temp = *fct;
	if (!(*fct))
	{
		(*fct) = malloc(sizeof(t_fct));
		(*fct)->fct_ptr = fct_ptr;
		(*fct)->next = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_fct));
		temp->next->fct_ptr = fct_ptr;
		temp->next->next = NULL;
	}
}

void	ft_init_fct(t_fct **fct)
{
	ft_new_fct(fct, sa);
	ft_new_fct(fct, sb);
	ft_new_fct(fct, ss);
	ft_new_fct(fct, pa);
	ft_new_fct(fct, pb);
	ft_new_fct(fct, ra);
	ft_new_fct(fct, rb);
	ft_new_fct(fct, rr);
	ft_new_fct(fct, rra);
	ft_new_fct(fct, rrb;
	ft_new_fct(fct, rrr);
}