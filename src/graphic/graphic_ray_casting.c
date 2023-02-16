/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ray_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 18:02:18 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

double	ray_vertical(t_cub3d *main, double angle, int x, int y)
{
	double	vdy;
	double	vdx;
	double	distance;

	if (x == -1)
		vdx = main->player->def_p_x - floor(main->player->def_p_x);
	else
		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
	vdy = fabs(tan(angle_to_radyan(angle)) * vdx);
	distance = 10000;
	while (!while_check_v(main, vdx * x, vdy * y))
	{
		vdx += 0.0001;
		if (!if_check_v(main, vdy * y, vdx * x))
			set_last_hit_v(main, vdx * x, vdy * y);
		if (is_wall_v2(main, main->player->def_p_x + vdx \
		* x, main->player->def_p_y + vdy * y))
		{
			distance = sqrt(((vdx * x) * (vdx * x)) + ((vdy * y) * (vdy * y)));
			break ;
		}
		vdx += 1.0 - 0.0001;
		vdy = fabs(tan(angle_to_radyan(angle)) * vdx);
	}
	return (distance);
}

double	ray_horizonal(t_cub3d *main, double angle, int x, int y)
{
	double	hdy;
	double	hdx;
	double	distance;

	if (y == -1)
		hdy = main->player->def_p_y - floor(main->player->def_p_y);
	else
		hdy = ceil(main->player->def_p_y) - main->player->def_p_y;
	hdx = fabs(hdy / tan(angle_to_radyan(angle)));
	distance = 10000;
	while (!while_check_v(main, hdx * x, hdy * y))
	{
		hdy += 0.0001;
		if (!if_check_h(main, hdy * y, hdx * x))
			set_last_hit_h(main, hdx * x, hdy * y);
		if (is_wall_v2(main, main->player->def_p_x + hdx * x,
				main->player->def_p_y + hdy * y))
		{
			distance = sqrt(((hdx * x) * (hdx * x)) + ((hdy * y) * (hdy * y)));
			break ;
		}
		hdy = hdy + 1.0 - 0.0001;
		hdx = fabs(hdy / tan(angle_to_radyan(angle)));
	}
	return (distance);
}

void	ray_calculator(t_cub3d *main, double angle)
{
	double	distance_v;
	double	distance_h;
	int		x;
	int		y;

	x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
	y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;
	main->ray.dir_x = x;
	main->ray.dir_y = y;
	main->ray.sp_ray = false;
	distance_v = ray_vertical(main, angle, x, y);
	distance_h = ray_horizonal(main, angle, x, y);
	ray_calculator_c(main, distance_v, distance_h);
	main->ray.o_distance = main->ray.distance;
	main->ray.distance = main->ray.distance
		* cos((main->player->angle - angle) * (M_PI / 180.0));
	draw_ray(x, y, angle, main);
}

static void	ray_c_norm(t_cub3d *main)
{
	main->color = color_assignment(255, 0, 0, 0);
	img_colors(main, main->mini_map->ray_addr, main->mh,
		main->mw);
}

void	raycasting(t_cub3d *main)
{
	double	angle;

	main->player->def_p_x = (main->player->player_x
			+ (main->mini_map->map_img_size_x / 2))
		/ main->mini_map->map_img_size_x;
	main->player->def_p_y = (main->player->player_y
			+ (main->mini_map->map_img_size_y / 2))
		/ main->mini_map->map_img_size_y;
	angle = main->player->angle - (ROT_ANGLE_USER / 2);
	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	ray_c_norm(main);
	main->ray.ray_number = 0;
	while (main->ray.ray_number < SCREEN_WIDTH)
	{
		main->ray.sp_distance = 0;
		ray_calculator(main, angle);
		angle += (double)ROT_ANGLE_USER / (double)SCREEN_WIDTH;
		main->ray.ray_number++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window,
		main->mini_map->ray_img, 0, 0);
}
