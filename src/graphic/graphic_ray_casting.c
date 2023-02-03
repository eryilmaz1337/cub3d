/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:30:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/17 12:30:50 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_wall_tmp(double x, double y, t_cub3d *main)
{
	int xX;
	int yY;

	if (x < 0 || x > main->map->map_max_line || y < 0 || y > main->map->map_lines_num)
		return (1);
    xX = floor(x);
    yY = floor(y);
	if (xX < 0 || xX > main->map->map_max_line || yY < 0 || yY > main->map->map_lines_num)
		return (1);
	if (main->map->map[yY][xX] != '1')
		return (0);
    return (1);
}


void	draw_xpm_to_wall(t_cub3d *main, int location, int oran, int * xpm)
{
	int	i = -1;
	int find_pixel = 0;
	if (main->ray.hit_h == true)
		find_pixel = ((main->ray.pos_x - floor(main->ray.pos_x)) * 64); // resimdeki pixel sütun konumunu bulur.
	else if (main->ray.hit_v == true)
		find_pixel = ((main->ray.pos_y - floor(main->ray.pos_y)) * 64); // resimdeki pixel sütun konumunu bulur.
	int img_loc = (64 * (64 / 2)) + find_pixel;
	int color;
	if (oran >= 4000)
		oran = 4000;
	while (++i < oran)
	{
		color = xpm[img_loc - 64 * (int)((double)i * ((double)64 / (double)(oran * 2)))];//xpm.img.addr[img_loc - (xpm.width * ((i / (WINDOW_H / main->xpm[0].height)) % xpm.height))];
		if ((location - (SCREEN_WIDTH * i)) >= 0 && color >= 0) //yukarı
			main->game_img_adress[(location - (SCREEN_WIDTH * i))] = color;
		color = xpm[img_loc + 64 * (int)((double)i * ((double)64 / (double)(oran * 2)))];//xpm.img.addr[img_loc + (xpm.width * ((i / (WINDOW_H / main->xpm[0].height)) % xpm.height))];
		if ((SCREEN_HEIGHT * SCREEN_WIDTH) >= (location + (SCREEN_WIDTH * i)) && color >= 0) // aşağı
			main->game_img_adress[(location + (SCREEN_WIDTH * i))] = color;
	}
}

void draw_3d(t_cub3d *main, double distance, int ray_number)
{
	int loc;
	int oran;
	distance = distance * main->mini_map->map_img_size_x * ((double)SCREEN_HEIGHT / (double)SCREEN_WIDTH);
	loc = (SCREEN_WIDTH * main->mini_map->screen_focus) - ray_number;// 180000. pixel
	oran = (((double)SCREEN_HEIGHT / 2.0) / distance) * 16.0;

	if (main->ray.hit_h == true && main->ray.dir_y == -1)// kuzey
		draw_xpm_to_wall(main, loc, oran, main->map->NO_texture_addr);
	else if (main->ray.hit_h == true && main->ray.dir_y == 1)// guney
		draw_xpm_to_wall(main, loc, oran, main->map->SO_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == 1)// dogu
		draw_xpm_to_wall(main, loc, oran, main->map->EA_texture_addr);
	else if (main->ray.hit_v == true && main->ray.dir_x == -1)// bati
		draw_xpm_to_wall(main, loc, oran, main->map->WE_texture_addr);
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
        if (!is_wall_tmp(ray_x, ray_y, main))
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
	main->player->def_p_y = (main->player->player_y + (main->mini_map->map_img_size_x / 2)) / main->mini_map->map_img_size_y;
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
