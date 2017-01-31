/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:51:12 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/30 14:28:40 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reload(t_mlx *truc)
{
	mlx_destroy_image(truc->mlx, truc->img);
	truc->img = mlx_new_image(truc->mlx, 800, 500);
	truc->data_addr = mlx_get_data_addr(truc->img,
		&truc->bpx, &truc->size, &truc->idgaf);
	if (truc->which == 1)
		mandelbrot(truc);
	if (truc->which == 2)
		julia(truc);
}

int		mouse_input(int keycode, int x, int y, t_mlx *truc)
{
	float	xtmp;
	float	ytmp;

	xtmp = (x / truc->zoom) + truc->x1;
	ytmp = (y / truc->zoom) + truc->y1;
	if (keycode == 4 && truc->zoom < 1500000000)
	{
		truc->zoom *= 1.3;
		truc->it *= 1.2;
		truc->x1 = xtmp - (x / truc->zoom);
		truc->y1 = ytmp - (y / truc->zoom);
		reload(truc);
	}
	if (keycode == 5)
	{
		truc->zoom *= 0.7;
		truc->it *= 0.8;
		truc->x1 = xtmp - (x / truc->zoom);
		truc->y1 = ytmp - (y / truc->zoom);
		reload(truc);
	}
	return (0);
}

int		keyboard_input(int keycode, t_mlx *truc)
{
	if (keycode == 53)
	{
		free(truc);
		exit(0);
		return (0);
	}
	reload(truc);
	return (0);
}

int		mouse_motion(int x, int y, t_mlx *truc)
{
	x = x - 400;
	y = y - 250;
	if (truc->which == 2)
	{
		truc->cijulia = (float)x / 400;
		reload(truc);
	}
	return (0);
}

