/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:37:13 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/25 17:10:46 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	lourd_carre(t_mlx smlx, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			*(unsigned *)(smlx.data_addr + (j * smlx.size) +
					(i * smlx.bpx / 8)) = 0x0000FFFF;
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_mlx	smlx;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, 1300, 900, "Fract'ol");
	smlx.img = mlx_new_image(smlx.mlx, 1300, 900);
	smlx.data_addr = mlx_get_data_addr(smlx.img, &smlx.bpx, &smlx.size, &smlx.idgaf);
	lourd_carre(smlx, 500);
	mlx_put_image_to_window(smlx.mlx, smlx.win, smlx.img, 0, 0);
	mlx_loop(smlx.mlx);
}
