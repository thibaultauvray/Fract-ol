/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:34:34 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 14:17:00 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 114)
		*e = init_env(*e);
	if (keycode == 65307)
		exit (0);
	if (keycode == 65364)
		e->y -= 10;
	if (keycode == 65362)
		e->y += 10;
	if (keycode == 65363)
		e->x -= 10;
	if (keycode == 65361)
		e->x += 10;
	if (keycode == 99)
	{
		e->c++;
		if (e->c == 4)
			e->c = 1;
	}
	return (0);
}
