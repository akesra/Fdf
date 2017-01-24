/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:58:24 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 17:51:08 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (len == 0)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] && i < len)
	{
		while (s1[i + j] == s2[j] && s2[j] && i < len)
			j++;
		if (s2[j] == '\0' && i + j <= len)
			return ((char*)&s1[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
