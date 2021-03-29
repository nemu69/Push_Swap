/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/29 16:01:22 by nepage-l         ###   ########lyon.fr   */
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
	a->nb = ac - 1;
	a->chunk = (a->nb < 100 ? 2 : a->nb / 10);
	a->chunked = a->chunk;
	a->indchunk = 0;
	a->doublon = 42;
	a->tab = NULL;
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

int		lil_sort(t_stack *a, t_stack *b, int nb)
{
	int		taba[a->nb + 4];
	int		tabb[b->nb + 4];

	ft_fill(taba, tabb, a, b);
	if (ft_sort(a, b->nb))
		return (1);
	if (nb == 0)
		return (0);
	if (sa(a, b, nb) && (a->tab[nb] = ft_strdup("sa\n")))
		return (1);
	ft_gars(taba, tabb, a, b);
	if (ra(a, b, nb) && (a->tab[nb] = ft_strdup("ra\n")))
		return (1);
	ft_gars(taba, tabb, a, b);
	if (rra(a, b, nb) && (a->tab[nb] = ft_strdup("rra\n")))
		return (1);
	ft_gars(taba, tabb, a, b);
	if (pb(a, b, nb) && (a->tab[nb] = ft_strdup("pb\n")))
		return (1);
	ft_gars(taba, tabb, a, b);
	if (pa(a, b, nb) && (a->tab[nb] = ft_strdup("pa\n")))
		return (1);
	if (a->shell == nb)
		return (lil_sort(a, b, ++a->shell));
	return (0);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (0);
	if (!(a.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (ft_putstr("Error\n"));
	if (!(b.stack = (long long int *)malloc(sizeof(long long int) * ac - 1)))
		return (free_all(&a, NULL, -1) && ft_putstr("Error\n"));
	if (!init_a(&a, av, ac))
		return (free_all(&a, &b, -2) && ft_putstr("Error\n"));
	b.nb = 0;
	a.shell = shellsort(a.stack, a.nb);
	if (!ft_init_fct(&a, a.nb))
		return (free_all(&a, &b, -1) && ft_putstr("Error\n"));
	if (!init_a(&a, av, ac))
		return (free_all(&a, &b, -1) && ft_putstr("Error\n"));
	a.nb < 6 ? 0 : ft_operate(&a, &b, 0);
	if (a.shell != -1 && !(a.tab = calloc(sizeof(char *), a.shell + 2)))
		return (free_all(&a, &b, -1) && ft_putstr("Error\n"));
	a.nb < 6 ? lil_sort(&a, &b, a.shell) : 0;
	return (!free_all(&a, &b, a.shell));
}
