/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/08 17:05:00 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_sort(t_stack *a)
{
    int i;

    i = -1;
    while (++i < a->nb)
    {
        if (a->stack[i] > a->stack[i + 1])
            return (1);
    }
    return (2);
}

int     sa(t_stack *a, t_stack *b)
{
    long int temp;

    if (a->nb > 1)
    {
        temp = a->stack[0];
        a->stack[0] = a->stack[1];
        a->stack[1] = temp;

        if (ft_sort(a) == 2)
            return (1);
        ft_test(a, b);
    }
    return (0);
}

int     sb(t_stack *a, t_stack *b)
{
    long int temp;

    if (b->nb > 1)
    {
        temp = b->stack[0];
        b->stack[0] = b->stack[1];
        b->stack[1] = temp;
        ft_test(a, b);
    }
    return (0);
}

int     ss(t_stack *a, t_stack *b)
{

    sb(a, b);
    sa(a, b);
    if (ft_sort(a) == 2)
        return (1);
    ft_test(a, b);
    return (0);
}

int     pa(t_stack *a, t_stack *b)
{
    int         i;

    if (b->nb > 0)
    {
        i = a->nb + 1;
        while (--i != 0)
            a->stack[i] = a->stack[i - 1];
        a->stack[0] = b->stack[0];
        a->nb++;
        i = 1;
        while (i != b->nb)
        {
            b->stack[i - 1] = b->stack[i];
            i++;
        }
        b->nb--;
        if (ft_sort(a) == 2)
            return (1);
        ft_test(a, b);
    }
    return (0);
}

int     pb(t_stack *a, t_stack *b)
{
    int         i;

    if (a->nb > 0)
    {
        i = a->nb + 1;
        while (--i != 0)
            b->stack[i] = b->stack[i - 1];
        b->stack[0] = a->stack[0];
        b->nb++;
        i = 1;
        while (i != a->nb)
        {
            a->stack[i - 1] = a->stack[i];
            i++;
        }
        a->nb--;
        ft_test(a, b);
    }
    return (0);
}

int     ra(t_stack *a, t_stack *b)
{
    long int    temp;
    int         i;

    if (a->nb > 1)
    {
        temp = a->stack[0];
        i = 1;
        while (i != a->nb)
        {
            a->stack[i - 1] = a->stack[i];
            i++;
        }
        a->stack[a->nb - 1] = temp;
        if (ft_sort(a) == 2)
            return (1);
        ft_test(a, b);
    }
    return (0);
}

int     rb(t_stack *a, t_stack *b)
{
    long int    temp;
    int         i;

    if (b->nb > 1)
    {
        temp = b->stack[0];
        i = 1;
        while (i != b->nb)
        {
            b->stack[i - 1] = b->stack[i];
            i++;
        }
        b->stack[b->nb - 1] = temp;
        ft_test(a, b);
    }
    return (0);
}

int     rr(t_stack *a, t_stack *b)
{
    rb(a, b);
    ra(a, b);

    if (ft_sort(a) == 2)
        return (1);
    ft_test(a, b);
    return (0);
}

int     rra(t_stack *a, t_stack *b)
{
    long int    temp;
    int         i;

    if (a->nb > 1)
    {
        temp = a->stack[a->nb - 1];
        i = 0;
        while (i != a->nb)
        {
            a->stack[i] = a->stack[i + 1];
            i++;
        }
        a->stack[0] = temp;
        if (ft_sort(a) == 2)
            return (1);
        ft_test(a, b);
    }
    return (0);
}

int     rrb(t_stack *a, t_stack *b)
{
    long int    temp;
    int         i;

    if (b->nb > 1)
    {
        temp = b->stack[b->nb - 1];
        i = 0;
        while (i != b->nb)
        {
            b->stack[i] = b->stack[i + 1];
            i++;
        }
        b->stack[0] = temp;
        ft_test(a, b);
    }
    return (0);
}

int     rrr(t_stack *a, t_stack *b)
{
    rrb(a, b);
    rra(a, b);
    if (ft_sort(a) == 2)
        return (1);
    ft_test(a, b);
    return (0);
}

int     ft_test(t_stack *a, t_stack *b)
{    
    if (sa(a, b) || sb(a, b) || ss(a, b) || ra(a, b) || rb(a, b) || rr(a, b) || rra(a, b) || rrb(a, b) || rrr(a, b) || pa(a, b) || pb(a, b))
    {
         for(int j = 0; j < a->nb; j++) {
        printf("%ld\n", a->stack[j]);
    }
    }
    return (0);
}