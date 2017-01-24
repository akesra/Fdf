/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:57:07 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/19 21:43:16 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static	char	*ft_copy(char const *s, int start, int end, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;

	start = 0;
	if (!s)
		return (NULL);
	if (s[start] == '\0')
		return (ft_copy(s, 0, 0, 0));
	end = ft_strlen(s);
	len = ft_strlen(s);
	while (ft_isspace(s[start]) == 1)
	{
		len--;
		start++;
	}
	if (len == 0)
		return (ft_strnew(0));
	while (ft_isspace(s[end - 1]) == 1)
	{
		len--;
		end--;
	}
	return (ft_copy(s, start, end, len));
}
