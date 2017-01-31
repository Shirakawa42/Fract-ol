/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:31:17 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/30 15:43:13 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mandelbrot_while(t_mlx *smlx)
{
	smlx->tmp = smlx->zr;
	smlx->zr = smlx->zr * smlx->zr -
		smlx->zi * smlx->zi + smlx->cr;
	smlx->zi = 2 * smlx->zi * smlx->tmp + smlx->ci;
	smlx->i++;
}

void		mandelbrot(t_mlx *smlx)
{
	smlx->xx = 0;
	while (smlx->xx < smlx->image_x)
	{
		smlx->yy = 0;
		while (smlx->yy < smlx->image_y)
		{
			smlx->cr = smlx->xx / smlx->zoom + smlx->x1;
			smlx->ci = smlx->yy / smlx->zoom + smlx->y1;
			smlx->zr = 0;
			smlx->zi = 0;
			smlx->i = 0;
			while (smlx->zr * smlx->zr + smlx->zi * smlx->zi
				< 4 && smlx->i < (int)smlx->it)
				mandelbrot_while(smlx);
			if (smlx->i != (int)smlx->it)
				*(unsigned *)(smlx->data_addr + (smlx->yy * smlx->size) +
					(smlx->xx * smlx->bpx / 8)) = 0x0000FFFF * (int)smlx->i *
					600;
			smlx->yy++;
		}
		smlx->xx++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

void		mandelbrot_init(t_mlx *truc)
{
	truc->x1 = -3.4;
	truc->x2 = 0.6;
	truc->y1 = -1.6;
	truc->y2 = 1.2;
	truc->zoom = 150;
	truc->it = 30;
	truc->image_x = 800;
	truc->image_y = 500;
	mandelbrot(truc);
}
