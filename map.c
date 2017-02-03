/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:19:55 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/02 10:13:00 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_stock_map(t_env *e, char **tmp, int y, int x)
{
	int i;

	i = 0;
	while (tmp[i] && x < e->xmax)
	{
		e->array[y][x] = ft_atoi(tmp[i]);
		x++;
		i++;
	}
	x = 0;
}

void ft_read_map(t_env *e, char *argv)
{
	int y;
	int x;
	char **tmp;
	int fd;
	char *line = NULL;

	fd = open(argv, O_RDONLY);
	x = 0;
	y = 0;
	tmp = NULL;
	e->array = (int**)malloc(sizeof(int*) * e->ymax); //+1 pas utile..
	while ((get_next_line(fd, &line)) > 0)
	{
		e->array[x] = (int*)malloc(sizeof(int) * e->xmax + 1);
		tmp = ft_strsplit(line, ' ');
		ft_stock_map(e, tmp, y, 0);
		ft_strdel(tmp);
		ft_strdel(&line);
		x++;
		y++;
	}
	close(fd);
}
