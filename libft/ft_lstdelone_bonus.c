/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:03:00 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:51:15 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	lst->zero = 0;
	lst->minus = 0;
	lst->flag = 0;
	lst->error = 0;
	lst->width = 0;
	lst->preci = -1;
	lst->convert = 0;
	lst->flagn = 0;
	(*del)(lst->content);
	free(lst);
}
