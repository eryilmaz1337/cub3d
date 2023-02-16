/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_mini_map_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:05:39 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 18:02:18 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixel_put(t_cub3d *main, int x, int y, t_color_data color)
{
	t_color_data	data;

	data.tmp_x = x;
	data.tmp_y = y;
	data.flag = 1;
	data.transparent = color.transparent;
	data.red = color.red;
	data.green = color.green;
	data.blue = color.blue;
	main->color = data;
	img_colors(main, main->mini_map_img_adress,
		main->mini_map->map_img_size_y, main->mini_map->map_img_size_x);
}

void	put_to_ray_addr(t_cub3d *main, double ray_y, double ray_x)
{
	if (main->mw * \
	(int)floor(main->mini_map->map_img_size_y \
	* ray_y) + (int)floor(main->mini_map->map_img_size_x \
	* ray_x) >= 0 && \
	main->mw * \
	(int)floor(main->mini_map->map_img_size_y \
	* ray_y) + (int)floor(main->mini_map->map_img_size_x \
	* ray_x) < main->mh * main->mw)
	{
		main->mini_map->ray_addr[main->mw * \
	(int)floor(main->mini_map->map_img_size_y \
	* ray_y) + (int)floor(main->mini_map->map_img_size_x \
	* ray_x)] = rgb_to_hex(color_assignment(100, 0, 255, 0));
	}
}

void	draw_ray(int x, int y, double angle, t_cub3d *main)
{
	double	ray_x;
	double	ray_y;
	double	dx;
	double	dy;

	ray_x = main->player->def_p_x;
	ray_y = main->player->def_p_y;
	dx = main->ray.distance * fabs(cos(angle_to_radyan(angle))) * x;
	dy = main->ray.distance * fabs(sin(angle_to_radyan(angle))) * y;
	dx /= main->ray.distance;
	dy /= main->ray.distance;
	while (1)
	{
		if (!is_wall_v2(main, ray_x, ray_y))
			put_to_ray_addr(main, ray_y, ray_x);
		else
		{
			main->ray.pos_x = ray_x;
			main->ray.pos_y = ray_y;
			draw_3d(main, main->ray.distance, angle);
			break ;
		}
		ray_x += dx / 100;
		ray_y += dy / 100;
	}
}

static void	map_paint_c(t_cub3d *main, int x, int y)
{
	if (main->map->map[y][x] == 'K')
		ft_pixel_put(main, main->mini_map->map_img_size_x \
		* x, main->mini_map->map_img_size_y * y, \
		color_assignment(0, 255, 0, 0));
	else if (main->map->map[y][x] == 'A')
		ft_pixel_put(main, main->mini_map->map_img_size_x \
		* x, main->mini_map->map_img_size_y * y, \
		color_assignment(0, 0, 0, 255));
	else if (main->map->map[y][x] == 'L')
		ft_pixel_put(main, main->mini_map->map_img_size_x \
		* x, main->mini_map->map_img_size_y * y, \
		color_assignment(0, 255, 0, 255));
}

void	map_paint(t_cub3d *main)
{
	int	x;
	int	y;

	y = -1;
	while (main->map->map[++y])
	{
		x = -1;
		while (main->map->map[y][++x])
		{
			if (main->map->map[y][x] == '1')
				ft_pixel_put(main, main->mini_map->map_img_size_x \
				* x, main->mini_map->map_img_size_y * y, \
				color_assignment(0, 255, 255, 0));
			else if (main->map->map[y][x] == '0')
				ft_pixel_put(main, main->mini_map->map_img_size_x \
				* x, main->mini_map->map_img_size_y * y, \
				color_assignment(0, 150, 75, 0));
			else
				map_paint_c(main, x, y);
		}
	}
}
