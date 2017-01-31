/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:55:41 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/31 16:58:52 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	matrice_ator(t_mlx *truc, float x, float y, float z)
{
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

void	xyz(t_mlx *truc)
{
	int		x;
	int		y;

	truc->rotx = truc->xrotate * 0.0174533;
	truc->roty = truc->yrotate * 0.0174533;
	truc->rotz = truc->zrotate * 0.0174533;
	y = 0;
	truc->fat = 0;
	while (y < truc->nby)
	{
		x = 0;
		while (x < truc->nbx)
		{
			matrice_ator(truc, x, y);
			x++;
			truc->fat++;
		}
		y++;
	}
}
