/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:27:40 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 18:09:22 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] && size != 0)
	{
		size--;
		i++;
	}
	if (size == 0)
		return (i + ft_strlen(src));
	while (src[j] != '\0' && size != 1)
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
