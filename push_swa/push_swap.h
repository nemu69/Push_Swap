/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:01:00 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/27 19:12:07 by nepage-l         ###   ########lyon.fr   */
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
	long long int	*stack;
	long long int	*sort;
	int				min;
	int				maxnb;
	int				chunk;
	int				chunked;
	int				indchunk;
	int				nb;
	int				doublon;
	char			**tab;
}					t_stack;

typedef	struct		s_fct
{
	int				(*fct_ptr)(t_stack*, t_stack*, int, struct s_fct *);
	char			*name;
	struct s_fct	*next;
}					t_fct;

int					ft_test(t_stack *a, t_stack *b, int nb);
int					free_all(t_stack *a, t_stack *b);
int					ft_sort(t_stack *a, int empty);
int					ft_init_fct(t_stack *a, int nb);
int					lil_sort(t_stack *a, t_stack *b, int nb);
int					ft_check_before(t_stack *a, t_stack *b, int nb);
int					pa(t_stack *a, t_stack *b, int nb);
int					pb(t_stack *a, t_stack *b, int nb);
int					ra(t_stack *a, t_stack *b, int nb);
int					rb(t_stack *a, t_stack *b, int nb);
int					rr(t_stack *a, t_stack *b, int nb);
int					rra(t_stack *a, t_stack *b, int nb);
int					rrb(t_stack *a, t_stack *b, int nb);
int					rrr(t_stack *a, t_stack *b, int nb);
int					sa(t_stack *a, t_stack *b, int nb);
int					sb(t_stack *a, t_stack *b, int nb);
int					ss(t_stack *a, t_stack *b, int nb);

#endif
