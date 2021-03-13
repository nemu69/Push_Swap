/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:29:11 by aviscogl          #+#    #+#             */
/*   Updated: 2021/03/13 15:07:24 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef	struct		s_stack
{
	long long int	*stack;
	int				nb;
	int				instruct;
	int				doublon;
}					t_stack;

typedef	struct		s_fct
{
	int				(*fct_ptr)(t_stack*, t_stack*);
	char			*name;
	struct s_fct	*next;
}					t_fct;

int					ft_read_stack(t_stack *a, t_stack *b, char **line);
int					free_all(long long int *a, long long int *b, t_fct *fct);
int					rra(t_stack *a, t_stack *b);
int					rrb(t_stack *a, t_stack *b);
int					rrr(t_stack *a, t_stack *b);
int					ra(t_stack *a, t_stack *b);
int					rb(t_stack *a, t_stack *b);
int					rr(t_stack *a, t_stack *b);
int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);
int					sa(t_stack *a, t_stack *b);
int					sb(t_stack *a, t_stack *b);
int					ss(t_stack *a, t_stack *b);

#endif
