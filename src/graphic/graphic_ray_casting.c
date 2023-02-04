/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ray_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/04 14:41:15 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_wall_v2(t_cub3d *main, double x, double y)
{
	int xX;
	int yY;

	xX = (int)floor(x);
	yY = (int)floor(y);
	return (ft_strchr("0NSEW", main->map->map[yY][xX]) == NULL);
}

double ray_vertical(t_cub3d *main, double angle, int x, int y)
{
	double vdy;
	double vdx;
	bool hit = false;

	if (x == -1)
		vdx = main->player->def_p_x - floor(main->player->def_p_x);
	else
		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
	vdy = fabs(tan(angle * (M_PI / 180.0)) * vdx);

	double tmp_x = vdx * x;
	double tmp_y = vdy * y;

	while (main->player->def_p_x + vdx * x - 0.0001 >= 0
		&& main->player->def_p_x + vdx * x - 0.0001 <= main->map->map_max_line
		&& main->player->def_p_y + vdy * y >= 0
		&& main->player->def_p_y + vdy * y <= main->map->map_lines_num)
	{
		vdx += 0.0001;
		if (is_wall_v2(main, main->player->def_p_x + vdx*x, main->player->def_p_y + vdy*y))
		{
			hit = true;
			tmp_x = vdx * x;
			tmp_y = vdy*y;
			break;
		}
		vdx += 1.0 - 0.0001;
		vdy = fabs(tan(angle * (M_PI / 180.0)) * vdx);
	}
	double distance;

	if (hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}

double ray_horizonal(t_cub3d *main, double angle, int x, int y)
{
	double hdy;
	double hdx;
	bool hit = false;

	if (y == -1)
		hdy = main->player->def_p_y - floor(main->player->def_p_y);
	else
		hdy = ceil(main->player->def_p_y) - main->player->def_p_y;
	hdx = fabs(hdy / tan(angle * (M_PI / 180.0)));

	double tmp_y = hdy*y;
	double tmp_x = hdx*x;

	while (main->player->def_p_x + hdx * x >= 0
		&& main->player->def_p_x + hdx * x <= main->map->map_max_line
		&& main->player->def_p_y + hdy * y - 0.0001 >= 0
		&& main->player->def_p_y + hdy * y - 0.0001 <= main->map->map_lines_num)
	{
		hdy += 0.0001;
		if (is_wall_v2(main, main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y))
		{
			hit = true;
			tmp_y = hdy * y;
			tmp_x = hdx * x;
			break;
		}
		hdy =  hdy + 1.0 - 0.0001;
		hdx = fabs(hdy / tan(angle * (M_PI / 180.0)));
	}
	double distance;
	if (hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}

void beam_calculation(t_cub3d *main, double angle, int ray_number)
{
	double distance_v;
	double distance_h;
	double distance;
	int x;
	int y;

	x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
	y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;
	main->ray.dir_x = x;
	main->ray.dir_y = y;
	distance_v = ray_vertical(main, angle, x, y);
	distance_h = ray_horizonal(main, angle, x, y);
	if(distance_v < distance_h)
	{
		distance = distance_v;
		main->ray.hit_v = true;
		main->ray.hit_h = false;
	}
	else
	{
		distance = distance_h;
		main->ray.hit_v = false;
		main->ray.hit_h = true;
	}
	distance = distance * cos((main->player->angle - angle) * (M_PI / 180.0));// balik gozunu engellemek icin.
	draw_ray(distance, x, y, angle, main, ray_number);
}

void raycasting(t_cub3d *main)
{
	main->player->def_p_x = (main->player->player_x + (main->mini_map->map_img_size_x / 2)) / main->mini_map->map_img_size_x;
	main->player->def_p_y = (main->player->player_y + (main->mini_map->map_img_size_y / 2)) / main->mini_map->map_img_size_y;
	double angle;
	int ray_number;
	ray_number = 0;
	angle = main->player->angle - (ROT_ANGLE_USER / 2);
	img_colors(main->mini_map->ray_addr, MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
	while (ray_number < SCREEN_WIDTH)
	{
		beam_calculation(main, angle, ray_number);
		angle += (double)ROT_ANGLE_USER / (double)SCREEN_WIDTH;
		ray_number++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
}
