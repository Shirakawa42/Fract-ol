/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:55:41 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 11:56:37 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

void	pixel(int x, int y, t_mlx *smlx)
{
	if (x < 800 && x > 0 && y < 500 && y > 0)
		*(unsigned *)(smlx->data_addr + (y * smlx->size) +
			(x * smlx->bpx / 8)) = palet(smlx->i, smlx);
}

void	matrice_ator(t_mlx *truc, float x, float y)
{
	float	z;

	z = 0;
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
