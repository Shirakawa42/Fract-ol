/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 14:30:57 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <mlx.h>
# include "../src/libft/libft.h"
# include <stdlib.h>

typedef struct	s_mlx
{
	void		*win;
	void		*mlx;
	int			bpx;
	int			size;
	char		*data_addr;
	void		*img;
	int			idgaf;
	double		it;
	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		cr;
	double		ci;
	double		cijulia;
	double		zr;
	double		zi;
	double		tmp;
	int			image_x;
	int			image_y;
	int			xx;
	int			yy;
	int			i;
	int			which;
	int			s;
	double		rotx;
	double		roty;
	double		rotz;
	double		tmpx;
	double		tmpy;
	double		tmpz;
	double		xrotate;
	double		yrotate;
	double		zrotate;
	int			xpadding;
	int			ypadding;
	int			motion;
	int			color;
}				t_mlx;

void			mandelbrot_init(t_mlx *truc);
void			mandelbrot(t_mlx *smlx);
void			reload(t_mlx *truc);
int				mouse_input(int keycode, int x, int y, t_mlx *truc);
int				keyboard_input(int keycode, t_mlx *truc);
int				mouse_motion(int x, int y, t_mlx *truc);
void			julia_init(t_mlx *truc);
void			julia(t_mlx *smlx);
void			burning_ship(t_mlx *smlx);
void			burning_ship_init(t_mlx *truc);
int				palet(t_mlx *truc);
void			matrice_ator(t_mlx *truc, float x, float y);
void			xyz(int x, int y, t_mlx *truc);
void			pixel(int x, int y, t_mlx *smlx);

#endif
