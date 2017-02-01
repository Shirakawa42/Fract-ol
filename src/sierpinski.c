/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:42:04 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 16:31:40 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	sierpinski_while(t_mlx *smlx)
{
	if (smlx->zr < 0)
		smlx->zr = -smlx->zr;
	if (smlx->zi < 0)
		smlx->zi = -smlx->zi;
	smlx->tmp = smlx->zr;
	smlx->zr = smlx->zr * smlx->zr -
		smlx->zi * smlx->zi + smlx->cr;
	smlx->zi = 2 * smlx->zi * smlx->tmp + smlx->ci;
	smlx->i += 1;
}

void		sierpinski(t_mlx *smlx)
{
	smlx->xx = 0;
	while (smlx->xx < smlx->image_x)
	{
		smlx->yy = 0;
		while (smlx->yy < smlx->image_y)
		{
			smlx->cr = 0.285;
			smlx->ci = 0.01;
			smlx->zr = smlx->xx / smlx->zoom + smlx->x1;
			smlx->zi = smlx->yy / smlx->zoom + smlx->y1;
			smlx->i = 0;
			while (smlx->zr * smlx->zr + smlx->zi * smlx->zi
				< 4 && (int)smlx->i < (int)smlx->it)
				sierpinski_while(smlx);
			if ((int)smlx->i != (int)smlx->it)
			{
				xyz(smlx->xx, smlx->yy, smlx);
				smlx->color = palet(smlx);
				pixel((int)smlx->tmpx, (int)smlx->tmpy, smlx);
			}
			smlx->yy++;
		}
		smlx->xx++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

void		sierpinski_init(t_mlx *truc)
{
	truc->x1 = -2.6;
	truc->x2 = 0.6;
	truc->y1 = -1.6;
	truc->y2 = 1.2;
	truc->zoom = 150;
	truc->it = 80;
	truc->image_x = 800;
	truc->image_y = 500;
	sierpinski(truc);
}
