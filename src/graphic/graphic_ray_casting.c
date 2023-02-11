/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ray_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/10 20:10:07 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_control(t_cub3d *main, double x, double y)
{
	int	xX;
	int	yY;
	
	xX = (int)floor(x);
	yY = (int)floor(y);
	if (x >= 0 && x < main->map->map_max_line && y >= 0 && y < main->map->map_lines_num)
		if (main->ray.ray_num == SCREEN_WIDTH / 2)
		{
			if (main->map->map[yY][xX] == 'K' && main->player->key_e && (int)main->ray.distance < 2)
			{
				main->map->map[yY][xX] = 'A';
				main->player->key_e = false;
			}
			else if (main->map->map[yY][xX] == 'A' && main->player->key_e && is_door(main, main->player->player_x, main->player->player_y) != 'A')
			{
				main->map->map[yY][xX] = 'K';
				main->player->key_e = false;
			}
		}
}

int	is_wall_v2(t_cub3d *main, double x, double y)
{
	int	xX;
	int	yY;

	xX = (int)floor(x);
	yY = (int)floor(y);
	if (x < 0 || x > main->map->map_max_line || y < 0 || y > main->map->map_lines_num)
		return (0);
	return (ft_strchr("0NSEWA", main->map->map[yY][xX]) == NULL);
}

double	ray_vertical(t_cub3d *main, double angle, int x, int y)
{
	double vdy;
	double vdx;
	bool hit = false;

	if (x == -1)
		vdx = main->player->def_p_x - floor(main->player->def_p_x);
	else
		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
	vdy = fabs(tan(angle_to_radyan(angle)) * vdx);
	double tmp_x = vdx * x;
	double tmp_y = vdy * y;

	while (main->player->def_p_x + vdx * x - 0.0001 >= 0
		&& main->player->def_p_x + vdx * x - 0.0001 <= main->map->map_max_line
		&& main->player->def_p_y + vdy * y >= 0
		&& main->player->def_p_y + vdy * y <= main->map->map_lines_num)
	{
		vdx += 0.0001;
		// printf("%c\n", main->map->map[(int)(main->player->def_p_y + vdy*y)][(int)(main->player->def_p_x + vdx*x)]);
		if ((int)(main->player->def_p_y + vdy*y) >= 0 && 
		(int)(main->player->def_p_y + vdy*y) < main->map->map_lines_num && 
		(int)(main->player->def_p_x + vdx*x) >= 0 && 
		(int)(main->player->def_p_x + vdx*x) < main->map->map_max_line
		)
		main->ray.lh_y = main->map->map[(int)(main->player->def_p_y + vdy*y)][(int)(main->player->def_p_x + vdx*x)];
		door_control(main, main->player->def_p_x + vdx * x, main->player->def_p_y + vdy * y);
		if (is_wall_v2(main, main->player->def_p_x + vdx*x, main->player->def_p_y + vdy*y))
		{
			hit = true;
			tmp_x = vdx * x;
			tmp_y = vdy * y;
			break;
		}
		vdx += 1.0 - 0.0001;
		vdy = fabs(tan(angle_to_radyan(angle)) * vdx);
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
	hdx = fabs(hdy / tan(angle_to_radyan(angle)));
	double tmp_y = hdy*y;
	double tmp_x = hdx*x;

	while (main->player->def_p_x + hdx * x >= 0
		&& main->player->def_p_x + hdx * x <= main->map->map_max_line
		&& main->player->def_p_y + hdy * y - 0.0001 >= 0
		&& main->player->def_p_y + hdy * y - 0.0001 <= main->map->map_lines_num)
	{
		hdy += 0.0001;
		if ((int)(main->player->def_p_y + hdy*y) >= 0 && 
		(int)(main->player->def_p_y + hdy*y) < main->map->map_lines_num && 
		(int)(main->player->def_p_x + hdx*x) >= 0 && 
		(int)(main->player->def_p_x + hdx*x) < main->map->map_max_line
		)
		main->ray.lh_x = main->map->map[(int)(main->player->def_p_y + hdy*y)][(int)(main->player->def_p_x + hdx*x)];
		door_control(main, main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y);
		if (is_wall_v2(main, main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y))
		{
			hit = true;
			tmp_y = hdy * y;
			tmp_x = hdx * x;
			break;
		}
		hdy =  hdy + 1.0 - 0.0001;
		// printf("%f\n", angle);
		hdx = fabs(hdy / tan(angle_to_radyan(angle)));
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
		main->ray.distance = distance_v;
		main->ray.hit_v = true;
		main->ray.hit_h = false;
		main->ray.last_hit = main->ray.lh_y;
	}
	else
	{
		main->ray.distance = distance_h;
		main->ray.hit_v = false;
		main->ray.hit_h = true;
		main->ray.last_hit = main->ray.lh_x;
	}
	main->ray.distance = main->ray.distance * cos((main->player->angle - angle) * (M_PI / 180.0));// balik gozunu engellemek icin.
	draw_ray(x, y, angle, main, ray_number);
}

void raycasting(t_cub3d *main)
{
	double angle;

	main->player->def_p_x = (main->player->player_x + (main->mini_map->map_img_size_x / 2)) / main->mini_map->map_img_size_x;
	main->player->def_p_y = (main->player->player_y + (main->mini_map->map_img_size_y / 2)) / main->mini_map->map_img_size_y;
	angle = main->player->angle - (ROT_ANGLE_USER / 2);
	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	img_colors(main->mini_map->ray_addr, MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
	main->ray.ray_num = 0;
	while (main->ray.ray_num < SCREEN_WIDTH)
	{
		beam_calculation(main, angle, main->ray.ray_num);
		angle += (double)ROT_ANGLE_USER / (double)SCREEN_WIDTH;
		main->ray.ray_num++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
}
