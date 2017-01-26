/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:29:00 by akesraou          #+#    #+#             */
/*   Updated: 2017/01/26 12:18:35 by akesraou         ###   ########.fr       */
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
	int		**array;
	int		bpp;
	int		size_line;
	int		endian;
	int		xx0;
	int		xx1;
	int		yy0;
	int		yy1;
}					t_env;


int		ft_find_xmax(char *line)
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
	}
	return (nx);
}

int		ft_xymax(t_env *e, char *argv)
{
	int fd;
//	int xline;
	char *line = NULL;
	int x;
	int y;

	x = 0;
	y = 0;
	fd = open(argv, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		/*xline*/x = ft_find_xmax(line);
	/*	if (xline > x)
			x = xline;*/ //faire ce calcul du max si ligne de taille differente ? ou message d'erreur?
		ft_strdel(&line);
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

void		ft_stock_map(t_env *e, char **tmp, int y, int x)
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

void		ft_map(t_env *e, char *argv)
{
	int y;
	char **tmp;
	int fd;
	char *line = NULL;

	fd = open(argv, O_RDONLY);
	y = 0;
	tmp = NULL;
	e->array = (int**)malloc(sizeof(int*) * e->ymax); //+1 pas utile..
	while ((get_next_line(fd, &line)) > 0)
	{
		e->array[y] = (int*)malloc(sizeof(int) * e->xmax + 1);
		tmp = ft_strsplit(line, ' ');
		ft_stock_map(e, tmp, y, 0);
		ft_strdel(tmp);
		ft_strdel(&line);
		y++;
	}
	close(fd);
}

int		key_fonction(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 53)
		mlx_clear_window(e->mlx, e->win);
	return (0);
}

int		ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * - 1); //ou -nb? lequel est le plus propre?
}

void	ft_pixel_put_image(t_env *e, int x, int y)
{
	e->data[((x * e->bpp / 8) + (y * e->size_line))] = 255;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 1] = 255;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 2] = 255;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 3] = 0;
}

void	ft_draw_lines(t_env *e)
{
	//algo de bresenham -
	int dx = ft_abs(e->xx1 - e->xx0), sx = e->xx0 < e->xx1 ? 1 : -1;
	int dy = ft_abs(e->yy1 - e->yy0), sy = e->yy0 < e->yy1 ? 1 : -1;
	int err = (dx > dy ? dx : - dy ) / 2, e2;

	for(;;){
		ft_pixel_put_image(e, e->xx0, e->yy0);
		if (e->xx0 == e->xx1 && e->yy0 == e->yy1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; e->xx0 += sx; }
		if (e2 < dy) { err += dx; e->yy0 += sy; }
	}
}

void	ft_isomeshit(t_env *e, int *x0, int *y0, int i)
{
	int x1;
	int y1;
	//formule isometrie  http://clintbellanger.net/articles/isometric_math/
	//fait ces calculs a la main pour qlq points pour voir comment ca fonctionne
	e->xx0 = (*x0 - *y0) * 20;
	e->yy0 = (*x0 + *y0) * 20;
	if (i == 1) //iso qui s'affiche sur la gauche de la fenetre..
	{
		x1 = *x0 + 1;
		y1 = *y0;
		e->xx1 = (x1 - y1) * 20;// - e->array[*y0][*x0 + 1] * 2;
		e->yy1 = ((x1 + y1) * 20) - e->array[*y0][*x0 + 1] * 2; // le tableau contient donc la valeur du z (0 ou 10 pour 42.fdf). tu peux faire" - e->array.. " pour la profondeur, si tu fais "*" ca marchera pas car ca fausse l'equation
	}
	if (i == 0)// iso qui s'affiche sur la droite de la fenetre..
	{
		x1 = *x0;
		y1 = *y0 + 1;
		e->xx1 = (x1 - y1) * 20;// - e->array[*y0 + 1][*x0] * 2;
		e->yy1 = ((x1 + y1) * 20) - e->array[*y0 + 1][*x0] * 2;
	}
}

int		ft_draw_map_into_img(t_env *e)
{
	int x;
	int y;

	y = 0;
	e->img = mlx_new_image(e->mlx, 1000, 800);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	while (y < e->ymax)
	{
		x = 0;
		while (x < e->xmax)
		{
			if (x + 1 < e->xmax)
			{
				ft_isomeshit(e, &x, &y, 1);
				ft_draw_lines(e);
			}
			if (y + 1 < e->ymax)
			{
				ft_isomeshit(e, &x, &y, 0);
				ft_draw_lines(e);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
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
	e->win = mlx_new_window(e->mlx, 1000, 800, "FdF");
	mlx_key_hook(e->win, key_fonction, e);
	ft_draw_map_into_img(e);
	mlx_loop(e->mlx);
	return (0);
}
