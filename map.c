/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:19:55 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/01 18:39:37 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_find_xmax(char *line)
{
	int i;
	int nx;

	i = 0;
	nx = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			nx++;
			while (line[i] != '\0' && line[i] != ' ')
				i++;
			i--;
		}
		i++;
	}
	return (nx);
}

int	ft_xymax(t_env *e, char *argv)
{
	int fd;
	int xline;
	char *line = NULL;
	int y;
	int h;

	y = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("No file found.\n");
		return (-1);
	}
	while ((get_next_line(fd, &line)) > 0)
	{
		xline = ft_find_xmax(line);
		if (y == 0)
			h = xline;
		if (xline != h)
		{
			ft_putstr("Wrong size of line. Exit.\n");
			return (-1);
		}
		ft_strdel(&line);
		y++;
	}
	if (xline == 0 && y == 0)
	{
		ft_putstr("No data found.\n");
		return (-1);
	}
	close(fd);
	e->xmax = xline;
	e->ymax = y;
	ft_putstr("xmax: ");
	ft_putnbr(xline);
	ft_putchar('\n');
	ft_putstr("ymax: ");
	ft_putnbr(y);
	return (0);
}

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

void ft_map(t_env *e, char *argv)
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
