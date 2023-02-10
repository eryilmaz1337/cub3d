/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/10 19:17:59 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_x_value(t_cub3d *main, int status, double x)
{
	double	val;

	val = x + (main->mini_map->map_img_size_x / 2);
	val += (main->mini_map->map_img_size_x / 5) * status;
	val /= main->mini_map->map_img_size_x;
	return (val);
}

double	get_y_value(t_cub3d *main, int status, double y)
{
	double	val;

	val = y + (main->mini_map->map_img_size_y / 2);
	val += (main->mini_map->map_img_size_y / 5) * status;
	val /= main->mini_map->map_img_size_y;
	return (val);
}

static int	is_door_c(t_cub3d *main, double x, double y, char c)
{
	double new_x;
	double new_y;

	new_x = get_x_value(main, 1, x);
	new_y = get_y_value(main, -1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == 'A' || c == 'K')
		return (c);
	new_x = get_x_value(main, -1, x);
	new_y = get_y_value(main, 1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == 'A' || c == 'K')
		return (c);
	new_x = get_x_value(main, 1, x);
	new_y = get_y_value(main, 1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == 'A' || c == 'K')
		return (c);
	return (0);
}

char	is_door(t_cub3d *main, double x, double y)
{
	double	new_x;
	double	new_y;
	char	c;

	new_x = get_x_value(main, -1, x);
	new_y = get_y_value(main, -1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == 'A' || c == 'K')
		return (c);
	return (is_door_c(main, x, y, c));
}

static int	is_wall_c(t_cub3d *main, double x, double y, char c)
{
	double new_x;
	double new_y;

	new_x = get_x_value(main, 1, x);
	new_y = get_y_value(main, -1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == '1' || c == 'K')
		return (1);
	new_x = get_x_value(main, -1, x);
	new_y = get_y_value(main, 1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == '1' || c == 'K')
		return (2);
	new_x = get_x_value(main, 1, x);
	new_y = get_y_value(main, 1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == '1' || c == 'K')
		return (1);
	return (0);
}

int	is_wall(t_cub3d *main, double x, double y)
{
	double	new_x;
	double	new_y;
	char	c;

	new_x = (x + (main->mini_map->map_img_size_x / 2)) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2)) / main->mini_map->map_img_size_y;
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == 'K')
		return (2);
	new_x = get_x_value(main, -1, x);
	new_y = get_y_value(main, -1, y);
	c = main->map->map[(int)new_y][(int)new_x];
	if (c == '1' || c == 'K')
		return (1);
	return (is_wall_c(main, x, y, c));
}
