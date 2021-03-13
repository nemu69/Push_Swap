/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 17:53:58 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_all(long long int *a, long long int *b)
{
	free(a);
	free(b);
	return (1);
}

int		check_a(long long int *a, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < nb)
	{
		if (a[i] < -2147483647 || a[i] > 2147483647)
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

	i = 1;
	while (av[i])
	{
		a->stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	a->nb = ac - 1;
	a->instruct = 0;
	a->doublon = 42;
	return (check_a(a->stack, ac - 1));
}

int		shellsort(long long *arr, int n)
{
	int	ret;
	int	gap;
	int	i;
	int	temp;
	int	j;

	gap = n / 2;
	ret = 0;
	while (gap > 0)
	{
		i = gap;
		while (i < n)
		{
			++ret ? temp = arr[i] : 0;
			j = i;
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			++i ? arr[j] = temp : 0;
		}
		gap /= 2;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_fct	*fct;
	int		ret;

	fct = NULL;
	ft_init_fct(&fct);
	if (ac == 1)
		return (ft_putstr("Error\n"));
	if (!(a.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (0);
	if (!(b.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (0);
	if (!init_a(&a, av, ac))
		return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
	b.nb = 0;
	ret = shellsort(a.stack, a.nb);
	if (!init_a(&a, av, ac))
		return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
	ft_test(&a, &b, ret, fct);
	return (0);
}
