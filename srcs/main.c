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

void	lourd_carre(t_mlx *smlx)
{
	float	x1 = -2.1 + smlx->x1;
	float	x2 = 0.6 + smlx->x2;
	float	y1 = -1.2 + smlx->y1;
	float	y2 = 1.2 + smlx->y2;
	int		image_x = 1300;
	int		image_y = 700;
	int		iteration_max = 5 + smlx->it;
	float	zoom_x = (image_x / (x2 - x1)) * smlx->zoom;
	float	zoom_y = (image_y / (y2 - y1)) * smlx->zoom;
	int		x = 0;
	int		y = 0;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		i;
	float	tmp;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < iteration_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				*(unsigned *)(smlx->data_addr + (y * smlx->size) +
						(x * smlx->bpx / 8)) = 0x0000FFFF;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(smlx->mlx, smlx->win, smlx->img, 0, 0);
}

int		mouse_input(int keycode, int x, int y, void *truc)
{
	y = 0;
	if (keycode == 1 && x < 650)
		((t_mlx*)truc)->it += 1;
	if (keycode == 1 && x >= 650)
		((t_mlx*)truc)->it -= 1;
	mlx_destroy_image(((t_mlx*)truc)->mlx, ((t_mlx*)truc)->img);
	((t_mlx*)truc)->img = mlx_new_image(((t_mlx*)truc)->mlx, 1300, 700);
	((t_mlx*)truc)->data_addr = mlx_get_data_addr(((t_mlx*)truc)->img, 
		&((t_mlx*)truc)->bpx, &((t_mlx*)truc)->size, &((t_mlx*)truc)->idgaf);
	lourd_carre(truc);
	return (0);
}

int		keyboard_input(int keycode, void *truc)
{
	ft_putchar('\n');
	ft_putnbr(keycode);
	if (keycode == 69)
		((t_mlx*)truc)->zoom += 0.02;
	if (keycode == 78)
		((t_mlx*)truc)->zoom -= 0.02;
	if (keycode == 87)
		((t_mlx*)truc)->x1 += 0.05;
	if (keycode == 86)
		((t_mlx*)truc)->y2 -= 0.05;
	mlx_destroy_image(((t_mlx*)truc)->mlx, ((t_mlx*)truc)->img);
	((t_mlx*)truc)->img = mlx_new_image(((t_mlx*)truc)->mlx, 1300, 700);
	((t_mlx*)truc)->data_addr = mlx_get_data_addr(((t_mlx*)truc)->img, 
		&((t_mlx*)truc)->bpx, &((t_mlx*)truc)->size, &((t_mlx*)truc)->idgaf);
	lourd_carre(truc);
	return (0);
}

int		main(void)
{
	t_mlx	*smlx;

	smlx = (t_mlx*)malloc(sizeof(t_mlx));
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, 1300, 700, "Fract'ol");
	smlx->img = mlx_new_image(smlx->mlx, 1300, 700);
	smlx->data_addr = mlx_get_data_addr(smlx->img, &smlx->bpx, &smlx->size, &smlx->idgaf);
	smlx->zoom = 1;
	smlx->it = 1;
	smlx->x1 = 0;
	smlx->x2 = 0;
	smlx->y1 = 0;
	smlx->y2 = 0;
	lourd_carre(smlx);
	mlx_key_hook(smlx->win, keyboard_input, smlx);
	mlx_mouse_hook(smlx->win, mouse_input, smlx);
	mlx_hook(smlx->mlx, )
	mlx_loop(smlx->mlx);
}
