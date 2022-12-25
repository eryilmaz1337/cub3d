/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_ultis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:04:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/25 18:04:41 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */


// bu dosya mini_map ve ana ekran resmi için ortak kullanılan fonksiyonları içeriri lütfen sadece ilgili fonksiyonları ayırın "yazan=erdem"
#include "../../lib/cub3d.h"

unsigned long	rgb_to_hex(int transparent ,int r, int g, int b)//0x_00_00_ff
{
	return ((transparent << 24)+(r << 16) + (g << 8) + (b));
}
