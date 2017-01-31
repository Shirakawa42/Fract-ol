/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/31 11:35:56 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <mlx.h>
# include "../src/libft/libft.h"
# include <stdlib.h>

typedef struct	s_mlx
{
	void	*win;
	void	*mlx;
	int		bpx;
	int		size;
	char	*data_addr;
	void	*img;
	int		idgaf;
	float	it;
	float	x;
	float	y;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	float	cr;
	float	ci;
	float	cijulia;
	float	zr;
	float	zi;
	float	tmp;
	int		image_x;
	int		image_y;
	int		xx;
	int		yy;
	int		i;
	int		which;
}				t_mlx;

void	mandelbrot_init(t_mlx *truc);
void	mandelbrot(t_mlx *smlx);
void	reload(t_mlx *truc);
int		mouse_input(int keycode, int x, int y, t_mlx *truc);
int		keyboard_input(int keycode, t_mlx *truc);
int		mouse_motion(int x, int y, t_mlx *truc);
void	julia_init(t_mlx *truc);
void	julia(t_mlx *smlx);
void	buddhabrot_init(t_mlx *truc);
void	buddhabrot(t_mlx *smlx);

#endif
