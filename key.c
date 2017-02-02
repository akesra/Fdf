/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:39:13 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/02 09:45:16 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_clear_and_put(t_env *e)
{
			mlx_clear_window(e->mlx, e->win);
			mlx_destroy_image(e->mlx, e->img);
			e->img = mlx_new_image(e->mlx, 1000, 1000);
			e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
			ft_draw_map_into_img(e);
			mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
}

void	ft_color_change(int keycode, t_env *e)
{
	if (keycode == 83 && e->r + 10 < 255)
	{
		e->r = e->r + 10;
		ft_clear_and_put(e);
	}
	if (keycode == 84 && e->g + 10 < 255)
	{
		e->g = e->g + 10;
		ft_clear_and_put(e);
	}
	if (keycode == 85 && e->b + 10 < 255)
	{
		e->b = e->b + 10;
		ft_clear_and_put(e);
	}
	if (keycode == 82)
	{
		e->r = 0;
		e->g = 0;
		e->b = 0;
		ft_clear_and_put(e);
	}
}

void	ft_depth_change(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		if (e->xmax > 40)
		{
			if (e->deep > - e->xmax / e->xmax - 2)
			{
				e->deep = e->deep - 1;
				ft_clear_and_put(e);
				printf("deep++ : %d\n", e->deep);
			}
		}
		else if (e->xmax <= 40)
		{
			if (e->deep > - e->xmax / 2)
			{
				e->deep = e->deep -1;
				ft_clear_and_put(e);
			}
		}
	}
	if (keycode == 78)
	{
		if (e->xmax > 40)
		{
			if (e->deep < e->xmax / e->xmax + 2)
			{
				e->deep = e->deep + 1;
				ft_clear_and_put(e);
			}
		}
		else if (e->xmax <= 40)
		{
			if (e->deep < e->xmax / 2)
			{
				e->deep = e->deep + 1;
				ft_clear_and_put(e);
			}
		}
			//		=> dans une fonction static
		printf("deep-- : %d\n", e->deep);
	}
}

void	ft_vertical_change(int keycode, t_env *e)
{
	if (keycode == 121)
	{
		e->vertical = e->vertical + 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
		printf("vertical: %d\n", e->vertical);
	}
	if (keycode == 116)
	{
		e->vertical = e->vertical - 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
		printf("vertical vers le haut: %d\n", e->vertical);
	}
}

void	ft_right_change(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->right = e->right + 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
		printf("right++: %d\n", e->right);
	}
	if (keycode == 123)
	{
		e->right = e->right - 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right + (e->ymax - e->xmax), e->vertical);
		printf("right--: %d\n", e->right);
	}
}

int		key_fonction(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
//	if (keycode == 8)
	//	mlx_clear_window(e->mlx, e->win);
	ft_color_change(keycode, e);
	ft_depth_change(keycode, e);
	ft_vertical_change(keycode, e);
/*	if (keycode == 125)
	{
		if (e->ymax < 100)
		{
			if (e->iso > e->ymax * 2)
			{
				e->iso = e->iso - 1;
				ft_clear_and_put(e);
			}
		}
		else
		{
			if (e->iso > 1)
			{
				e->iso = e->iso - 1;
				ft_clear_and_put(e);
			}
		}
		printf("iso: %d\n", e->iso);
	}
	if (keycode == 126)
	{
		if (e->xmax < 100)
		{
			if (e->iso < e->xmax * 2.5)
			{
				e->iso = e->iso + 1;
				ft_clear_and_put(e);
			}
		}
		else
		{
			if (e->iso < 3)
			{
				e->iso = e->iso + 1;
				ft_clear_and_put(e);
			}
		}
		printf("iso: %d\n", e->iso);
	}*/
	ft_right_change(keycode, e);
	return (0);
}
/*
int		loop_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_draw_map_into_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
	mlx_clear_window(e->mlx, e->win);
	//mlx_destroy_image(e->mlx, e->img);
	return (0);
}*/

int		ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * - 1);
}

void	ft_init(t_env *e)
{
	e->r = 120;
	e->g = 120;
	e->b = 120;
	e->deep = 1;
	e->right = 80;
	if (e->xmax >= 20)
		e->vertical = e->xmax * 0.5;
	else
		e->vertical = e->xmax * - 10;
	e->iso = 450 / sqrt(e->xmax * e->xmax + e->ymax * e->ymax);
}
