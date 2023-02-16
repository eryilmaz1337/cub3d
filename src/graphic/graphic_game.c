/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 15:49:52 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	draw_xpm_to_wall(t_cub3d *main, int location, int *xpm)
{
	int	i;
	int	find_pixel;
	int	img_loc;

	i = -1;
	find_pixel = 0;
	main->map->xpm_tmp = xpm;
	if (main->ray.hit_h == true)
		find_pixel = ((main->ray.pos_x - floor(main->ray.pos_x)) * 64);
	else if (main->ray.hit_v == true)
		find_pixel = ((main->ray.pos_y - floor(main->ray.pos_y)) * 64);
	while (main->wh >= 4000)
		main->wh--;
	if ((64 * (64 / 2)) + find_pixel < 64 * 64)
		img_loc = (64 * (64 / 2)) + find_pixel;
	while (++i < main->wh && (location - (SCREEN_WIDTH * i)) <= SCREEN_HEIGHT \
	* SCREEN_WIDTH && img_loc - 64 \
	* (int)((double)i * ((double)64 / (double)(main->wh * 2))) <= 64 * 64)
		textured_wall(main, img_loc, location, i);
}

void	draw_3d(t_cub3d *main, double distance, double angle)
{
	int		loc;

	distance = distance * main->mini_map->map_img_size_x * ((double)
			SCREEN_HEIGHT / (double)SCREEN_WIDTH);
	loc = (SCREEN_WIDTH * main->mini_map->screen_focus)
		- main->ray.ray_number;
	main->wh = (((double)SCREEN_HEIGHT / 2.0) / distance) * 16.0;
	if (main->ray.last_hit == 'K')
		draw_xpm_to_wall(main, loc, main->map->door_addr);
	else if (main->ray.hit_h == true && main->ray.dir_y == -1)
		draw_xpm_to_wall(main, loc, main->map->no_texture_addr);
	else if (main->ray.hit_h == true && main->ray.dir_y == 1)
		draw_xpm_to_wall(main, loc, main->map->so_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == 1)
		draw_xpm_to_wall(main, loc, main->map->ea_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == -1)
		draw_xpm_to_wall(main, loc, main->map->we_texture_addr);
	if (main->ray.sp_ray == true
		&& main->ray.o_distance > main->ray.sp_distance)
		sp_calculate(main, angle, loc);
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
				main->game_img_adress[SCREEN_WIDTH * k + i]
					= main->map->c_rgb_code;
		}
		i = -1;
		while (++i != SCREEN_WIDTH && k >= sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->f_rgb_code;
		k++;
	}
}

void	door_control(t_cub3d *main, double x, double y)
{
	int	x_x;
	int	y_y;

	x_x = (int)floor(x);
	y_y = (int)floor(y);
	if (x >= 0 && x < main->map->map_max_line \
	&& y >= 0 && y < main->map->map_lines_num)
	{
		if (main->ray.ray_number == SCREEN_WIDTH / 2)
		{
			if (main->map->map[y_y][x_x] == 'K' \
			&& main->player->key_e && (int)main->ray.distance < 2)
			{
				main->map->map[y_y][x_x] = 'A';
				main->player->key_e = false;
			}
			else if (main->map->map[y_y][x_x] == 'A' && main->player->key_e \
			&& is_door(main, main->player->player_x,
			main->player->player_y) != 'A')
			{
				main->map->map[y_y][x_x] = 'K';
				main->player->key_e = false;
			}
		}
	}
}
