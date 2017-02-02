/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:29:00 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/02 09:35:12 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put_image(t_env *e, int x, int y)
{
	e->data[((x * e->bpp / 8) + (y * e->size_line))] = e->b;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 1] = e->g;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 2] = e->r;
	e->data[((x * e->bpp / 8) + (y * e->size_line)) + 3] = 0;
}

int		ft_draw_lines(t_env *e)
{
	//algo de bresenham -
	int dx = ft_abs(e->xx1 - e->xx0), sx = e->xx0 < e->xx1 ? 1 : -1;
	int dy = ft_abs(e->yy1 - e->yy0), sy = e->yy0 < e->yy1 ? 1 : -1;
	int err = (dx > dy ? dx : - dy ) / 2, e2;

	while (1)
	{
		ft_pixel_put_image(e, e->xx0, e->yy0);
		if (e->xx0 == e->xx1 && e->yy0 == e->yy1) 
			return (0);
		e2 = err;
		if (e2 > -dx)
		{
			err = err - dy;
			e->xx0 = e->xx0 + sx;
		}
		if (e2 < dy)
		{
			err = err + dx;
			e->yy0 = e->yy0 + sy;
		}
	}
	return (0);
}

void	ft_isomeshit(t_env *e, int *x0, int *y0, int i)
{
	int x1;
	int y1;
	e->xx0 = ((*x0 + e->xmax) - *y0) * e->iso /*+ e->right*/ + 100;
	e->yy0 = (((*x0 + e->xmax) + *y0) * e->iso /*+ e->vertical*/) - e->array[*y0][*x0] * e->deep;
	if (i == 1)
	{
		x1 = (*x0 + 1) + e->xmax;
		y1 = *y0;
		e->xx1 = (x1 - y1) * e->iso /*+ e->right*/ + 100;
		e->yy1 = ((x1 + y1) * e->iso/* + e->vertical*/) - e->array[*y0][*x0 + 1] * e->deep;
	}
	if (i == 0)
	{
		x1 = *x0 + e->xmax;
		y1 = *y0 + 1;
		e->xx1 = (x1 - y1) * e->iso /*+ e->right*/ + 100;
		e->yy1 = ((x1 + y1) * e->iso/* + e->vertical*/) - e->array[*y0 + 1][*x0] * e->deep;
	}
}

int		ft_draw_map_into_img(t_env *e)
{
	int x;
	int y;

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
	return (0);
}


int		main(int argc, char **argv)
{
	t_env	*e;
//	int j;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	if (ft_xymax(e, argv[1]) == -1)
		return (0);
	ft_map(e, argv[1]);
	ft_init(e);
	/*int i = 0;
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
	e->win = mlx_new_window(e->mlx, 1000, 1000, "FdF");
	mlx_key_hook(e->win, key_fonction, e);
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_draw_map_into_img(e);
	//	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
	mlx_loop(e->mlx);
	return (0);
}
