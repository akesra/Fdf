/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:17:34 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 16:15:26 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s01;
	unsigned char	*s02;

	i = 0;
	s01 = (unsigned char*)s1;
	s02 = (unsigned char*)s2;
	while (n != 0)
	{
		if (s01[i] != s02[i])
			return (s01[i] - s02[i]);
		else
			i++;
		n--;
	}
	return (0);
}
