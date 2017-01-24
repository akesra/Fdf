/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:25:34 by akesraou          #+#    #+#             */
/*   Updated: 2016/11/17 20:27:24 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_write_words(char *words, char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
	{
		words[i] = s[i];
		i++;
	}
	words[i] = '\0';
}