/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:54:20 by akesraou          #+#    #+#             */
/*   Updated: 2016/12/20 19:00:31 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>

typedef		struct	s_env
{
	void *mlx;
	void *win;
	void *img;
	char *data;
	char ***array;
	int spacing;
}					t_env;

typedef		struct	s_point
{
	int xmax;
	int ymax;
	int x;
	int y;
	int z;
	int X;
	int Y;
}					t_point;

void	ft_pixel_put_image(t_env *e,/* t_point coord,*/ int x, int y, int *bpp, int *size_line)
{
	//	ft_putstr("X= ");
	//	ft_putnbr(coord.X);
	//	ft_putstr("\nY= ");
	//	ft_putnbr(coord.y);
	//	ft_putchar('\n');
	//	ft_putnbr(e->spacing);
	//	ft_putchar('\n');
	e->data[((x * *bpp / 8)/*e->spacing*/ + ((y * *size_line)/*e->spacing*/))] = 255;
	e->data[((x * *bpp / 8)/*e->spacing*/ + ((y * *size_line)/*e->spacing*/)) + 1] = 255;
	e->data[((x * *bpp / 8)/*e->spacing*/ + ((y * *size_line)/*e->spacing*/)) + 2] = 255;
	e->data[((x * *bpp / 8)/*e->spacing*/ + ((y * *size_line)/*e->spacing*/)) + 3] = 0;
	//	e->data[(/*((coord.x * *bpp / 8) * e->spacing + (coord.y * *size_line * e->spacing))*/coord.X + coord.Y)] = 255;
	//	e->data[(/*(((coord.x * *bpp / 8) * e->spacing + (coord.y * *size_line * e->spacing)) + 1)*/coord.X + coord.Y + 1)] = 255;
	//	e->data[(/*(((coord.x * *bpp / 8) * e->spacing + (coord.y * *size_line * e->spacing)) + 2)*/coord.X + coord.Y + 2)] = 255;
	//	e->data[(/*(((coord.x * *bpp / 8) * e->spacing + (coord.y * *size_line * e->spacing)) + 3)*/coord.X + coord.Y + 3)] = 0;
}

int		key_function(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 8)
		mlx_clear_window(e->mlx, e->win);
	return (0);
}

int		ft_nb_line(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	close(fd);
	return (i);
}

char	***ft_stock_map(int fd, char **line, t_point *coord)
{
	int i;
	int j;
	char ***array;
	char **tmp;

	i = 0;
	array = (char***)malloc(sizeof(char**) * (coord->ymax + 1));
	while ((get_next_line(fd, line)) > 0 && !(j = 0))
	{
		tmp = ft_strsplit(*line, ' ');
		while (tmp[j])
			j++;
		coord->xmax = j;
		array[i] = (char**)malloc(sizeof(char*) * (j + 1));
		j = 0;
		while (tmp[j])
		{
			array[i][j] = ft_strdup(tmp[j]);
			j++;
		}
		array[i][j] = NULL;
		ft_strdel(line);
		i++;
	}
	array[i] = NULL;
	close(fd);
	return (array);
}
/*void	ft_trad(t_env *e, int x1, int )
{
	//	ft_putstr("spacing\n");
	//	ft_putnbr(e->spacing);
	//	ft_putstr("size_line: ");
	//	ft_putnbr(*size_line);
	coord->z = ft_atoi(e->array[coord->y][coord->x]);
	//	ft_putstr("Z= ");
	//	ft_putnbr(coord->z);
	//	ft_putchar('\n');
	coord->x = coord->x;// + 1 * coord->z;
	coord->y = coord->y;// + 1/2 * coord->z;
	//	coord->X = coord->x * *bpp / 8 * 30 + 1 * coord->z;
	//	coord->Y = coord->y * *size_line * 30 + 1/2 * coord->z;
	//	coord->X = 1 * coord->x * *bpp / 8 * 10 + 1 * coord->y * *size_line * 10;
	//	ft_putstr("X\n");
	//	coord->Y = coord->z + 1/2 * coord->x * *bpp / 8 * 10 + 1/2 * coord->y * *size_line * 10;
	//	ft_putstr("Y\n");
}*/

//if (x1 == x2 && y1 != y2) //verticl
/*void	ft_vertic(t_env e, int x1, int y1, int x2, int y2, int *bpp, int *size_line)
{
	int y;

	y = y1;
	if (y1 > y2)
		ft_vertical(e, x1, y2, x2, y1, bpp, size_line);
	while (y < y2)
	{
		ft_pixel_put_image(&e, x1, y, bpp, size_line);
		y++;
	}
}
//	else if (x1 != x2 && y1 == y2) //horizontal
void	ft_horiz(t_env e, int x1, int y1, int x2, int y2, int *bpp, int *size_line)
{
	int x;

	if (x1 > x2)
		ft_horiz(e, x2, y1, x1, y2, bpp, size_line);
	x = x1;
	while (x <= x2)
	{
		ft_pixel_put_image(&e, x, y1, bpp, size_line);
		x++;
	}
}

void	ft_en_biais(t_env e, int x1, int y1, int x2, int y2, int *bpp, int *size_line) //(x2 > x1 && y2 > y1)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		ft_pixel_put_image(&e, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), bpp, size_line);
		x++;
	}
}*/
/*{
  int x;
  int y;
  double a, b;

  a = (double) (y2 - y1) / (x2 - x1);
  b = y1 - a * x1;
  x = x1;
  while (x < x2)
  {
  y = (int) (a * x + b);
//		mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
ft_pixel_put_image(&e, x, y1, bpp, size_line);
x++;
}
}*/

