/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 22:11:06 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 22:00:39 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
