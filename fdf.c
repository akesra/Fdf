/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akesraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:29:00 by akesraou          #+#    #+#             */
/*   Updated: 2017/02/03 12:04:52 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_env *e)
{
	e->r = 100;
	e->g = 100;
	e->b = 100;
	e->h = 0;
	e->color = 0;
	e->deep = 1;
	e->right = 80;
	e->menu = 0;
	if (e->xmax > 20)
		e->vertical = e->xmax * 0.5;
	else
		e->vertical = e->xmax * - 10;
	if (e->xmax > 200)
	{
		e->iso = 1;
		e->deep = 0.9;
	}
	else
		e->iso = 600 / sqrt(e->xmax * e->xmax + e->ymax * e->ymax);
}

int	ft_find_xmax(char *line)
{
	int i;
	int nx;

	i = 0;
	nx = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			nx++;
			while (line[i] != '\0' && line[i] != ' ')
				i++;
			i--;
		}
		i++;
	}
	return (nx);
}

int	ft_xymax(t_env *e, char *argv)
{
	int fd;
	int xline;
	char *line = NULL;
	int y;
	int h;

	y = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("No file found.\n");
		return (-1);
	}
	while ((get_next_line(fd, &line)) > 0)
	{
		xline = ft_find_xmax(line);
		if (y == 0)
			h = xline;
		if (xline != h)
		{
			ft_putstr("Wrong size of line. Exit.\n");
			return (-1);
		}
		ft_strdel(&line);
		y++;
	}
	if (xline == 0 && y == 0)
	{
		ft_putstr("No data found.\n");
		return (-1);
	}
	close(fd);
	e->xmax = xline;
	e->ymax = y;
	ft_putstr("xmax: ");
	ft_putnbr(xline);
	ft_putchar('\n');
	ft_putstr("ymax: ");
	ft_putnbr(y);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	if (ft_xymax(e, argv[1]) == -1)
		return (0);
	ft_read_map(e, argv[1]);
	ft_init(e);
	e->win = mlx_new_window(e->mlx, 1400, 1500, "FdF");
	mlx_key_hook(e->win, key_fonction, e);
	e->img = mlx_new_image(e->mlx, 1400, 1500);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	ft_draw_map_into_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->right, e->vertical);
	ft_menu(e);
	mlx_loop(e->mlx);
	return (0);
}