void	ft_droite(t_env *e, int x0, int y0, int x1, int y1, int *bpp, int *size_line)
{

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;){
		ft_pixel_put_image(e, x0, y0, bpp, size_line);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

int main(int argc, char **argv)
{
	t_env	*e;
	t_point	coord;
	int dim_tab;
	//	int x1;
	//	int y1;
	//	int x2;
	//	int y2;
	int bpp;
	int size_line;
	int endian;
	int fd;
	//	int spacing;
	//	int x;
	//	int y;
	char *line;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	coord.ymax = ft_nb_line(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	e = (t_env*)malloc(sizeof(t_env));
	e->array = ft_stock_map(fd, &line, &coord);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "mlx 42");
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &bpp, &size_line, &endian);
	dim_tab = coord.xmax * coord.ymax;
	if (coord.xmax > coord.ymax)
		e->spacing = 1000 / coord.xmax;
	else
		e->spacing = 1000 / coord.ymax;
	coord.y = 0;
	//	ft_trad(e, &coord);
	while (e->array[coord.y])
	{
		coord.x = 0;
		while (e->array[coord.y][coord.x])
		{
			//		ft_trad(e, &coord);
			//		ft_pixel_put_image(e, coord, &bpp, &size_line);
			if (coord.x >= 1)
			//	ft_pixel_put_image(e, (coord.x + 1 * ft_atoi(e->array[coord.y][coord.x])) * 50, (coord.y + 1/2 * ft_atoi(e->array[coord.y][coord.x])) * 50, &bpp, &size_line);
				//		ft_droite(e, (coord.x - 1) * 30, coord.y * 30, coord.x * 30, coord.y * 30, &bpp, &size_line);
			//	ft_trad(e, coord.x - 1, coord.y, coord.x, coord.x);
				ft_droite(e, ((coord.x - 1) + 1 * ft_atoi(e->array[coord.y][coord.x - 1])) * 30, (coord.y + 1/2 * ft_atoi(e->array[coord.y][coord.x - 1])) * 30, (coord.x + 1 * ft_atoi(e->array[coord.y][coord.x])) * 30, (coord.y + 1/2 * ft_atoi(e->array[coord.y][coord.x])) * 30, &bpp, &size_line);
			if (coord.y >= 1)
	//			ft_pixel_put_image(e, coord.x * 30, coord.y * 30, &bpp, &size_line);
				//voir pour coord.x - 1
			//	ft_trad(e, coord.x, coord.y - 1, coord.x, coord.y, &bpp, &size_line);
		//	ft_droite(e, coord.x * 30, (coord.y - 1) * 30, coord.x * 30, coord.y * 30, &bpp, &size_line);
				ft_droite(e, (coord.x + 1 * ft_atoi(e->array[coord.y][coord.x])) * 30, ((coord.y - 1) + 1/2 * ft_atoi(e->array[coord.y - 1][coord.x])) * 30, (coord.x + 1 * ft_atoi(e->array[coord.y][coord.x])) * 30, (coord.y + 1/2 * ft_atoi(e->array[coord.y][coord.x])) * 30, &bpp, &size_line);
			coord.x = coord.x + 1;
		}
		coord.y = coord.y + 1;
	}
	/*	while (e->array[coord.y])
		{
		coord.x = 0;
		while (e->array[coord.y][coord.x])
		{
		coord.z = ft_atoi(e->array[coord.y][coord.x]);
		x1 = coord.x + 1 * coord.z;// * bpp / 8) * 30;
	//	ft_putnbr(x1);
	y1 = (coord.y * 5) + 1/2 * coord.z;// * size_line) * 30;
	//		x2 = coord.x + 1 + 1 * coord.z;// * bpp / 8) * 30;
	//	ft_putnbr(x2);
	//		y2 = coord.y + 1/2 * coord.z;// * size_line) * 30;
	x = x1;
	while (x1 < x * 5)
	{
	ft_pixel_put_image(e, &x1, &y1, &bpp, &size_line);
	x1++;
	}
	y = y1;
	while (y1 < y + 5)
	{
	ft_pixel_put_image(e, &x1, &y1, &bpp, &size_line);
	y1++;
	}
	//ft_draw_cas(e, x1, y1, x2, y2);
		coord.x = coord.x + 1;
		}
		coord.y = coord.y + 1;
		}*/
	mlx_put_image_to_window(e->mlx, e->win, e->img, 100, 100);
	mlx_key_hook(e->win, key_function, &e);
	mlx_loop(e->mlx);
	return (0);
}
