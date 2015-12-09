/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:43:13 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/25 13:21:02 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FFRACTOL_H
# define FFRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 700
# define HEIGHT 700
# define MLX_BIG_ENDIAN 1
# define ZOOM 1.1

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*edit;
	int				bpx;
	int				szl;
	int				endiant;
	char			*av;
	double			zoom;
	double			movex;
	double			movey;
	int				width;
	int				m;
	int				height;
	int				tmp_x;
	int				c;
	double			x;
	float			tri;
	int				pause;
	double			cim;
	double			cre;
	double			y;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_bres
{
	int				w;
	int				h;
	int				dx1;
	int				dy1;
	int				dx2;
	int				dy2;
	int				longest;
	int				shortest;
	int				numerator;
	int				i;
}					t_bres;

typedef struct		s_liste
{
	double			x;
	double			y;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_rgb
{
	int				r;
	int				b;
	int				g;
	int				c;
}					t_rgb;

typedef struct		s_julia
{
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	int				x;
	int				y;
	int				i;
}					t_julia;

typedef struct		s_mand
{
	double			pr;
	double			pi;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	int				x;
	int				y;
	int				i;
}					t_mand;

typedef unsigned int	t_uint32;

int					key_hook(int keycode, t_env *e);
t_uint32			swap_endian(t_uint32 in);
t_uint32			true_color(void *mlx, int endian, int rgb);
void				pxl_to_img(t_env *e, int x, int y, t_uint32 color);
void				draw_line(t_point p, t_point p2, t_env *e);
void				julia_put(t_env *e, t_julia j);
void				mandelbroot_put(t_env *e);
void				tri_sierpinski(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);

int					move_hook(int x, int y, t_env *e);
int					ft_color(int i, int max, t_env *e);
t_env				init_env(t_env e);
void				draw_tab(t_env *e);
t_julia				init_julia(t_env *e, t_julia j);
void				puterror_fra(void);
int					ft_color_tri(int i, int max, t_env *e);
int					ft_col_tri(int i, int max);
int					ft_notopts(char *av);
#endif
