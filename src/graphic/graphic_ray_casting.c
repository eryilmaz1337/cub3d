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

// int is_wall_tmp(double x, double y, t_cub3d *main)
// {
// 	int xX;
// 	int yY;

// 	if (x < 0 || x > main->map->map_max_line || y < 0 || y > main->map->map_lines_num)
// 		return (1);
//     xX = floor(x);
//     yY = floor(y);
// 	if (main->map->map[yY][xX] != '1')
// 		return (0);
//     return (1);
// }


// void draw_ray(double distance, int x, int y, double angle, t_cub3d *main)
// {
// 	double    ray_x;
//     double    ray_y;
//     double    dx;
//     double    dy;

//     ray_x = main->player->def_p_x;
//     ray_y = main->player->def_p_y;
//     dx = distance * fabs(cos(angle * (M_PI / 180))) * x;
//     dy = distance * fabs(sin(angle * (M_PI / 180))) * y;
//     dx /= distance;
//     dy /= distance;
//     while (1)
//     {
//         if (!is_wall_tmp(ray_x, ray_y, main))
//             main->mini_map->ray_addr[SCREEN_WIDTH * (int)floor(main->mini_map->map_img_size_y * ray_y) + (int)floor(main->mini_map->map_img_size_x * ray_x)] = rgb_to_hex(color_assignment(0,0,255,0));
//         else
//             break;
//         ray_x += dx / 100;
//         ray_y += dy / 100;
//     }
// }


// double ray_vertical(t_cub3d *main, double angle, int x, int y)
// {
// 	double vdy;
// 	double vdx;

// 	if (x == -1)
// 		vdx = main->player->def_p_x - floor(main->player->def_p_x);
// 	else
// 		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
// 	vdy = fabs(tan(angle * (M_PI / 180)) * vdx);

// 	double tmp_x = vdx*x;
// 	double tmp_y = vdy*y;

// 	if (!is_wall_tmp(main->player->def_p_x + vdx * x, main->player->def_p_y + vdy * y, main))
// 	{
// 		while (1)
// 		{
// 			vdx = vdx + 1;
// 			vdy = fabs(tan(angle * (M_PI / 180)) * vdx);
// 			if (!is_wall_tmp(main->player->def_p_x + vdx*x, main->player->def_p_y + vdy*y, main))
// 			{
// 				tmp_x = vdx*x;
// 				tmp_y = vdy*y;
// 			}
// 			else
// 				break ;
// 		}
// 	}
// 	double distance;
// 	distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
// 	//printf("vertical_distance:%f\n", distance);
// 	//printf("tmp_x:%f, tmp_y:%f\n", tmp_x, tmp_y);
// 	return (distance);
// }

// double ray_horizonal(t_cub3d *main, double angle, int x, int y)
// {
// 	double hdy;
// 	double hdx;

// 	if (y == -1)
// 		hdy = floor(main->player->def_p_y) - main->player->def_p_y;
// 	else
// 		hdy = ceil(main->player->def_p_y) - main->player->def_p_y;
// 	hdx = fabs(hdy / tan(angle * (M_PI / 180)));

// 	double tmp_y = hdy*y;
// 	double tmp_x = hdx*x;

// 	if (!is_wall_tmp(main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y, main))
// 	{
// 		while (1)
// 		{
// 			hdy = hdy + 1;
// 			hdx = fabs(hdy / tan(angle * (M_PI / 180)));
// 			if (!is_wall_tmp(main->player->def_p_x + hdx*x, main->player->def_p_y + hdy*y, main))
// 			{
// 				tmp_y = hdy*y;
// 				tmp_x = hdx*x;
// 			}
// 			else
// 				break;
// 		}
// 	}
// 	double distance;
// 	distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
// 	//printf("horizonal_distance:%f\n", distance);
// 	//printf("tmp_x:%f\n", hdy);
// 	return (distance);
// }

// void beam_calculation(t_cub3d *main, double angle)
// {
// 	double distance_v;
// 	double distance_h;
// 	double distance;
// 	int x;
// 	int y;

// 	x = ((cos(angle * (M_PI / 180)) > 0) * 2) - 1;
// 	y = ((sin(angle * (M_PI / 180)) > 0) * -2) + 1;

// 	distance_v = ray_vertical(main, angle, x, y);
// 	distance_h = ray_horizonal(main, angle, x, y);

