/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:07:02 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/29 13:07:03 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int is_wall_tmp(double x, double y, t_cub3d *main)
{
	int xX;
	int yY;

	if (x < 0 || x > main->map->map_max_line || y < 0 || y > main->map->map_lines_num)
		return (1);
    xX = floor(x);
    yY = floor(y);
	if (main->map->map[yY][xX] != '1')
		return (0);
    return (1);
}


void draw_ray(double distance, int x, int y, double angle, t_cub3d *main)
{
	double    ray_x;
    double    ray_y;
    double    dx;
    double    dy;

    ray_x = main->player->def_p_x;
    ray_y = main->player->def_p_y;
    dx = distance * fabs(cos(angle * (M_PI / 180))) * x;
    dy = distance * fabs(sin(angle * (M_PI / 180))) * y;
    dx /= distance;
    dy /= distance;
    while (1)
    {
        if (!is_wall_tmp(ray_x, ray_y, main))
            main->img_ray_adress[SCREEN_WIDTH * (int)floor(main->mini_map->map_img_size_y * ray_y) + (int)floor(main->mini_map->map_img_size_x * ray_x)] = rgb_to_hex(0,0,255,0);
        else
            break;
        ray_x += dx / 100;
        ray_y += dy / 100;
    }
}


double ray_vertical(t_cub3d *main, double angle, int x, int y)
{
	double vdy;
	double vdx;

	if (x == -1)
		vdx = main->player->def_p_x - floor(main->player->def_p_x);
	else
		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
	vdy = fabs(tan(angle * (M_PI / 180)) * vdx);

	double tmp_x = vdx*x;
	double tmp_y = vdy*y;

	if (!is_wall_tmp(main->player->def_p_x + vdx * x, main->player->def_p_y + vdy * y, main))
	{
		while (1)
		{
			vdx = vdx + 1;
			vdy = fabs(tan(angle * (M_PI / 180)) * vdx);
			if (!is_wall_tmp(main->player->def_p_x + vdx*x, main->player->def_p_y + vdy*y, main))
			{
				tmp_x = vdx*x;
				tmp_y = vdy*y;
			}
			else
				break ;
		}
	}
	double distance;
	distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	//printf("vertical_distance:%f\n", distance);
	//printf("tmp_x:%f, tmp_y:%f\n", tmp_x, tmp_y);
	return (distance);
}

double ray_horizonal(t_cub3d *main, double angle, int x, int y)
{
	double hdy;
	double hdx;

	if (y == -1)
		hdy = floor(main->player->def_p_y) - main->player->def_p_y;
	else
		hdy = ceil(main->player->def_p_y) - main->player->def_p_y;
	hdx = fabs(hdy / tan(angle * (M_PI / 180)));

	double tmp_y = hdy*y;
	double tmp_x = hdx*x;

	if (!is_wall_tmp(main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y, main))
	{
		while (1)
		{
			hdy = hdy + 1;
			hdx = fabs(hdy / tan(angle * (M_PI / 180)));
			if (!is_wall_tmp(main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y, main))
			{
				tmp_y = hdy*y;
				tmp_x = hdx*x;
			}
			else
				break;
		}
	}
	double distance_tmp;
	distance_tmp = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	//printf("horizonal_distance:%f\n", distance);
	//printf("tmp_x:%f, tmp_y:%f\n", tmp_x, tmp_y);
	return (distance_tmp);
}

void beam_calculation(t_cub3d *main, double angle)
{
	double distance_v;
	double distance_h;
	double distance;
	int x;
	int y;

	x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
	y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;

	distance_v = ray_vertical(main, angle, x, y);
	distance_h = ray_horizonal(main, angle, x, y);

	if(distance_v < distance_h)
		distance = distance_v;
	else
		distance = distance_h;
	printf("distance:%f\n", distance);
	//draw_ray(distance, x, y, angle, main);
}

void raycasting(t_cub3d *main)
{
	// double angle;

	// angle = -1 * MOVE_PERSPECTIVE / 2;

	// while (angle <= MOVE_PERSPECTIVE / 2)
	// {
		double angle = 0;
		beam_calculation(main, main->player->angle + angle);
	// 	angle += MOVE_BEAM_ANGLE_INCREASE_RATIO;
	// }
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->img_ray, 0, 0);
}

void put_ray(t_cub3d *main)
{
	main->img_ray = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	main->img_ray_adress = (int *)mlx_get_data_addr(main->img_ray, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	int k=0, i = 0;
	while (k != MINI_MAP_HEIGHT)
	{
		i = -1;
		while (++i != MINI_MAP_WIDTH)
			main->img_ray_adress[MINI_MAP_WIDTH * k + i] = rgb_to_hex(255,0,0,0);
		k++;
	}
	raycasting(main);
}
