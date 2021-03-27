/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 14:23:59 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a->maxnb = a->nb;
	a->chunk = (a->nb % 2 == 0 ? a->nb / 10 : a->nb / 10 + 1);
	//a->chunk = 2;
	a->chunked = a->chunk;
	a->indchunk = 0;
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

//int		print_answer(char **tab, int ret)
//{
//	int i;

//	i = ret;
//	while (--i >= 0)
//	{
//		if (tab[i])
//			write(1, tab[i], ft_strlen(tab[i]));
//		free(tab[i]);
//	}
//	free(tab);
//	return (0);
//}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_fct	*fct;
	int		ret;

	if (ac == 1)
		return (0);
	if (!(a.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (ft_putstr("Error\n"));
	if (!(b.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (free_all(a.stack, NULL) && ft_putstr("Error\n"));
	if (!init_a(&a, av, ac))
		return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
	b.nb = 0;
	ret = shellsort(a.stack, a.nb);
	if (!ft_init_fct(&fct, &a, a.nb))
		return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
	if (!init_a(&a, av, ac))
		return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
	ft_test(&a, &b, ret, fct);
	//print_answer(a.tab, ret);
	return (!free_all(a.stack, b.stack));
}
