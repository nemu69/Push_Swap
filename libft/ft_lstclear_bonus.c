/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:11:06 by nepage-l          #+#    #+#             */
/*   Updated: 2021/03/13 14:51:15 by nepage-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cour;
	t_list	*suiv;

	cour = *lst;
	suiv = cour->next;
	while (cour)
	{
		suiv = cour->next;
		ft_lstdelone(cour, del);
		cour = suiv;
	}
	*lst = NULL;
}
