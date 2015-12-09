/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:08:09 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 13:07:33 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bres	b_init_d(t_bres b)
{
	if (!(b.longest > b.shortest))
	{
		b.longest = abs(b.h);
		b.shortest = abs(b.w);
		if (b.h < 0)
			b.dy2 = -1;
		else if (b.h > 0)
			b.dy2 = 1;
		b.dx2 = 0;
	}
	b.numerator = b.longest >> 1;
	b.i = 0;
	return (b);
}

t_bres	b_init(t_bres b, t_point p, t_point p2)
{
	b.w = p2.x - p.x;
	b.h = p2.y - p.y;
	b.dx1 = 0;
	b.dy1 = 0;
	b.dx2 = 0;
	b.dy2 = 0;
	if (b.w < 0)
		b.dx1 = -1;
	else if (b.w > 0)
		b.dx1 = 1;
	if (b.h < 0)
		b.dy1 = -1;
	else if (b.h > 0)
		b.dy1 = 1;
	if (b.w < 0)
		b.dx2 = -1;
	else if (b.w > 0)
		b.dx2 = 1;
	b.longest = abs(b.w);
	b.shortest = abs(b.h);
	b = b_init_d(b);
	return (b);
}

void	draw_line(t_point p, t_point p2, t_env *e)
{
	t_bres	b;
	int		color;

	color = true_color(e->mlx, e->endiant, 0x8DEEEE);
	b = b_init(b, p, p2);
	if (p.z > p2.z)
		p2.z = p.z;
	while (b.i <= b.longest && p.x <= 1000 && p.x >= 0 && p.y <= 1000 &&
			p.y >= 0)
	{
		pxl_to_img(e, p.y, p.x, color);
		b.numerator += b.shortest;
		if (!(b.numerator < b.longest))
		{
			b.numerator -= b.longest;
			p.x += b.dx1;
			p.y += b.dy1;
		}
		else
		{
			p.x += b.dx2;
			p.y += b.dy2;
		}
		b.i++;
	}
}
