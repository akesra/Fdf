/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 09:57:24 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 12:23:59 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		e->color = 0;
		e->h = 0;
		e->r = 0;
		e->g = 0;
		e->b = 0;
		ft_clear_and_put(e);
	}
}

void	ft_depth_up_change(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		if (e->xmax >= 30)
		{
			if (e->deep < e->xmax / e->xmax)
			{
				e->deep = e->deep + 0.3;
				ft_clear_and_put(e);
			}
		}
		else if (e->xmax < 30)
		{
			if (e->deep < e->xmax / 2 + 1)
			{
				e->deep = e->deep + 1;
				ft_clear_and_put(e);
			}
		}
	}
}

void	ft_depth_change(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		if (e->xmax >= 30)
		{
			if (e->deep > - e->xmax / e->xmax)
			{
				e->deep = e->deep - 0.3;
				ft_clear_and_put(e);
			}
		}
		else if (e->xmax < 30)
		{
			if (e->deep > - e->xmax / 2 - 1)
			{
				e->deep = e->deep -1;
				ft_clear_and_put(e);
			}
		}
	}
	ft_depth_up_change(keycode, e);
}

void	ft_vertical_change(int keycode, t_env *e)
{
	if (keycode == 125)
	{
		e->vertical = e->vertical + 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
		if (e->menu == 0)
			ft_menu(e);
		else if (e->menu == 1)
			mlx_string_put(e->mlx, e->win, 1000, 1260, 255255255, "*Afficher le menu:   m");
	}
	if (keycode == 126)
	{
		e->vertical = e->vertical - 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
		if (e->menu == 0)
			ft_menu(e);
		else if (e->menu == 1)
			mlx_string_put(e->mlx, e->win, 1000, 1260, 255255255, "*Afficher le menu:   m");
	}
}
void    ft_right_change(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->right = e->right + 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
		if (e->menu == 0)
			ft_menu(e);
		else if (e->menu == 1)
			mlx_string_put(e->mlx, e->win, 1000, 1260, 255255255, "*Afficher le menu:   m");
	}
	if (keycode == 123)
	{
		e->right = e->right - 20;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
		if (e->menu == 0)
			ft_menu(e);
		else if (e->menu == 1)
			mlx_string_put(e->mlx, e->win, 1000, 1260, 255255255, "*Afficher le menu:   m");
	}
}