// 	if(distance_v < distance_h)
// 		distance = distance_v;
// 	else
// 		distance = distance_h;
// 	printf("distance:%f\n", distance);
// 	//draw_ray(distance, x, y, angle, main);
// }

// void raycasting(t_cub3d *main)
// {
// 	double angle;
// 	angle = -1 * MOVE_PERSPECTIVE / 2;
// 	main->player->def_p_x = main->player->player_x / main->mini_map->map_img_size_x;
// 	main->player->def_p_y = main->player->player_y / main->mini_map->map_img_size_y;
// 	img_colors(main->mini_map->ray_addr, MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
// 	while (angle <= MOVE_PERSPECTIVE / 2)
// 	{
// 		double angle = 0;
// 		beam_calculation(main, main->player->angle + angle);
// 		angle += MOVE_BEAM_ANGLE_INCREASE_RATIO;
// 	}
// 	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
// }


// void	draw_3d(t_cub3d *main, double dis, int ray, int loc, double angle)
// {
// 	int	wh;
// 	int	draw_loc;
// 	int	i;
// 	int	color;

// 	i = 0;
// 	wh = (SCREEN_HEIGHT / dis) * 3;
// 	draw_loc = ((SCREEN_WIDTH * main->mini_map->screen_focus + (SCREEN_WIDTH)) - ray);
// 	color = 0x000000;
// 	if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc - 1] || angle == 0.0 || angle == 360.0)
// 		color = 0xff0000;
// 	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc + 1] || angle == 180.0)
// 		color = 0x00ff00;
// 	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc + SCREEN_WIDTH] || angle == 90.0)
// 		color = 0x0000ff;
// 	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc - SCREEN_WIDTH] || angle == 270.0)
// 		color = 0xffffff;
// 	while (i < wh)
// 	{
// 		main->game_img_adress[draw_loc - (SCREEN_WIDTH * i)] = color;
// 		main->game_img_adress[draw_loc + (SCREEN_WIDTH * i)] = color;
// 		i++;
// 	}
// }


// void ray(t_cub3d *main)
// {
// 	double ray_lenght;
// 	double angle_tmp;
// 	int status;
// 	int tmp_x;
// 	int tmp_y;
// 	int tmp_next_y;
// 	int tmp_next_x;
// 	int i=0;
// 	int k = 0;

// 	ray_lenght = 0;
// 	angle_tmp = main->player->angle - (ROT_ANGLE_USER / 2);
// 	status = 0;
// 	tmp_y = main->player->player_y + (main->mini_map->map_img_size_y / 2);
// 	tmp_x = main->player->player_x + (main->mini_map->map_img_size_x / 2);
// 	img_colors(main->mini_map->ray_addr, MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
// 	i = 0;
// 	k = 0;
// 	while (i < SCREEN_WIDTH)
// 	{
// 		ray_lenght = 0.1;
// 		status = 0;
// 		while (status == 0)
// 		{
// 			tmp_next_y = ((tmp_y - (int)(sin(angle_to_radyan(angle_tmp)) * (double)ray_lenght))) / main->mini_map->map_img_size_y;
// 			tmp_next_x = ((tmp_x + (int)(cos(angle_to_radyan(angle_tmp)) * (double)ray_lenght))) / main->mini_map->map_img_size_x;
// 			if (main->map->map[tmp_next_y][tmp_next_x] != '1')
// 				main->mini_map->ray_addr[(((tmp_y - (int)(sin(angle_to_radyan(angle_tmp)) * (double)ray_lenght))) * MINI_MAP_WIDTH) + ((tmp_x + (int) (cos(angle_to_radyan(angle_tmp)) * (double)ray_lenght)))] = rgb_to_hex(color_assignment(0, 0, 255, 0));
// 			else
// 			{
// 				draw_3d(main, ray_lenght, i,(((tmp_y - (int)(sin(angle_to_radyan(angle_tmp)) * (double)ray_lenght))) * MINI_MAP_WIDTH) + ((tmp_x + (int) (cos(angle_to_radyan(angle_tmp)) * (double)ray_lenght))), angle_tmp);
// 				status = 1;
// 			}
// 			ray_lenght++;
// 		}
// 		angle_tmp += ((double)ROT_ANGLE_USER / (double)SCREEN_WIDTH);
// 		i++;
// 	}
// 	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
// }
