/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:53:48 by tlapierr          #+#    #+#             */
/*   Updated: 2017/01/09 16:39:34 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nb_words(const char *s, char c)
{
	int		nb_words;
	size_t	i;
	size_t	size_s;

	nb_words = 0;
	i = 0;
	size_s = ft_strlen(s);
	while (i < size_s)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int		ft_nb_letters(const char *s, char c, size_t pos)
{
	size_t	i;
	int		nb_letters;

	i = pos;
	nb_letters = 0;
	while (s[i] != c && s[i] != '\0')
	{
		nb_letters++;
		i++;
	}
	return (nb_letters);
}

static char		*ft_fill_string(const char *s, char c, size_t pos)
{
	char	*word;
	size_t	size;

	size = ft_nb_letters(s, c, pos);
	word = ft_strnew(size);
	if (word == NULL)
		return (NULL);
	ft_strncpy(word, s + pos, size);
	return (word);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (j < (size_t)ft_nb_words(s, c) && s[i] != '\0')
	{
		if (s[i] != c)
		{
			tab[j] = ft_fill_string(s, c, i);
			i += ft_strlen(tab[j]);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
