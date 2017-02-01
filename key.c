/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:39:13 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/01 12:46:31 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_fonction(int keycode, t_env *e)
{
//	if (keycode == 76)
	if (keycode == 53)
		exit (0);
	if (keycode == 83 && e->r + 10 < 255)
		e->r = e->r + 10;
	if (keycode == 84 && e->g + 10 < 255)
		e->g = e->g + 10;
	if (keycode == 85 && e->b + 10 < 255)
		e->b = e->b + 10;
	if (keycode == 82)
	{
		e->r = 0;
		e->g = 0;
		e->b = 0;
	}
	if (keycode == 69)
	{
		printf("keycode: %d\n", keycode);
		if (e->deep < 45)
			e->deep = e->deep - 1;
		printf("deep++ : %d\n", e->deep);
	}
	if (keycode == 121)
	{
		e->vertical = e->vertical + 30;
		printf("vertical: %d\n", e->vertical);
	}
	if (keycode == 116)
	{
		e->vertical = e->vertical - 30;
		printf("vertical vers le haut: %d\n", e->vertical);
	}
	if (keycode == 78)
	{
		printf("keycode: %d\n", keycode);
			e->deep = e->deep + 1;
		printf("deep-- : %d\n", e->deep);
	}
	if (keycode == 125)
	{
		if (e->ymax < 100)
		{
			if (e->iso > e->ymax * 2)
				e->iso = e->iso - 1;
		}
		else
		{
			if (e->iso > 1)
				e->iso = e->iso - 1;
		}
		printf("iso: %d\n", e->iso);
	}
	if (keycode == 126)
	{
		if (e->xmax < 100)
		{
			if (e->iso < e->xmax * 2.5)
				e->iso = e->iso + 1;
		}
		else
		{
			if (e->iso < 3)
				e->iso = e->iso + 1;
		}
		printf("iso: %d\n", e->iso);
	}
	if (keycode == 124)
		//	if (e->right < e->xmax * e->xmax)
		e->right = e->right + 20;
	printf("right++: %d\n", e->right);
	if (keycode == 123)
		//	if (e->right > e->xmax * e->xmax)
		e->right = e->right - 20;
	printf("right--: %d\n", e->right);
	//	if (keycode == 53)
	//		mlx_clear_window(e->mlx, e->win);
	return (0);
}

int		loop_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_draw_map_into_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

int		ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * - 1);		//ou -nb? lequel est le plus propre?
}

void	ft_init(t_env *e)
{
	e->r = 120;
	e->g = 120;
	e->b = 120;
	e->deep = 0;
	e->right = 0;
	if (e->xmax >= 20)
		e->vertical = e->xmax * 0.5;
	else
		e->vertical = e->xmax * - 10;
	e->iso = 450 / sqrt(e->xmax * e->xmax + e->ymax * e->ymax);
}
