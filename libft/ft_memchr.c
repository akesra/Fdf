/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:16:12 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 15:43:45 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	int				i;

	i = 0;
	s1 = (unsigned char*)s;
	while (n != 0)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
		n--;
	}
	return (NULL);
}
