/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:21:19 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 16:32:29 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*x;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = ft_lstnew(((f)(lst))->content,
					((f)(lst))->content_size)))
		return (NULL);
	x = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(x->next = ft_lstnew(((f)(lst))->content,
						((f)(lst))->content_size)))
			return (NULL);
		x = x->next;
	}
	x->next = NULL;
	return (new_lst);
}
