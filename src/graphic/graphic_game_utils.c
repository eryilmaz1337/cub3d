/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:04:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/11 16:23:21 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// bu dosya mini_map ve ana ekran resmi için ortak kullanılan fonksiyonları içeriri lütfen sadece ilgili fonksiyonları ayırın "yazan=erdem"
#include "cub3d.h"

t_color_data color_assignment(int transparent, int red, int green, int blue)
{
	t_color_data color;

	color.transparent = transparent;
	color.red = red;
	color.green = green;
	color.blue = blue;
	color.tmp_x = 0;
	color.tmp_y = 0;
	color.flag = 0;
	return (color);
}

unsigned long	rgb_to_hex(t_color_data color)
{
	return ((color.transparent << 24)+(color.red << 16) + (color.green << 8) + (color.blue));
}

double	angle_to_radyan(double ang)
{
	return(ang * (M_PI / 180.0));
}

void	img_colors(int *img, int height, int width, t_color_data color)
{
	int	i;
	int	k;
	k = 0;

	while (k != height)
	{
		i = -1;
		while (++i != width)
		{
			if (color.flag == 1)
				img[(int)MINI_MAP_WIDTH * (color.tmp_y + k) + (color.tmp_x + i)] = rgb_to_hex(color);
			else
				img[(int)width * k + i] = rgb_to_hex(color);
		}
		k++;
	}
}
