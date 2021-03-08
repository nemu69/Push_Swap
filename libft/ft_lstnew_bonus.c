/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 19:03:47 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:58:51 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->content = content;
	lst->zero = 0;
	lst->minus = 0;
	lst->flag = 0;
	lst->flagn = 0;
	lst->error = 0;
	lst->width = 0;
	lst->preci = -1;
	lst->convert = 0;
	lst->next = NULL;
	return (lst);
}
