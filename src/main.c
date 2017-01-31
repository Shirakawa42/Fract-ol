/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:37:13 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/30 13:41:22 by lvasseur         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_mlx	*smlx;

	if ((smlx = (t_mlx*)malloc(sizeof(t_mlx))) == 0)
		return (-1);
	smlx->which = 0;
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		smlx->which = 1;
		init_mlx(smlx);
		mandelbrot_init(smlx);
		mlx_loop(smlx->mlx);
	}
	else if (ac == 2 && ft_strcmp(av[1], "julia") == 0)
	{
		smlx->which = 2;
		init_mlx(smlx);
		julia_init(smlx);
		mlx_loop(smlx->mlx);
	}
	else
	{
		ft_putstr("usage: ./fractol \"mandelbrot\" or \"julia\"\n");
		exit(0);
	}
	return (0);
}
