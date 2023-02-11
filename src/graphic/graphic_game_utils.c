/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:04:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/10 20:15:39 by uercan           ###   ########.fr       */
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
	while (ang <= 0.0)
		ang += 360;
	while (ang > 360.0)
		ang -= 360;
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

void	draw_xpm_to_wall(t_cub3d *main, int location, int WH, int* xpm)
{
	int	i;
	int find_pixel;
	int	img_loc;
	int	color;

	i = -1;
	find_pixel = 0;
	if (main->ray.hit_h == true)
		find_pixel = ((main->ray.pos_x - floor(main->ray.pos_x)) * 64); // resimdeki pixel sütun konumunu bulur.
	else if (main->ray.hit_v == true)
		find_pixel = ((main->ray.pos_y - floor(main->ray.pos_y)) * 64); // resimdeki pixel sütun konumunu bulur.
	if (WH >= 4000)
		WH = 4000;
	img_loc = (64 * (64 / 2)) + find_pixel;
	while (++i < WH && (location - (SCREEN_WIDTH * i)) <= SCREEN_HEIGHT * SCREEN_WIDTH && img_loc - 64 * (int)((double)i * ((double)64 / (double)(WH * 2))) <= 64 * 64)
	{
		if (img_loc - 64 * (int)((double)i * ((double)64 / (double)(WH * 2))) >= 0)
		{
			color = xpm[img_loc - 64 * (int)((double)i * ((double)64 / (double)(WH * 2)))];//xpm.img.addr[img_loc - (xpm.width * ((i / (WINDOW_H / main->xpm[0].height)) % xpm.height))]
			if ((location - (SCREEN_WIDTH * i)) >= 0 && color >= 0) //yukarı
				main->game_img_adress[(location - (SCREEN_WIDTH * i))] = color;
		}
		if (img_loc + 64 * (int)((double)i * ((double)64 / (double)(WH * 2))) < 64 * 64)
		{
			color = xpm[img_loc + 64 * (int)((double)i * ((double)64 / (double)(WH * 2)))];//xpm.img.addr[img_loc + (xpm.width * ((i / (WINDOW_H / main->xpm[0].height)) % xpm.height))];
			if ((SCREEN_HEIGHT * SCREEN_WIDTH) >= (location + (SCREEN_WIDTH * i)) && color >= 0) // aşağı
				main->game_img_adress[(location + (SCREEN_WIDTH * i))] = color;
		}
	}
}

