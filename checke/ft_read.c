/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/22 18:33:14 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_sort(t_stack *a, int empty)
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

int		ft_check_command(t_fct *fct, char *line, t_stack *a, t_stack *b)
{
	t_fct *temp;

	temp = fct;
	while (temp)
	{
		if (!ft_strcmp(temp->name, line))
		{
			write(1, line, ft_strlen(line));
			free(line);
			temp->fct_ptr(a, b);
			return (1);
		}
		temp = temp->next;
	}
	free(line);
	return (0);
}

void	ft_new_fct(t_fct **fct, int (*fct_ptr)(t_stack*, t_stack*), char *name)
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
	ft_new_fct(fct, sa, "sa");
	ft_new_fct(fct, sb, "sb");
	ft_new_fct(fct, ss, "ss");
	ft_new_fct(fct, pa, "pa");
	ft_new_fct(fct, pb, "pb");
	ft_new_fct(fct, ra, "ra");
	ft_new_fct(fct, rb, "rb");
	ft_new_fct(fct, rr, "rr");
	ft_new_fct(fct, rra, "rra");
	ft_new_fct(fct, rrb, "rrb");
	ft_new_fct(fct, rrr, "rrr");
}

int		ft_read_stack(t_stack *a, t_stack *b, char **line)
{
	t_fct	*fct;
	int		ret;

	fct = NULL;
	ft_init_fct(&fct);
	while (get_next_line(0, &(*line)))
	{
		ret = -1;
		if (!ft_check_command(fct, *line, a, b))
			return (free_all(a->stack, b->stack, fct) && ft_putstr("Error\n"));
		while (++ret < a->instruct)
		{
			write(1, "\n", 1);
			if (ret < a->nb)
				ft_putnbr_fd(a->stack[ret], 1);
			write(1, "  ", 1);
			if (ret < b->nb)
				ft_putnbr_fd(b->stack[ret], 1);
		}
		write(1, "\n--------\nA B\n\n", 15);
	}
	if (ft_sort(a, b->nb))
		return (free_all(a->stack, b->stack, fct) && ft_putstr("OK\n"));
	return (free_all(a->stack, b->stack, fct) && ft_putstr("KO\n"));
}
