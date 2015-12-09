/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:45:56 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 13:21:07 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose_hook(t_env *e)
{
	draw_tab(e);
	return (0);
}

int				loop_hook(t_env *e)
{
	draw_tab(e);
	return (0);
}

void			ft_gest_lib(t_env e)
{
	e = init_env(e);
	if (!(e.mlx = mlx_init()))
		exit(1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fractol");
	mlx_key_hook(e.win, &key_hook, &e);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.edit = mlx_get_data_addr(e.img, &(e.bpx), &(e.szl), &(e.endiant));
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 6, (1L << 6), move_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
}

void			ft_fractol(char *av)
{
	t_env	e;

	e.av = av;
	ft_gest_lib(e);
}

int				main(int ac, char **av)
{
	if (ac != 2 || ft_notopts(av[1]) == 1)
	{
		puterror_fra();
	}
	else
		ft_fractol(av[1]);
	return (0);
}
