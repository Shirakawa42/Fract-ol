/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:33:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/25 15:48:38 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <mlx.h>
# include "../srcs/libft/libft.h"

typedef struct	s_mlx
{
	void	*win;
	void	*mlx;
	int		bpx;
	int		size;
	char	*data_addr;
	void	*img;
	int		idgaf;
}				t_mlx;

typedef struct	s_frac
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_frac;

#endif
