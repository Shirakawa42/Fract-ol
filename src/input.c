/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:51:12 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 16:46:36 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_input(int keycode, int x, int y, t_mlx *truc)
{
	float	xtmp;
	float	ytmp;

	xtmp = (x / truc->zoom) + truc->x1;
	ytmp = (y / truc->zoom) + truc->y1;
	if (keycode == 4 && truc->zoom < 1500000000)
	{
		truc->zoom *= 1.3;
		truc->it *= 1.25;
		truc->x1 = xtmp - (x / truc->zoom);
		truc->y1 = ytmp - (y / truc->zoom);
		reload(truc);
	}
	if (keycode == 5)
	{
		truc->zoom *= 0.7;
		truc->it *= 0.75;
		truc->x1 = xtmp - (x / truc->zoom);
		truc->y1 = ytmp - (y / truc->zoom);
		reload(truc);
	}
	mouse_input2(keycode, truc);
	return (0);
}

void	keyboard_input2(int keycode, t_mlx *truc)
{
	if (keycode == 13)
		truc->ypadding -= 5;
	if (keycode == 1)
		truc->ypadding += 5;
	if (keycode == 0)
		truc->xpadding -= 5;
	if (keycode == 2)
		truc->xpadding += 5;
	if (keycode == 82)
	{
		if (truc->motion == 1)
			truc->motion = 0;
		else
			truc->motion = 1;
		truc->cijulia = 0;
	}
}

int		keyboard_input(int keycode, t_mlx *truc)
{
	if (keycode == 53)
	{
		free(truc);
		exit(0);
		return (0);
	}
	if (keycode == 83)
		truc->s = 1;
	if (keycode == 84)
		truc->s = 2;
	if (keycode == 85)
		truc->s = 3;
	if (keycode == 126)
		truc->xrotate += 5;
	if (keycode == 125)
		truc->xrotate -= 5;
	if (keycode == 123)
		truc->yrotate -= 5;
	if (keycode == 124)
		truc->yrotate += 5;
	keyboard_input2(keycode, truc);
	reload(truc);
	return (0);
}

int		mouse_motion(int x, int y, t_mlx *truc)
{
	x = x - 400;
	y = y - 250;
	if (truc->which == 2 && truc->motion == 1)
	{
		truc->cijulia = (float)x / ((truc->zoom / 2) + 350);
		reload(truc);
	}
	return (0);
}
