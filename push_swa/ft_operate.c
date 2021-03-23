/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/23 18:18:01 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int		ft_fill_bef(t_stack *a, t_stack *b, int nb)
//{
//	int i;

//	i = -1;
//	while (++i < a->nb)
//		a->before[nb - 1][i] = a->stack[i];
//	i = -1;
//	while (++i < a->nb)
//		b->before[nb - 1][i] = b->stack[i];
//	return (0);
//}

int		ft_gars(int *tempa, int *tempb, t_stack *a, t_stack *b)
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
	return (1);
}

void	ft_fill(int *tempa, int *tempb, t_stack *a, t_stack *b)
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
}

int topa(t_stack *a)
{
	int top;
	int i;
	int bottom;

	top = -1;
	bottom = a->nb - 1;
	while (++top < a->nb)
	{
		i = a->indchunk - 1;
		while (++i < a->maxnb - a->chunk)
		{
			if (a->stack[top] == a->sort[i])
				return (top);
			if (a->stack[bottom] == a->sort[i])
				return (bottom);
		}
		bottom--;
	}
	a->indchunk = a->chunk;
	a->chunk /= 2;
	return (-1);
}
int topb(t_stack *b)
{
	int top;
	int i;

	top = 0;
	i = 0;
	while (++i < b->nb)
		if (b->stack[top] < b->stack[i])
			top = i;
	//dprintf(1, "top : %d\n", top);
	return (top);
}

int		ft_pa(t_stack *a, t_stack *b)
{
	if (a->stack[0] > a->stack[1] && write(1, "sa\n", 3))
		sa(a, b, 0, NULL);
	//dprintf(1, "%d\n", a->chunk);
	//dprintf(1, "%d\n", a->indchunk);
	//sleep(5);
	
	while (!ft_sort(a, b->nb))
	{
		
		if (!(a->min = topb(b)))
			write(1, "pa\n", 3) && pa(a, b, 0, NULL);
		if (a->min == 1)
			write(1, "sb\n", 3) && sb(a, b, 0, NULL);
		else if (a->min > 1)
		{
			//return(1);
			if (a->min <= b->nb / 2)
			{
				//dprintf(1, "min : %d\n", a->min);
				while (topb(b))
				{
					a->min--;	
					rb(a, b, 0, NULL);
					write(1, "rb\n", 3);
				}
			}
			else
			{
				while (topb(b))
				{
					a->min++;	
					rrb(a, b, 0, NULL);
					write(1, "rrb\n", 4);
				}
			}
		}
	}
	return (1);
}

int		ft_pushb(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	pb(a, b, 0, fct);
	if (b->nb > 1 && b->stack[0] < b->stack[1] && write(1, "sb\n", 3))
		return (sb(a, b, nb, fct));
	return (ft_test(a, b, nb, fct));
}

int		ft_test(t_stack *a, t_stack *b, int nb, t_fct *fct)
{
	//int		taba[a->nb + 4];
	//int		tabb[b->nb + 4];
	t_fct	*temp;

	temp = fct;

	if (a->nb == 1)
		return (ft_pa(a, b));
	if (ft_sort(a, b->nb))
		return (1);
	//dprintf(1, "indchuck = %d\n", a->indchunk);
	//dprintf(1, "chuck = %d\n", a->chunk);
	//if (a->chunk == 0)
	//{
	//	for (int i = 0; i < a->nb; i++)
	//	{
	//		dprintf(1, "\n%lld", a->stack[i]);
	//	}
	//		dprintf(1, "\n\n");
	//	for (int i = 0; i < b->nb; i++)
	//	{
	//			dprintf(1, "%lld\n", b->stack[i]);

	//	}
		
		//sleep(3);
	//}
					usleep(50000);

	if (!(a->min = topa(a)))
		return (write(1, "pb\n", 3) && ft_pushb(a, b, nb, fct));
	//ft_fill(taba, tabb, a, b);
	if (a->min != -1 && a->min <= a->nb / 2)
	{
		while (a->min != 0)
		{
			a->min--;	
			ra(a, b, 0, fct);
			write(1, "ra\n", 3);
		}
	}
	else if (a->min != -1)
	{
		while (a->min != a->nb)
		{
			a->min++;	
			rra(a, b, 0, fct);
			write(1, "rra\n", 4);
		}
	}
	return (ft_test(a, b, nb, fct));
}
