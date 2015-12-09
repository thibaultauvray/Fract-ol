/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 12:30:10 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 13:09:38 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_col_tri2(int i, int max)
{
	t_rgb	c;

	if (i < 100)
	{
		c.r = i * 255 / max;
		c.g = i * 10 / max;
		c.b = i * 5 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else if (i < 255)
	{
		c.r = i * 100 / max;
		c.g = i * 255 / max;
		c.b = i * 1 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else
	{
		c.r = i * 1 / max;
		c.g = i * 1 / max;
		c.b = i * 255 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	return (c.c);
}

int		ft_col_tri3(int i, int max)
{
	t_rgb	c;

	if (i < 100)
	{
		c.r = i * 50 / max;
		c.g = i * 124 / max;
		c.b = i * 60 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else if (i < 255)
	{
		c.r = i * 200 / max;
		c.g = i * 56 / max;
		c.b = i * 1 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else
	{
		c.r = i * 1 / max;
		c.g = i * 255 / max;
		c.b = i * 1 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	return (c.c);
}

int		ft_col_tri(int i, int max)
{
	t_rgb	c;

	if (i < 100)
	{
		c.r = i * 15 / max;
		c.g = i * 255 / max;
		c.b = i * 15 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else if (i < 255)
	{
		c.r = i * 1 / max;
		c.g = i * 10 / max;
		c.b = i * 255 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	else
	{
		c.r = i * 10 / max;
		c.g = i * 98 / max;
		c.b = i * 125 / max;
		c.c = ((c.b & 0xff) << 16) + ((c.g & 0xff) << 8) + c.r;
	}
	return (c.c);
}

int		ft_color_tri(int i, int max, t_env *e)
{
	int	c;

	if (e->c == 1)
		c = ft_col_tri(i, max);
	if (e->c == 2)
		c = ft_col_tri2(i, max);
	if (e->c == 3)
		c = ft_col_tri3(i, max);
	return (c);
}
