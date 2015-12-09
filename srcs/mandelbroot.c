/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:03:30 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/12 13:59:07 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mand	init_mand(t_mand m)
{
	m.x = 0;
	m.i = 0;
	m.y = 0;
	return (m);
}

t_mand	rest_ima(t_env *e, t_mand m)
{
	m.pr = (((m.x + e->x) / e->zoom / WIDTH * 4 - 2));
	m.pi = (((m.y + e->y) / e->zoom / HEIGHT * 4 - 2));
	m.newre = 0;
	m.newim = 0;
	m.oldre = 0;
	m.oldim = 0;
	return (m);
}

void	mandelbroot_put(t_env *e)
{
	t_mand	m;

	m = init_mand(m);
	while (m.x < WIDTH)
	{
		while (m.y < HEIGHT)
		{
			m = rest_ima(e, m);
			m.i = 0;
			while (m.i < e->m)
			{
				m.oldre = m.newre;
				m.oldim = m.newim;
				m.newre = m.oldre * m.oldre - m.oldim * m.oldim + m.pr;
				m.newim = 2 * m.oldre * m.oldim + m.pi;
				if ((m.newre * m.newre + m.newim * m.newim) > 4)
					break ;
				m.i++;
			}
			pxl_to_img(e, m.y, m.x, ft_color(m.i, e->m, e));
			m.y++;
		}
		m.y = 0;
		m.x++;
	}
}
