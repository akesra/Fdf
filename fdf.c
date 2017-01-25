/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:29:00 by akesraou          #+#    #+#             */
/*   Updated: 2017/01/25 19:12:16 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>

typedef		struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		xmax;
	int		ymax;
	int		x;
	int		y;
	int		z;
	int		**array;
	int		r;
	int		g;
	int		b;
}					t_env;


int		ft_strnumber(char *line)
{
	int i;
	int nx;

	i = 0;
	nx = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') && (line[i + 1] == '\0' || line[i + 1] == ' '))
			nx++;
		i++;
/*		if (line[i] >= '0' && line [i] <= '9')
		{
			nx++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		i++;*/
	}
	return (nx);
}

int		ft_xymax(t_env *e, char *argv)
{
	int fd;
	int xline;
	char *line = NULL;
	int x;
	int y;

	x = 0;
	y = 0;
	fd = open(argv, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		xline = ft_strnumber(line);
		if (xline > x)
			x = xline;
		if (line)
			ft_strdel(&line);//; a free ?
		y++;
	}
	close(fd);
	e->xmax = x;
	e->ymax = y;
	ft_putstr("xmax: ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("ymax: ");
	ft_putnbr(y);
	return (0);
}

void		ft_init_map(t_env *e, char **tmp, int y)
{
	int x;
	int i;

	x = 0;
	i = 0;
//	e->array[*y][x] = (int)malloc(sizeof(int) * e->xmax);
	while (tmp[i] && x < e->xmax)
	{
		e->array[y][x] = ft_atoi(tmp[i]);
		x++;
		i++;
	}/*
	while (x < e->xmax)
	{
		e->array[y][x] = 22; //chiffre invalide;
		x++;
	}*/
//	return (0);
}

void		ft_map(t_env *e, char *argv)
{
	int y;
	char **tmp;
	int fd;
	char *line;
	int x;

	fd = open(argv, O_RDONLY);
	x = 0;
	y = 0;
	tmp = (char**)malloc(sizeof(char*) * e->xmax);
//	e->array = (int**)malloc(sizeof(int*) * e->ymax); //+1?
	while ((get_next_line(fd, &line)) > 0)
	{
		e->array[y] = (int*)malloc(sizeof(int) * e->xmax + 1);
		tmp = ft_strsplit(line, ' ');
		if (tmp)
			ft_init_map(e, tmp, y);
	//	if (tmp)
	//		ft_strdel(tmp);
		ft_strdel(&line);
		y++;
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	int j;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	ft_xymax(e, argv[1]);
	ft_map(e, argv[1]);
	int i = 0;
	while (i < e->ymax)
	{
		j = 0;
		while (j < e->xmax)
		{
			printf("%d", e->array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
