/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_sierpinski.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:43:58 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 12:29:45 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_sierpi(t_env *e, int x, int y, int itmax)
{
	int		i;

	i = 0;
	x = (x + e->x) / e->zoom;
	x = (x < 0) ? -x : x;
	y = (y + e->y) / e->zoom;
	y = (y < 0) ? -y : y;
	while ((x > 0 || y > 0) && i < itmax)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (i);
		x /= 3;
		y /= 3;
		i++;
	}
	return (itmax);
}

void			tri_sierpinski(t_env *e)
{
	int	x;
	int y;
	int i;
	int itmax;

	itmax = 500;
	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			i = ft_sierpi(e, x, y, itmax);
			pxl_to_img(e, y, x, ft_color_tri(i, itmax, e));
			y++;
		}
		x++;
	}
}
