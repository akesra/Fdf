/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:39:13 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 12:10:56 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keycode(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 12)
	{
		e->menu = 1;
		ft_clear_and_put(e);
	}
	if (keycode == 46)
	{
		e->menu = 0;
		ft_clear_and_put(e);
	}
	if (keycode == 67)
	{
		e->menu = 2;
		ft_clear_and_put(e);
	}
	if (keycode == 12)
		ft_clear_and_put(e);
}

int		key_fonction(int keycode, t_env *e)
{
	ft_keycode(keycode, e);
	ft_color_change(keycode, e);
	ft_depth_change(keycode, e);
	ft_vertical_change(keycode, e);
	ft_right_change(keycode, e);
/*	if (keycode == 116)
	{
		if (e->xmax > 150 && e->iso < 1)
			e->iso = e->iso + 1;
		printf("e->iso: %d", e->iso);
	}*/
	if (keycode == 8)
	{
		e->color = 1;
		e->h = e->h + 10;
		ft_clear_and_put(e);
	}
	return (0);
}
