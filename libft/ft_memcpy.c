/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:09:07 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 16:13:06 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int			i;
	char		*pdst;
	const char	*psrc;

	i = 0;
	pdst = (char*)dst;
	psrc = (const char*)src;
	while (n != 0)
	{
		pdst[i] = psrc[i];
		i++;
		n--;
	}
	return (pdst);
}
