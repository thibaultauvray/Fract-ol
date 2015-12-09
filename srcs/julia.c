/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:22:09 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/12 13:59:08 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_julia	init_julia(t_env *e, t_julia j)
{
	j.i = 0;
	j.y = 0;
	j.x = 0;
	j.cre = e->cre;
	j.cim = e->cim;
	return (j);
}

void	julia_put(t_env *e, t_julia j)
{
	j = init_julia(e, j);
	while (j.x < WIDTH)
	{
		while (j.y < HEIGHT)
		{
			j.newre = (((j.x + e->x) / e->zoom / WIDTH * 4 - 2));
			j.newim = (((j.y + e->y) / e->zoom / HEIGHT * 4 - 2));
			j.i = 0;
			while (j.i < e->m)
			{
				j.oldre = j.newre;
				j.oldim = j.newim;
				j.newre = j.oldre * j.oldre - j.oldim * j.oldim + j.cre;
				j.newim = 2 * j.oldre * j.oldim + j.cim;
				if ((j.newre * j.newre + j.newim * j.newim) > 4)
					break ;
				j.i++;
			}
			pxl_to_img(e, j.y, j.x, ft_color(j.i, e->m, e));
			j.y++;
		}
		j.y = 0;
		j.x++;
	}
}
