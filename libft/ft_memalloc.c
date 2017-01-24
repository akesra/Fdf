/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:39:07 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/13 23:24:58 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(*dest) * size)))
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
