/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:14:05 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/17 20:24:16 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*str;
	char	*str_new;

	i = 0;
	str = (char*)s;
	if (str == '\0')
		return (NULL);
	if (!(str_new = (char*)ft_strnew(sizeof(*str_new) * (ft_strlen(str)))))
		return (NULL);
	while (str[i])
	{
		str_new[i] = f(str[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
