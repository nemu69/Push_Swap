/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:56:07 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/11 17:56:20 by nepage-l         ###   ########lyon.fr   */
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
    a->doublon = 42;
    return (check_a(a->stack, ac - 1));
}

void swap(long int *xp,long  int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int bubbleSort(long int *arr, int n) 
{ 
   int ret = 0;
   int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
            ret++;
        }
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
    return(ret);
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
    int ret = bubbleSort(a.stack, a.nb);
    if (!init_a(&a, av , ac))
        return (free_all(a.stack, b.stack) && ft_putstr("Error\n"));
    
    printf("return : %d\n", ret);
    printf("return : %d\n", ft_test(&a , &b, ret));
    for(int j = 0; j < a.nb; j++)
        {
            printf("%d : %ld\n", j,a.stack[j]);
        }
    printf("instruct : %d\n", a.instruct);
    return (0);
}