/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/26 13:14:49 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <mlx.h>
# include "../srcs/libft/libft.h"
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
	float	zr;
	float	zi;
	float	tmp;
	int		image_x;
	int		image_y;
	int		xx;
	int		yy;
	int		i;
}				t_mlx;

#endif
