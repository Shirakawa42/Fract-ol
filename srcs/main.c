/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:37:13 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/26 17:37:57 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_mlx *smlx)
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
			{
				smlx->tmp = smlx->zr;
				smlx->zr = smlx->zr * smlx->zr -
					smlx->zi * smlx->zi + smlx->cr;
				smlx->zi = 2 * smlx->zi * smlx->tmp + smlx->ci;
				smlx->i++;
			}
			if (smlx->i != (int)smlx->it)
				*(unsigned *)(smlx->data_addr + (smlx->yy * smlx->size) +
					(smlx->xx * smlx->bpx / 8)) = 400 * smlx->i /
					smlx->it * 2;
			smlx->yy++;
		}
		smlx->xx++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

void	mandelbrot_init(t_mlx *truc)
{
	truc->x1 = -3.4;
	truc->x2 = 0.6;
	truc->y1 = -1.6;
	truc->y2 = 1.2;
	truc->zoom = 150;
	truc->it = 35;
	truc->image_x = 800;
	truc->image_y = 500;
	mandelbrot(truc);
}

void	reload(t_mlx *truc)
{
	mlx_destroy_image(truc->mlx, truc->img);
	truc->img = mlx_new_image(truc->mlx, 800, 500);
	truc->data_addr = mlx_get_data_addr(truc->img, 
		&truc->bpx, &truc->size, &truc->idgaf);
	mandelbrot(truc);
}

int		mouse_input(int keycode, int x, int y, t_mlx *truc)
{
	float	x_real;
	float	y_real;

	x_real = (x / truc->zoom) + truc->x1;
	y_real = (y / truc->zoom) + truc->y1;
	if (keycode == 4)
	{
		truc->zoom *= 1.1;
		truc->it *= 1.04;
		truc->x1 = x_real - (x / truc->zoom);
		truc->y1 = y_real - (y / truc->zoom);
		reload(truc);
	}
	if (keycode == 5)
	{
		truc->zoom *= 0.8;
		truc->it *= 0.96;
		truc->x1 = x_real - (x / truc->zoom);
		truc->y1 = y_real - (y / truc->zoom);
		reload(truc);
	}
	return (0);
}

int		keyboard_input(int keycode, t_mlx *truc)
{
	if (keycode == 65307)
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
	truc->x = x - 400;
	truc->y = y - 250;
	return (0);
}

int		main(void)
{
	t_mlx	*smlx;

	smlx = (t_mlx*)malloc(sizeof(t_mlx));
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, 800, 500, "Fract'ol");
	smlx->img = mlx_new_image(smlx->mlx, 800, 500);
	smlx->data_addr = mlx_get_data_addr(smlx->img, &smlx->bpx, &smlx->size, &smlx->idgaf);
	mandelbrot_init(smlx);
	mlx_key_hook(smlx->win, keyboard_input, smlx);
	mlx_mouse_hook(smlx->win, mouse_input, smlx);
	mlx_hook(smlx->win, 6, 1L<<6, mouse_motion, smlx);
	mlx_loop(smlx->mlx);
}
