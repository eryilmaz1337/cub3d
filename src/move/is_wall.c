/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/09 16:52:35 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_cub3d *main, double x, double y, double new_x, double new_y)
{
	double	collider;

	collider = 5;
	new_x = (x + (main->mini_map->map_img_size_x / 2)) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2)) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == 'K')
		return (2);
	new_x = (x + (main->mini_map->map_img_size_x / 2) - collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) - collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
		return (1);
	new_x = (x + (main->mini_map->map_img_size_x / 2) + collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) - collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
		return (1);
	new_x = (x + (main->mini_map->map_img_size_x / 2) - collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) + collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
		return (2);
	new_x = (x + (main->mini_map->map_img_size_x / 2) + collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) + collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
		return (1);
	return (0);
}
