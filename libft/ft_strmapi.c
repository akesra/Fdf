/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:06:06 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/16 17:12:01 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*str_new;

	i = 0;
	str = (char*)s;
	if (str == '\0')
		return (NULL);
	if (!(str_new = (char*)ft_strnew(sizeof(*str_new) * ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		str_new[i] = f(i, str[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
