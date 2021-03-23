/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:55:12 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/22 18:05:58 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int		ft_check_before(t_stack *a, t_stack *b, int nb)
//{
//	int i;
//	int j;
//	int same;

//	while (i > nb)
//	{
//		j = -1;
//		while (++j < a->nb)
//		{
//			if (a->before[i][j] != a->stack[j])
//				return (1);
//		}
//		j == a->nb ? same = 1 : 0;
//		j = -1;
//		while (++j < b->nb)
//		{
//			if (b->before[i][j] != b->stack[j])
//				return (1);
//		}
//		j == b->nb ? same += 1 : 0;
//		if (same == 2)
//			return (0);
//		i--;
//	}
//	return (1);
//}

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
	//if (fct)
	//{
	//	while (fct)
	//	{
	//		temp = fct;
	//		fct = fct->next;
	//		free(temp);
	//		free(temp->name);
	//	}
	//}
	return (1);
}

//int	fc(t_fct **fct, int (*fct_ptr)(t_stack*, t_stack*, int, t_fct*), char *name)
//{
//	t_fct *temp;

//	temp = *fct;
//	if (!(*fct))
//	{
//		(*fct) = malloc(sizeof(t_fct));
//		(*fct)->fct_ptr = fct_ptr;
//		(*fct)->name = ft_strdup(name);
//		(*fct)->next = NULL;
//	}
//	else
//	{
//		while (temp->next)
//			temp = temp->next;
//		temp->next = malloc(sizeof(t_fct));
//		temp->next->fct_ptr = fct_ptr;
//		temp->next->name = ft_strdup(name);
//		temp->next->next = NULL;
//	}
//	return (0);
//}

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

int	ft_init_fct(t_fct **fct, t_stack *a, int nb)
{
	*fct = NULL;
	if (!ft_init_tab(a, nb))
		return (0);
		
	//fc(fct, ra, "ra\n");
	
	//fc(fct, pb, "pb\n");
	//fc(fct, sa, "sa\n");
	//fc(fct, pa, "pa\n");
	//fc(fct, rra, "rra\n");
	//fc(fct, rr, "rr\n");
	//fc(fct, rrr, "rrr\n");
	//fc(fct, ss, "ss\n");
	//fc(fct, sb, "sb\n");
	//fc(fct, rb, "rb\n");
	//fc(fct, rrb, "rrb\n");
	return (1);
}
