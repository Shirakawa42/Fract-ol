/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:11 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/31 16:45:28 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		palet1(int i)
{
	if (i < 2)
		return (0x99FFCC * i);
	else if (i < 4)
		return (0xCCFFFF * i);
	else if (i < 8)
		return (0xFFFF99 * i);
	else if (i < 16)
		return (0xFFFF00 * i);
	else if (i < 32)
		return (0xFFCC33 * i);
	else if (i < 64)
		return (0xFF9900 * i);
	else if (i < 128)
		return (0xFF6600 * i);
	else if (i < 256)
		return (0xFF3300 * i);
	else if (i < 512)
		return (0xFF0000 * i);
	else if (i < 1024)
		return (0xCC0000 * i);
	return (0x990000 * i);
}

int		palet2(int i)
{
	if (i < 2)
		return (0x999900 * i);
	else if (i < 4)
		return (0x9999FF * i);
	else if (i < 8)
		return (0xFF6600 * i);
	else if (i < 16)
		return (0x9999FF * i);
	else if (i < 32)
		return (0x9900FF * i);
	else if (i < 64)
		return (0x66FFFF * i);
	else if (i < 128)
		return (0x0033FF * i);
	else if (i < 256)
		return (0x660033 * i);
	else if (i < 512)
		return (0x669900 * i);
	else if (i < 1024)
		return (0x009900 * i);
	return (0x000066 * i);
}

int		palet3(int i)
{
	if (i < 2)
		return (0x33CC33 * i);
	else if (i < 4)
		return (0xFF09FF * i);
	else if (i < 8)
		return (0xCC9900 * i);
	else if (i < 16)
		return (0xCC3300 * i);
	else if (i < 32)
		return (0x00FF00 * i);
	else if (i < 64)
		return (0xFF00FF * i);
	else if (i < 128)
		return (0x66CC33 * i);
	else if (i < 256)
		return (0xCCCC00 * i);
	else if (i < 512)
		return (0x9933FF * i);
	else if (i < 1024)
		return (0x99FFFF * i);
	return (0x000099 * i);
}

int		palet(int i, t_mlx *truc)
{
	if (truc->s == 2)
		return (palet2(i));
	if (truc->s == 3)
		return (palet3(i));
	return (palet1(i));
}
