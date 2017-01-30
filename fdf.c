/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:29:00 by akesraou          #+#    #+#             */
/*   Updated: 2017/01/30 12:10:23 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>
#include </System/Library/Frameworks/Tk.framework/Versions/Current/Headers/X11/X.h>

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
	int		spacing;
	int r;
	int g;
	int b;
	int deep;
	int iso;
	int right;
//	int left;
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

int		key_fonction(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 69)
	{
		printf("keycode: %d\n", keycode);
		if (e->deep < 45)
			e->deep = e->deep + 1;
		//	e->r = e->r + 10;
		//	e->g = e->g - 10;
	/*	if (e->deep == 0)
		{
			e->r = 255;
			e->g = 0;
			e->b = 0;
		}
		if (e->deep > 0 && e->deep < 10)
		{
			e->r = 128;
			e->r = e->r + 5;
			e->g = 0;
			e->b = 0;
		}
		if (e->deep > 10 && e->deep < 20)
		{
			e->r = 220;
			e->r = e->r + 5;
			e->g = 20;
			e->b = 60;
		}
		if (e->deep > 20 && e->deep < 30)
		{
			e->r = 255;
			e->g = 240;
			e->b = 245;
		}
		if (e->deep > 30 && e->deep < 45)
		{
			e->r = 255;
			e->g = 255;
			e->b = 255;
		}*/
		printf("deep++ : %d\n", e->deep);
	}
	if (keycode == 78)
	{
		printf("keycode: %d\n", keycode);
		if (e->deep > - 13)
			e->deep = e->deep - 1;
			e->b = e->b + 5;
		printf("deep-- : %d\n", e->deep);
	}
	if (keycode == 125)
	{
		if (e->iso > 1)
			e->iso = e->iso - 1;
		printf("iso: %d\n", e->iso);
	}
	if (keycode == 126)
	{
		if (e->iso < 20)
			e->iso = e->iso + 1;
		printf("iso: %d\n", e->iso);
	}
	if (keycode == 124)
		e->right = e->right + 20;
	if (keycode == 123)
		e->right = e->right - 20;
//	if (keycode == 53)
//		mlx_clear_window(e->mlx, e->win);
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
	e->data[((x * e->bpp / 8) + (y * e->size_line))] = e->b;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 1] = e->g;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 2] = e->r;
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
	e->xx0 = (((*x0 + e->xmax) - *y0) * e->iso + e->right);
	e->yy0 = (((*x0 + e->xmax) + *y0) * e->iso)  - e->array[*y0][*x0] * e->deep;
	if (i == 1)
	{
		x1 = (*x0 + 1) + e->xmax;
		y1 = *y0;
		e->xx1 = ((x1 - y1) * e->iso + e->right);
		e->yy1 = ((x1 + y1) * e->iso) - e->array[*y0][*x0 + 1] * e->deep;
	}
	if (i == 0)
	{
		x1 = *x0 + e->xmax;
		y1 = *y0 + 1;
		e->xx1 = ((x1 - y1) * e->iso + e->right);
		e->yy1 = ((x1 + y1) * e->iso) - e->array[*y0 + 1][*x0] * e->deep;
	}
}

int		ft_draw_map_into_img(t_env *e)
{
	int x;
	int y;

	e->img = mlx_new_image(e->mlx, 1400, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	y = 0;
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

int		loop_hook(t_env *e)
{
	ft_draw_map_into_img(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	e = (t_env*)malloc(sizeof(t_env));
	e->r = 120;
	e->g = 120;
	e->b = 120;
	e->deep = 0;
	e->iso = 0;
	e->right = 0;
	e->mlx = mlx_init();
	ft_xymax(e, argv[1]);
	ft_map(e, argv[1]);
//	e->iso = 500 / sqrt(e->xmax * e->xmax + e->ymax * e->ymax);
/*	int i = 0;
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
	}*/
	e->win = mlx_new_window(e->mlx, 1400, 1000, "FdF");
	mlx_key_hook(e->win, key_fonction, e);
//	e->img = mlx_new_image(e->mlx, 2000, 1000);
//	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
//	ft_draw_map_into_img(e);
//	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
//	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
