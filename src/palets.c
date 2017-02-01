/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:11 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 16:50:50 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_input3(t_mlx *truc)
{
	if (truc->which == 3)
	{
		truc->which = 0;
		reload(truc);
		truc->which = 4;
		sierpinski_init(truc);
	}
	else if (truc->which == 4)
	{
		truc->which = 0;
		reload(truc);
		truc->which = 1;
		mandelbrot_init(truc);
	}
}

void	mouse_input2(int keycode, t_mlx *truc)
{
	if (keycode == 1 || keycode == 2)
	{
		if (truc->which == 1)
		{
			truc->which = 0;
			reload(truc);
			truc->which = 2;
			julia_init(truc);
		}
		else if (truc->which == 2)
		{
			truc->which = 0;
			reload(truc);
			truc->which = 3;
			burning_ship_init(truc);
		}
		else if (truc->which >= 3)
			mouse_input3(truc);
	}
}

void	main_julia(t_mlx *smlx)
{
	smlx->which = 2;
	init_mlx(smlx);
	julia_init(smlx);
	mlx_loop(smlx->mlx);
}

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
	if (truc->which == 3)
		burning_ship(truc);
	if (truc->which == 4)
		sierpinski(truc);
}

int		palet(t_mlx *truc)
{
	int		i;

	i = truc->i;
	while (i > 20)
		i = i / 2;
	if (truc->s == 2)
		return (i * 0x004488BA);
	if (truc->s == 3)
		return (i * 0x006677BB);
	return (i * 0x005544AA);
}
