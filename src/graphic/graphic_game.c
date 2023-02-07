/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/04 15:32:33 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void draw_3d(t_cub3d *main, double distance, int ray_number)
{
	int loc;
	int oran;
	distance = distance * main->mini_map->map_img_size_x * ((double)SCREEN_HEIGHT / (double)SCREEN_WIDTH);
	loc = (SCREEN_WIDTH * main->mini_map->screen_focus) - ray_number;// 180000. pixel
	oran = (((double)SCREEN_HEIGHT / 2.0) / distance) * 16.0;
	if (main->ray.last_hit == 'K')// kapı
		draw_xpm_to_wall(main, loc, oran, main->map->door_addr);
	else if (main->ray.hit_h == true && main->ray.dir_y == -1)// kuzey
		draw_xpm_to_wall(main, loc, oran, main->map->NO_texture_addr);
	else if (main->ray.hit_h == true && main->ray.dir_y == 1)// guney
		draw_xpm_to_wall(main, loc, oran, main->map->SO_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == 1)// dogu
		draw_xpm_to_wall(main, loc, oran, main->map->EA_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == -1)// bati
		draw_xpm_to_wall(main, loc, oran, main->map->WE_texture_addr);
}

void	put_backscreen(t_cub3d *main)
{
	int	i;
	int	k;
	int	sky;

	k = 0;
	i = 0;
	sky = main->mini_map->screen_focus;
	while (k != SCREEN_HEIGHT)
	{
		i = -1;
		while (++i != SCREEN_WIDTH && k != sky)
		{
			if ((i * k) / 7 % 10000 == 0)
				main->game_img_adress[SCREEN_WIDTH * k + i] = 0xffe100;
			else
				main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->C_rgb_code;
		}
		i = -1;
		while (++i != SCREEN_WIDTH && k >= sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->F_rgb_code;
		k++;
	}
}
