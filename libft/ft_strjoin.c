/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:15:03 by akesraou          #+#    #+#             */
/*   Updated: 2016/12/19 09:08:19 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str_cat;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str_cat = (char*)malloc(sizeof(*str_cat) * (len + 1))))
			return (NULL);
		while (s1[i])
		{
			str_cat[i] = s1[i];
			i++;
		}
		while (s2[j])
			str_cat[i++] = s2[j++];
		str_cat[i] = '\0';
		return (str_cat);
	}
	else
		return (0);
}
