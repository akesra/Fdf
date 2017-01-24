/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:06:22 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 17:50:36 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*pdst;
	const char	*psrc;

	i = 0;
	pdst = (char*)dst;
	psrc = (char*)src;
	if (src <= dst)
	{
		psrc = psrc + (len - 1);
		pdst = pdst + (len - 1);
		while (len != 0)
		{
			pdst[i] = psrc[i];
			i--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
