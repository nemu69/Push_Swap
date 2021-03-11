/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/11 17:26:24 by nepage-l         ###   ########lyon.fr   */
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
            return (0);
    }
    return (1);
}

int     sa(t_stack *a, t_stack *b, int nb, int test)
{
    long int temp;

    // to do doublons operate useless
    if (a->nb > 1)
    {
        a->doublon = 1;
        temp = a->stack[0];
        a->stack[0] = a->stack[1];
        a->stack[1] = temp;
        if (test && ft_sort(a, b->nb) == 2)
            return (1);        
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     sb(t_stack *a, t_stack *b, int nb, int test)
{
    long int temp;

    // to do doublons operate useless
    if (b->nb > 1)
    {
        a->doublon = 2; 
        temp = b->stack[0];
        b->stack[0] = b->stack[1];
        b->stack[1] = temp;
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     ss(t_stack *a, t_stack *b, int nb)
{
    // to do doublons operate useless
    // warniing dont ft_test for this
    if (b->nb < 2 || a->nb < 2 || a->doublon == 1 || a->doublon == 2)
        return (0);
    a->doublon = 1;
    sb(a, b, nb, 0);
    sa(a, b, nb, 0);
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
        a->doublon = 3;
        i = a->nb;
        while (i > 0)
        {
            a->stack[i] = a->stack[i - 1];
            i--;
        }
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

        //                 printf("\n\n");
        // for(int j = 0; j < a->nb; j++)
        // {
        //     printf("pa%d : %ld    ", j,a->stack[j]);
        //     if (j < b->nb)
        //         printf("%ld\n",b->stack[j]);
        //     else
        //         printf("\n");
        // }
            // printf("%d\n", nb);
            // sleep(1);
        
        a->doublon = 4;
        i = b->nb;
        while (i > 0)
        {
            b->stack[i] = b->stack[i - 1];
            i--;
        }
        b->stack[0] = a->stack[0];
        b->nb++;
        i = 1;
        while (i != a->nb)
        {
            a->stack[i - 1] = a->stack[i];
            i++;
        }
        a->nb--;
        //     for(int j = 0; j < a->nb; j++)
        // {
        //     printf("%d : %ld    ", j,a->stack[j]);
        //     if (j < b->nb)
        //         printf("%ld\n",b->stack[j]);
        //     else
        //         printf("\n");
        // }
        //     printf("\n\n");
        if (ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     ra(t_stack *a, t_stack *b, int nb, int test)
{
    long int    temp;
    int         i;

    // to do tour du monde useless
    if (a->nb > 1)
    {
        a->doublon = 5;
        temp = a->stack[0];
        i = 1;
        while (i != a->nb)
        {
            a->stack[i - 1] = a->stack[i];
            i++;
        }
        a->stack[a->nb - 1] = temp;
        if (test && ft_sort(a, b->nb) == 2)
            return (1);
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rb(t_stack *a, t_stack *b, int nb, int test)
{
    long int    temp;
    int         i;

    // to do tour du monde useless

    if (b->nb > 1)
    {
        a->doublon = 6;
        temp = b->stack[0];
        i = 1;
        while (i != b->nb)
        {
            b->stack[i - 1] = b->stack[i];
            i++;
        }
        b->stack[b->nb - 1] = temp;
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rr(t_stack *a, t_stack *b, int nb)
{
    // to do same warning useless
    if (b->nb < 2 || a->nb < 2)
        return (0);
    rb(a, b, nb, 0);
    ra(a, b, nb, 0);

    if (ft_sort(a, b->nb) == 2)
        return (1);
    if (nb == 1)
            return (0);
    if (ft_test(a, b, nb - 1))
        return (1);
    return (0);
}

int     rra(t_stack *a, t_stack *b, int nb, int test)
{
    long int    temp;
    int         i;
    // to do tour du monde useless

    if (a->nb > 1)
    {
        a->doublon = 7;
        i = 0;
        temp = a->stack[0];
        while (i != a->nb)
        {
            a->stack[i] = a->stack[i + 1];
            i++;
        }
        a->stack[a->nb - 1] = temp;
        if (test && ft_sort(a, b->nb) == 2)
            return (1);
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rrb(t_stack *a, t_stack *b, int nb, int test)
{
    long int    temp;
    int         i;
    // to do tour du monde useless

    if (b->nb > 1)
    {
        a->doublon = 8;
        i = 0;
        temp = b->stack[0];
        while (i != b->nb)
        {
            b->stack[i] = b->stack[i + 1];
            i++;
        }
        b->stack[b->nb - 1] = temp;
        if (test && ft_test(a, b, nb - 1))
            return (1);
    }
    return (0);
}

int     rrr(t_stack *a, t_stack *b, int nb)
{
    // to do same warning useless

    a->doublon = 6;
    rrb(a, b, nb, 0);
    rra(a, b, nb, 0);
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
    a->instruct = tempa.instruct;
    a->doublon = tempa.doublon;
    a->nb = tempa.nb;
    b->nb = tempb.nb;
}
void    ft_inittemp(t_stack *tempa, t_stack *tempb, t_stack *a, t_stack *b)
{
    tempa->nb = a->nb;
    tempa->instruct = a->instruct;
    tempa->doublon = a->doublon;
    tempb->nb = b->nb;
}

void    ft_gars(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
    int i;

    i = -1;
    while (++i < a->nb)
        a->stack[i] = tempa[i];
    i = -1;
    while (++i < b->nb)
        b->stack[i] = tempb[i];
}
void    ft_fill(int *tempa, int *tempb, t_stack *a, t_stack *b)
{
    int i;

    i = -1;
    while (++i < a->nb)
        tempa[i] = a->stack[i];
    i = -1;
    while (++i < b->nb)
        tempb[i] = b->stack[i];

}

int     ft_test(t_stack *a, t_stack *b, int nb)
{
    t_stack tempa;
    t_stack tempb;
    int     taba[a->nb];
    int     tabb[b->nb];

    if (ft_sort(a, b->nb))
        return (1);
    if (nb == 0)
        return (0);
    ft_inittemp(&tempa, &tempb, a, b);
    ft_fill(taba, tabb, a, b);
    if (a->doublon != 1 && sa(a, b, nb, 1))
    {
        a->instruct++;
        write(1, "sa\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 7 && ra(a, b, nb, 1))
    {
        a->instruct++;
        write(1, "ra\n", 3);
        return (1);
    }
    
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 5 && rra(a, b, nb, 1))
    {
        a->instruct++;
        write(1, "rra\n", 4);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 2 && sb(a, b, nb , 1))
    {
        a->instruct++;
        write(1, "sb\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 8 && rb(a, b, nb, 1))
    {
        a->instruct++;
        write(1, "rb\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 7 && a->doublon != 8 && rr(a, b, nb))
    {
        a->instruct++;
        write(1, "rr\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 1 && a->doublon != 2 && ss(a, b, nb))
    {
        a->instruct++;
        write(1, "ss\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 6 && rrb(a, b, nb, 1))
    {
        a->instruct++;
        write(1, "rrb\n", 4);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (a->doublon != 6 && a->doublon != 5 && rrr(a, b, nb))
    {
        a->instruct++;
        write(1, "rrr\n", 4);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (pa(a, b, nb))
    {
        a->instruct++;
        write(1, "pa\n", 3);
        return (1);
    }
    ft_restart(tempa, tempb, a, b);
    ft_gars(taba, tabb, a, b);
    if (pb(a, b, nb))
    {
        a->instruct++;
        write(1, "pb\n", 3);
        return (1);
    }
    

//     ft_restart(tempa, tempb, a, b);
// ft_gars(taba, tabb, a, b);
    // if (a->instruct == 8 && nb == 8)
    // if (a->instruct == nb)
    // {
    //     write(1, "rrr\n", 4);
    //     a->instruct++;
    //     return (ft_test(a, b, nb + 1));
    // }
    return (0);
}