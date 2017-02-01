/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:21:40 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/01 08:04:15 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>
#include </System/Library/Frameworks/Tk.framework/Versions/Current/Headers/X11/X.h>

typedef struct     s_env
{
	void*mlx;
	void*win;
	void*img;
	char*data;
	int xmax;
	int	ymax;
	int**array;
	int bpp;
	int size_line;
	int endian;
	int xx0;
	int xx1;
	int yy0;
	int yy1;
	int spacing;
	int r;
	int g;
	int	b;
	int deep;
	int iso;
	int right;
	int vertical;
}					t_env;

int		ft_find_max(char *line);
int		ft_xymax(t_env *e, char *argv);
void	ft_stock_map(t_env *e, char **tmp, int y, int x);
void	ft_map(t_env *e, char *argv);
void	ft_init(t_env *e);
int		ft_abs(int nb);
int		loop_hook(t_env *e);
int		key_fonction(int keycode, t_env *e);
int		ft_draw_map_into_img(t_env *e);

#endif
