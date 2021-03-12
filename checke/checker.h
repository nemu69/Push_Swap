/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:29:11 by aviscogl          #+#    #+#             */
/*   Updated: 2021/03/11 22:29:11 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef	struct		s_stack
{
	long int    *stack;
    int         nb;
    int         instruct;
    int         doublon;
}					t_stack;

typedef	struct		s_fct
{
	int (*fct_ptr)(t_stack*, t_stack*);
    char *name;
    struct s_fct *next;
}					t_fct;



int     ft_read_stack(t_stack *a, t_stack *b, char **line);
int     free_all(long int *a, long int *b, t_fct *fct);

#endif
