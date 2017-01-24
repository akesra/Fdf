/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:19:53 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 18:05:45 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(dest, s1));
}
