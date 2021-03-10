/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/08 16:41:12 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     free_all(long int *a, long int *b)
{
    free(a);
    free(b);
    return (1);
}

int     check_a(long int *a, int nb)
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

int    init_a(t_stack *a, char **av , int ac)
{
    int i;

    i = 1;
    while (av[i])
    {
        a->stack[i - 1] = ft_atoi(av[i]);
        i++;
    }
    a->nb = ac - 1;
    a->instruct = 1;
    return (check_a(a->stack, ac - 1));
}

int     main(int ac, char **av)
{
    t_stack a;
    t_stack b;
    if (ac == 1)
        return (ft_putstr("Error\n"));
    if (!(a.stack = (long int *)malloc(sizeof(long int) * ac - 1)))
        return (0);
    if (!(b.stack = (long int *)malloc(sizeof(long int) * ac - 1)))
        return (0);
    if (!init_a(&a, av , ac))
        return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
    b.nb = 0;
    printf("return : %d\n", ft_test(&a , &b, 1));
    printf("instruct : %d\n", a.instruct);
     for(int j = 0; j < a.nb; j++)
        {
            printf("%d : %ld\n", j,a.stack[j]);
        }
    return (0);
}