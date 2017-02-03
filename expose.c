/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:03:40 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 11:58:27 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 900, 1040, 255255255, "/~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~\\");
	mlx_string_put(e->mlx, e->win, 900, 1060, 255255255, "*    Deplacer map:         Fleches     *");
	mlx_string_put(e->mlx, e->win, 900, 1080, 255255255, "*    Relief:               + ou -     *");
	mlx_string_put(e->mlx, e->win, 900, 1100, 255255255, "*    Plus de rouge:          1         *");
	mlx_string_put(e->mlx, e->win, 900, 1120, 255255255, "*    Plus de vert:           2         *");
	mlx_string_put(e->mlx, e->win, 900, 1140, 255255255, "*    Plus de bleu:           3         *");
	mlx_string_put(e->mlx, e->win, 900, 1160, 255255255, "*    Color reset:            0         *");
	mlx_string_put(e->mlx, e->win, 900, 1180, 255255255, "*    Couleur selon z:        c         *");
	mlx_string_put(e->mlx, e->win, 900, 1200, 255255255, "*    Afficher le menu:       m         *");
	mlx_string_put(e->mlx, e->win, 900, 1220, 255255255, "*    Quitter le programme:   esc       *");
	mlx_string_put(e->mlx, e->win, 900, 1240, 255255255, "*    Quitter le menu:        q         *");
	mlx_string_put(e->mlx, e->win, 900, 1260, 255255255, "\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/");
}

void	ft_clear_and_put(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, 1400, 1500);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_draw_map_into_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
	if (e->menu == 0)
		ft_menu(e);
	else if (e->menu == 1)
		mlx_string_put(e->mlx, e->win, 1000, 1260, 255255255, "*Afficher le menu:   m");
}
