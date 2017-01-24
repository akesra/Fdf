/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:14:29 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 17:29:13 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *tmp;
	t_list *tmp_free;

	tmp = *alst;
	while (tmp)
	{
		tmp_free = tmp;
		del(tmp->content, tmp->content_size);
		tmp = tmp->next;
		free(tmp_free);
	}
	*alst = NULL;
}
