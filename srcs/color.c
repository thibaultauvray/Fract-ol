/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:06:19 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 12:38:15 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_col3(int i, int max)
{
	double	n;
	int		r;
	int		g;
	int		b;

	n = (double)i / max;
	r = (sin(n * M_PI * 2 - M_PI_2) + 1) / 2 * 255;
	g = (sin(n * M_PI * 4 - M_PI_2) + 1) / 2 * 255;
	b = (sin(n * M_PI * 8 - M_PI_2) + 1) / 2 * 255;
	return (0x10000 * r + 0x100 * g + b);
}

int		ft_col2(int i, int max)
{
	double	n;
	int		r;
	int		g;
	int		b;

	n = (double)i / max;
	r = (sin(n * M_PI * 2 - M_PI_2) + 1) / 2 * 255;
	g = (sin(n * M_PI * 4 - M_PI_2) + 1) / 2 * 255;
	b = (sin(n * M_PI * 8 - M_PI_2) + 1) / 2 * 255;
	return (0x10000 * b + 0x100 * r + g);
}

int		ft_col(int i, int max)
{
	double	n;
	int		r;
	int		g;
	int		b;

	n = (double)i / max;
	r = (sin(n * M_PI * 2 - M_PI_2) + 1) / 2 * 255;
	g = (sin(n * M_PI * 4 - M_PI_2) + 1) / 2 * 255;
	b = (sin(n * M_PI * 8 - M_PI_2) + 1) / 2 * 255;
	return (0x10000 * g + 0x100 * b + r);
}

int		ft_color(int i, int max, t_env *e)
{
	int c;

	if (e->c == 1)
		c = ft_col(i, max);
	else if (e->c == 2)
		c = ft_col2(i, max);
	else
		c = ft_col3(i, max);
	return (c);
}
