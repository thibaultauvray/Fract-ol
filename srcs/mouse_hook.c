/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:20:25 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 13:07:06 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_hook(int x, int y, t_env *e)
{
	if (e->pause == 0)
	{
		if (e->cre <= 2 && e->cre >= -2)
		{
			e->cre = x * (4.00 / (double)WIDTH) - 2;
		}
		if (e->cim <= 1 && e->cim >= -1.2)
		{
			e->cim = y * (2.2 / (double)HEIGHT) - 1.2;
		}
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		if (e->pause == 0)
			e->pause = 1;
		else
			e->pause = 0;
	}
	if (button == 4)
	{
		e->tri += 10;
		e->zoom *= ZOOM;
		e->x = (e->x + ((WIDTH - (WIDTH / ZOOM)) / 2) +
				(x - WIDTH / 2) * (1 - (1 / ZOOM))) * ZOOM;
		e->y = (e->y + ((WIDTH - (WIDTH / ZOOM)) / 2) +
				(y - WIDTH / 2) * (1 - (1 / ZOOM))) * ZOOM;
	}
	if (button == 5)
	{
		e->zoom /= ZOOM;
		e->x = e->x / ZOOM - ((WIDTH - (WIDTH / ZOOM)) / 2) / ZOOM
								- (x - WIDTH / 2) * ZOOM + (x - WIDTH / 2);
		e->y = e->y / ZOOM - ((HEIGHT - (HEIGHT / ZOOM)) / 2) / ZOOM
								- (y - HEIGHT / 2) * ZOOM + (y - HEIGHT / 2);
	}
	return (0);
}
