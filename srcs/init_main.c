/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 12:15:01 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 13:21:05 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			puterror_fra(void)
{
	ft_putendl("Usage : ./fractol options:");
	ft_putendl("1 => Julia");
	ft_putendl("2 => Mandelbroot");
	ft_putendl("3 => Tapis de Sierpinski");
}

t_env			init_env(t_env e)
{
	e.zoom = 1.1;
	if (ft_strcmp(e.av, "3") == 0)
		e.zoom = 0.000000352282699;
	e.movex = 1;
	e.c = 1;
	e.movey = 1;
	e.width = WIDTH;
	e.height = HEIGHT;
	e.pause = 0;
	e.x = 0;
	e.tri = 0;
	e.m = 300;
	e.y = 0;
	e.cre = -2;
	e.cim = -1.2;
	return (e);
}

void			draw_tab(t_env *e)
{
	t_julia	j;

	if (ft_strcmp(e->av, "1") == 0)
	{
		j = init_julia(e, j);
		julia_put(e, j);
	}
	if (ft_strcmp(e->av, "2") == 0)
		mandelbroot_put(e);
	if (ft_strcmp(e->av, "3") == 0)
		tri_sierpinski(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int				ft_notopts(char *av)
{
	if (ft_strcmp(av, "1") == 0)
		return (0);
	if (ft_strcmp(av, "2") == 0)
		return (0);
	if (ft_strcmp(av, "3") == 0)
		return (0);
	return (1);
}
