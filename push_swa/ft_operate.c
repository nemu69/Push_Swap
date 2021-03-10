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

int     ft_sort(t_stack *a, int empty)
{
    int i;

    i = -1;
    if (empty != 0)
        return (0);
    while (++i < a->nb - 1)
    {
        if (a->stack[i] > a->stack[i + 1])
            return (1);
    }
    return (2);
}

int     sa(t_stack *a, t_stack *b, int nb)
{
    long int temp;

    if (a->nb > 1)
    {
        temp = a->stack[0];
        a->stack[0] = a->stack[1];
        a->stack[1] = temp;
        if (ft_sort(a, b->nb) == 2)
            return (1);
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     sb(t_stack *a, t_stack *b, int nb)
{
    long int temp;
    if (b->nb > 1)
    {
        temp = b->stack[0];
        b->stack[0] = b->stack[1];
        b->stack[1] = temp;
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     ss(t_stack *a, t_stack *b, int nb)
{
    sb(a, b, nb);
    sa(a, b, nb);
    if (ft_sort(a, b->nb) == 2)
        return (1);
    if (ft_test(a, b, nb - 1))
        return (1);
    return (0);
}

int     pa(t_stack *a, t_stack *b, int nb)
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
        if (ft_sort(a, b->nb) == 2)
            return (1);
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     pb(t_stack *a, t_stack *b, int nb)
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
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     ra(t_stack *a, t_stack *b, int nb)
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
        if (ft_sort(a, b->nb) == 2)
            return (1);
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rb(t_stack *a, t_stack *b, int nb)
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
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rr(t_stack *a, t_stack *b, int nb)
{
    rb(a, b, nb);
    ra(a, b, nb);

    if (ft_sort(a, b->nb) == 2)
        return (1);
    if (nb == 1)
            return (0);
    if (ft_test(a, b, nb - 1))
        return (1);
    return (0);
}

int     rra(t_stack *a, t_stack *b, int nb)
{
    long int    temp;
    int         i;

    if (a->nb > 1)
    {
        i = 0;
        temp = a->stack[0];
        while (i != a->nb)
        {
            a->stack[i] = a->stack[i + 1];
            i++;
        }
        a->stack[a->nb - 1] = temp;
        if (ft_sort(a, b->nb) == 2)
            return (1);
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rrb(t_stack *a, t_stack *b, int nb)
{
    long int    temp;
    int         i;

    if (b->nb > 1)
    {
        i = 0;
        temp = b->stack[0];
        while (i != b->nb)
        {
            b->stack[i] = b->stack[i + 1];
            i++;
        }
        b->stack[b->nb - 1] = temp;
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rrr(t_stack *a, t_stack *b, int nb)
{
    rrb(a, b, nb);
    rra(a, b, nb);
    if (ft_sort(a, b->nb) == 2)
        return (1);
    if (nb == 1)
            return (0);
    if (ft_test(a, b, nb - 1))
        return (1);
    return (0);
}

void    ft_restart(t_stack tempa, t_stack tempb, t_stack *a, t_stack *b)
{
    int i;

    a->instruct = tempa.instruct;
    a->nb = tempa.nb;
    b->nb = tempb.nb;
    i = -1;
    while (++i < tempa.nb)
        a->stack[i] = tempa.stack[i];
    i = -1;
    while (++i < tempb.nb)
        b->stack[i] = tempb.stack[i];
}
void    ft_inittemp(t_stack *tempa, t_stack *tempb, t_stack *a, t_stack *b)
{
    int i;

    i = -1;
    while (++i < a->nb)
        tempa->stack[i] = a->stack[i];
    i = -1;
    while (++i < b->nb)
        tempb->stack[i] = b->stack[i];
    tempa->nb = a->nb;
    tempa->instruct = a->instruct;
    tempb->nb = b->nb;
}

int     ft_test(t_stack *a, t_stack *b, int nb)
{
    t_stack tempa;
    t_stack tempb;


    if (ft_sort(a, b->nb) == 2)
        return (1);
    if (nb == 0)
        return (0);
     if (!(tempb.stack = (long int *)malloc(sizeof(long int) * a->nb)))
        return (0);
     if (!(tempa.stack = (long int *)malloc(sizeof(long int) * a->nb)))
        return (0);
    ft_inittemp(&tempa, &tempb, a, b);
    if (sa(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (sb(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (ss(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (ra(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (rb(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (rr(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (rra(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (rrb(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (rrr(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (pa(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (pb(a, b, nb))
        return (1);
    ft_restart(tempa, tempb, a, b);
    if (a->instruct == nb)
    {
        a->instruct++;
        return (ft_test(a, b, nb + 1));
    }
    return (0);
}