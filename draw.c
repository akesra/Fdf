/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 09:55:20 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 12:01:57 by akesraou         ###   ########.fr       */
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

int		ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

int		ft_draw_lines(t_env *e)
{
	e->dx = ft_abs(e->xx1 - e->xx0);
	e->sx = e->xx0 < e->xx1 ? 1 : -1;
	e->dy = ft_abs(e->yy1 - e->yy0);
	e->sy = e->yy0 < e->yy1 ? 1 : -1;
	e->err = (e->dx > e->dy ? e->dx : -e->dy) / 2;
	while (1)
	{
		ft_pixel_put_image(e, e->xx0, e->yy0);
		if (e->xx0 == e->xx1 && e->yy0 == e->yy1)
			return (0);
		e->e2 = e->err;
		if (e->e2 > -e->dx)
		{
			e->err = e->err - e->dy;
			e->xx0 = e->xx0 + e->sx;
		}
		if (e->e2 < e->dy)
		{
			e->err = e->err + e->dx;
			e->yy0 = e->yy0 + e->sy;
		}
	}
	return (0);
}

void	ft_isometric(t_env *e, int x0, int y0, int i)
{
	int x1;
	int y1;

	if (e->color == 1)
		ft_color(e, x0, y0, i);
	e->xx0 = ((x0 + e->xmax) - y0) * e->iso + 200;
	e->yy0 = ((x0 + e->xmax) + y0) * e->iso - e->array[y0][x0] * e->deep;
	if (i == 1)
	{
		x1 = (x0 + 1) + e->xmax;
		y1 = y0;
		e->xx1 = (x1 - y1) * e->iso + 200;
		e->yy1 = (x1 + y1) * e->iso - e->array[y0][x0 + 1] * e->deep;
	}
	if (i == 0)
	{
		x1 = x0 + e->xmax;
		y1 = y0 + 1;
		e->xx1 = (x1 - y1) * e->iso + 200;
		e->yy1 = (x1 + y1) * e->iso - e->array[y0 + 1][x0] * e->deep;
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
				ft_isometric(e, x, y, 1);
				ft_draw_lines(e);
			}
			if (y + 1 < e->ymax)
			{
				ft_isometric(e, x, y, 0);
				ft_draw_lines(e);
			}
			x++;
		}
		y++;
	}
	return (0);
}
