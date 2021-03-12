/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:01:00 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/11 14:07:17 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef	struct		s_stack
{
	long int    *stack;
    int         nb;
    int         instruct;
    int         doublon;
}					t_stack;

typedef int (*fct_ptr)(t_stack*, t_stack*, int);


int     ft_test(t_stack *a, t_stack *b, int nb);

#endif
