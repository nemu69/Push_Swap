/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:28:51 by aviscogl          #+#    #+#             */
/*   Updated: 2021/03/27 19:13:33 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		free_all(long long int *a, long long int *b, t_fct *fct)
{
	t_fct *temp;

	if (a)
		free(a);
	if (b)
		free(b);
	if (fct)
	{
		while (fct)
		{
			temp = fct;
			fct = fct->next;
			free(temp->name);
			free(temp);
		}
	}
	return (1);
}

int		check_a(long long int *a, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < nb)
	{
		if (a[i] < -2147483648 || a[i] > 2147483647)
			return (0);
		j = i + 1;
		while (j < nb)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		init_a(t_stack *a, char **av, int ac)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || av[i][j] == '+' || av[i][j] == '-')
				j++;
			else
				return (0);
		}
		a->stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	a->nb = ac - 1;
	a->instruct = ac - 1;
	a->doublon = 42;
	return (check_a(a->stack, ac - 1));
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		*line;

	if (ac == 1)
		return (0);
	if (!(a.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (ft_putstr("Error\n"));
	if (!(b.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (free_all(a.stack, NULL, NULL) && ft_putstr("Error\n"));
	if (!init_a(&a, av, ac))
		return (free_all(a.stack, b.stack, NULL) && ft_putstr("Error\n"));
	b.nb = 0;
	return (ft_read_stack(&a, &b, &line));
}
