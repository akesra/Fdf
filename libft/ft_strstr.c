/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:16:38 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/20 18:15:43 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s2[j] != '\0')
			{
				j++;
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
