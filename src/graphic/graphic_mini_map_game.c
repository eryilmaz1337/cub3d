/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_mini_map_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/11 17:59:28 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void ft_pixel_put(t_cub3d *main, int x, int y, t_color_data color)
{
	t_color_data data;
	data.tmp_x = x;
	data.tmp_y = y;
	data.flag = 1;
	data.transparent = color.transparent;
	data.red = color.red;
	data.green = color.green;
	data.blue = color.blue;
	img_colors(main->mini_map_img_adress, main->mini_map->map_img_size_y, main->mini_map->map_img_size_x, data);
}


void draw_ray(double distance, int x, int y, double angle, t_cub3d *main, int ray_number)
{
	double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;

    ray_x = main->player->def_p_x;
    ray_y = main->player->def_p_y;
    dx = distance * fabs(cos(angle * (M_PI / 180.0))) * x;
    dy = distance * fabs(sin(angle * (M_PI / 180.0))) * y;
    dx /= distance;
    dy /= distance;
	while (1)
	{
        if (!is_wall_v2(main,ray_x, ray_y))
            main->mini_map->ray_addr[MINI_MAP_WIDTH * (int)floor(main->mini_map->map_img_size_y * ray_y) + (int)floor(main->mini_map->map_img_size_x * ray_x)] = rgb_to_hex(color_assignment(0,0,255,0));
        else
		{
			main->ray.pos_x = ray_x;
			main->ray.pos_y = ray_y;
			draw_3d(main, distance, ray_number);
			break;
		}
        ray_x += dx / 100;
        ray_y += dy / 100;
    }
}

void map_paint(t_cub3d *main)
{
	int x;
	int y;

	y = -1;
	while (main->map->map[++y])
	{
		x = -1;
		while (main->map->map[y][++x])
		{
			if (main->map->map[y][x] == '1')
				ft_pixel_put(main, main->mini_map->map_img_size_x * x, main->mini_map->map_img_size_y * y, color_assignment(0, 255, 255, 0));
			else if (main->map->map[y][x] == '0')
				ft_pixel_put(main, main->mini_map->map_img_size_x * x, main->mini_map->map_img_size_y * y, color_assignment(0, 150, 75, 0));
		}
	}
}
