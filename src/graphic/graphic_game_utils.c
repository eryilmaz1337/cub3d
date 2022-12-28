/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:04:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 20:42:59 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// bu dosya mini_map ve ana ekran resmi için ortak kullanılan fonksiyonları içeriri lütfen sadece ilgili fonksiyonları ayırın "yazan=erdem"
#include "../../lib/cub3d.h"

unsigned long	rgb_to_hex(int transparent ,int r, int g, int b)//0x_00_00_ff
{
	return ((transparent << 24)+(r << 16) + (g << 8) + (b));
}

double	angle_to_radyan(double ang)
{
	return(ang * (M_PI / 180.0));
}