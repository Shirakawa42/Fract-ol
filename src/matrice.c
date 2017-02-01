/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:55:41 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 15:46:39 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel(int x, int y, t_mlx *smlx)
{
	if (x + smlx->xpadding < 800 && x + smlx->xpadding > 0 && y +
			smlx->ypadding < 500 && y + smlx->ypadding > 0)
		*(unsigned *)(smlx->data_addr + ((y + smlx->ypadding) * smlx->size) +
			((x + smlx->xpadding) * smlx->bpx / 8)) = smlx->color;
}

void	matrice_ator(t_mlx *truc, float x, float y)
{
	float	z;

	z = -truc->i * 2;
	truc->tmpx = x;
	truc->tmpy = y * cos(truc->rotx) + z * -sin(truc->rotx);
	truc->tmpz = y * sin(truc->rotx) + z * cos(truc->rotx);
	x = truc->tmpx * cos(truc->roty) + truc->tmpz * sin(truc->roty);
	y = truc->tmpy;
	z = truc->tmpx * -sin(truc->roty) + truc->tmpz * cos(truc->roty);
	truc->tmpx = x * cos(truc->rotz) + y * -sin(truc->rotz);
	truc->tmpy = x * sin(truc->rotz) + y * cos(truc->rotz);
	truc->tmpz = z;
}

void	xyz(int x, int y, t_mlx *truc)
{
	truc->rotx = truc->xrotate * 0.0174533;
	truc->roty = truc->yrotate * 0.0174533;
	truc->rotz = truc->zrotate * 0.0174533;
	matrice_ator(truc, x, y);
}
