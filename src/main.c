/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:37:13 by lvasseur          #+#    #+#             */
/*   Updated: 2017/02/01 12:45:36 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_mlx(t_mlx *smlx)
{
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, 800, 500, "Fract'ol");
	smlx->img = mlx_new_image(smlx->mlx, 800, 500);
	smlx->data_addr = mlx_get_data_addr(smlx->img, &smlx->bpx,
			&smlx->size, &smlx->idgaf);
	mlx_key_hook(smlx->win, keyboard_input, smlx);
	mlx_mouse_hook(smlx->win, mouse_input, smlx);
	mlx_hook(smlx->win, 6, 1L << 6, mouse_motion, smlx);
	return (0);
}

void	main_mandelbrot(t_mlx *smlx)
{
	smlx->which = 1;
	init_mlx(smlx);
	mandelbrot_init(smlx);
	mlx_loop(smlx->mlx);
}

void	main_julia(t_mlx *smlx)
{
	smlx->which = 2;
	init_mlx(smlx);
	julia_init(smlx);
	mlx_loop(smlx->mlx);
}

void	main_burning_ship(t_mlx *smlx)
{
	smlx->which = 3;
	init_mlx(smlx);
	burning_ship_init(smlx);
	mlx_loop(smlx->mlx);
}

int		main(int ac, char **av)
{
	t_mlx	*smlx;

	if ((smlx = (t_mlx*)malloc(sizeof(t_mlx))) == 0)
		return (-1);
	smlx->xrotate = 0;
	smlx->yrotate = 0;
	smlx->zrotate = 0;
	smlx->which = 0;
	smlx->xpadding = 0;
	smlx->ypadding = 0;
	smlx->motion = 1;
	smlx->s = 1;
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		main_mandelbrot(smlx);
	else if (ac == 2 && ft_strcmp(av[1], "julia") == 0)
		main_julia(smlx);
	else if (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0)
		main_burning_ship(smlx);
	else
	{
		ft_putstr("usage: ./fractol \"mandelbrot\" or ");
		ft_putstr("\"julia\" or \"burning_ship\"\n");
		exit(0);
	}
	return (0);
}
