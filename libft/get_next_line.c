/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:23:59 by akesraou          #+#    #+#             */
/*   Updated: 2017/01/19 18:29:59 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_gnlist		*ft_multi_fd(t_gnlist **list, const int fd)
{
	t_gnlist *elem;
	t_gnlist *last_elem;

	elem = *list;
	last_elem = NULL;
	if (fd < 0)
		return (NULL);
	while (elem)
	{
		if (fd == elem->fd)
			return (elem);
		last_elem = elem;
		elem = elem->next;
	}
	if (!(elem = (t_gnlist*)malloc(sizeof(*elem))))
		return (NULL);
	elem->fd = fd;
	elem->str = NULL;
	elem->next = NULL;
	if (*list)
		last_elem->next = elem;
	else
		*list = elem;
	return (elem);
}

static	int				ft_check_str(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			if (i == 0)
				*line = ft_strnew(0);
			else
			{
				if (!(*line = ft_strsub(*str, 0, i)))
					return (-1);
			}
			if (!(tmp = ft_strdup(&((*str)[i + 1]))))
				return (-1);
			ft_strdel(str);
			*str = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

static	int				ft_check_buffer(char **buffer, char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*buffer)[i])
	{
		if ((*buffer)[i] == '\n')
		{
			(*buffer)[i] = '\0';
			if (!(*line = ft_strjoin(*str, *buffer)))
				return (-1);
			ft_strdel(str);
			if (!(*str = ft_strdup(&((*buffer)[i + 1]))))
				return (-1);
			free(*buffer);
			return (1);
		}
		i++;
	}
	if (!(tmp = ft_strjoin(*str, *buffer)))
		return (-1);
	ft_strdel(str);
	*str = tmp;
	return (0);
}

static	int				ft_check_eof(int oct, char **str, char **line)
{
	if (oct == -1)
		return (-1);
	if (oct == 0 && **str)
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
		return (1);
	}
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnlist	*list = NULL;
	char			*buffer;
	int				oct;
	t_gnlist		*elem;
	int				n;

	if (!(elem = ft_multi_fd(&list, fd)))
		return (-1);
	if (elem->str)
	{
		if ((n = ft_check_str(&elem->str, line)) == 1 || n == -1)
			return (n);
	}
	else
		elem->str = ft_strnew(BUFF_SIZE);
	if (!(buffer = ft_strnew(BUFF_SIZE)) || !(elem->str))
		return (-1);
	while ((oct = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[oct] = '\0';
		if ((n = ft_check_buffer(&buffer, &elem->str, line)) == 1 || n == -1)
			return (n);
	}
	ft_strdel(&buffer);
	return (ft_check_eof(oct, &elem->str, line));
}
