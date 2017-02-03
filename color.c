/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:25:24 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 14:12:49 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color2(t_env *e, int x0, int y0, int i)
{
	if (i == 1)
	{
		if (e->array[y0][x0] > 20 || e->array[y0][x0 + 1] > 20)
		{
			e->r = 255 - e->h;
			e->g = 255;
			e->b = 255 - e->h / 2;
		}
		else if (e->array[y0][x0] > 5 || e->array[y0][x0 + 1] > 5)
		{
			e->r = 51 + e->h;
			e->g = 102;
			e->b = 51;
		}
		else
		{
			e->r = 0;
			e->g = 160;
			e->b = 150 - e->h;
		}
	}
}

void	ft_color(t_env *e, int x0, int y0, int i)
{
	if (i == 0)
	{
		if (e->array[y0][x0] > 20 || e->array[y0 + 1][x0] > 20)
		{
			e->r = 255 - e->h;
			e->g = 255;
			e->b = 255 - e->h / 2;
		}
		else if (e->array[y0][x0] > 5 || e->array[y0 + 1][x0] > 5)
		{
			e->r = 51 + e->h;
			e->g = 102;
			e->b = 51;
		}
		else
		{
			e->r = 0;
			e->g = 160;
			e->b = 150 - e->h;
		}
	}
	ft_color2(e, x0, y0, i);
}
