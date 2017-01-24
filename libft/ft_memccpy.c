/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:03:36 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 16:11:27 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*pdest;
	const char		*psrc;

	i = 0;
	pdest = (unsigned char*)dest;
	psrc = (const char*)src;
	while (n != 0)
	{
		if (psrc[i] != c)
		{
			pdest[i] = psrc[i];
			i++;
		}
		else
		{
			pdest[i] = psrc[i];
			return (&pdest[i + 1]);
		}
		n--;
	}
	return (0);
}
/*
**copy src dans dest jusqu'a ce que le caractere recherche = celui de
**src quon copie, on renvoie alors pointeur sur le caractere d apres.
**Pour eviter le chevauchement
*/
