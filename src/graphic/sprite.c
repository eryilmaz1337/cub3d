/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:33:58 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 15:41:15 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_if_check(t_cub3d *main, int img_loc, int location, int value)
{
	int	color;
	int	i;

	i = -1;
	while (++i < value)
	{
		color = main->map->sp_addr[img_loc - 64
			* (int)((double)i
				* ((double)64 / (double)(value * 2)))];
		if ((location - (SCREEN_WIDTH * i)) >= 0
			&& main->ray.sp_value > 0 && color > 0)
			main->game_img_adress[(location - (SCREEN_WIDTH * i))] = color;
		color = main->map->sp_addr[img_loc + 64 * (int)((double)i
				* ((double)64 / (double)(value * 2)))];
		if ((SCREEN_HEIGHT * SCREEN_WIDTH) >= (location + (SCREEN_WIDTH * i))
			&& main->ray.sp_value > 0 && color > 0)
			main->game_img_adress[(location + (SCREEN_WIDTH * i))] = color;
	}
}

void	sp_paint(t_cub3d *main, int location, int find_pixel)
{
	int	img_loc;
	int	value;

	if (main->ray.sp_value >= 0 && main->ray.sp_value <= 1.0)
		find_pixel = (main->ray.sp_value) * (64);
	img_loc = (64 * (64 / 2))
		+ find_pixel;
	value = (int)((double)((64 / 2) * main->mini_map->map_img_size_x)
			/ main->ray.sp_distance);
	if (value > 4000)
		value = 4000;
	sp_if_check(main, img_loc, location, value);
}

void	sp_calculate(t_cub3d *main, double angle, int location)
{
	if (main->ray.sp_ray == true)
	{
		main->ray.sp_value = 0;
		main->ray.sp_angle = 180.0 - atan2(
				main->ray.sp_y - main->player->def_p_y,
				main->ray.sp_x - main->player->def_p_x) * (180.0 / M_PI);
		if (angle > main->ray.sp_angle)
		{
			main->ray.sp_angle = angle - main->ray.sp_angle;
			main->ray.sp_lenght = tan(main->ray.sp_angle * (M_PI / 180.0))
				* main->ray.sp_distance;
			if (main->ray.sp_lenght <= 0.5 && main->ray.sp_lenght >= -0.5)
				main->ray.sp_value = 0.5 - main->ray.sp_lenght;
		}
		else if (angle < main->ray.sp_angle)
		{
			main->ray.sp_angle = (main->ray.sp_angle - angle);
			main->ray.sp_lenght = tan(main->ray.sp_angle * (M_PI / 180.0))
				* main->ray.sp_distance;
			if (main->ray.sp_lenght <= 0.5 && main->ray.sp_lenght >= -0.5)
				main->ray.sp_value = main->ray.sp_lenght + 0.5;
		}
	}
	sp_paint(main, location, 0);
}
