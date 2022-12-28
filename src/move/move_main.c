/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 19:55:56 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

// void get_move_value(t_cub3d *main, int value,  int status_axis, int status)
// {
// 	if(status_axis)
// 	{
// 		main->player->player_x += value * sin(angle_to_radyan(main->player->angle));
// 		if(status)
// 			main->player->player_y += cos(angle_to_radyan(main->player->angle));
// 		else
// 			main->player->player_y -= cos(angle_to_radyan(main->player->angle));
// 	}
// 	else
// 	{
// 		if(status)
// 		{
// 			main->player->player_x += cos(angle_to_radyan(main->player->angle));
// 			main->player->player_y += -1 * sin(angle_to_radyan(main->player->angle));
// 		}
// 		else
// 		{
// 			main->player->player_x += -1 * cos(angle_to_radyan(main->player->angle));
// 			main->player->player_y += sin(angle_to_radyan(main->player->angle));
// 		}
// 	}
// }

// int	move_loop(t_cub3d *main)
// {
// 	//printf("%d %d", main->player->key_a, main->mini_map->dir_left);
// 	if (main->player->key_a)
// 		get_move_value(main, -1, 1, 0);
// 	if (main->player->key_d)
// 		get_move_value(main, 1, 1, 1);
// 	if (main->player->key_w)
// 		get_move_value(main, 0, 0, 1);
// 	if (main->player->key_s)
// 		get_move_value(main, 0, 0, 0);
// 	if (main->player->dir_left)
// 		main->player->angle += MOVE_ANGLE;
// 	if (main->player->dir_right)
// 		main->player->angle -= MOVE_ANGLE;
// 	game_mini_map_paint(main);
// 	//game_put_player(main);
// 	printf("x:%0.2f\ty:%0.2f\tAng:%0.2f\n", main->player->player_x, main->player->player_y, main->player->angle);
// 	return (0);
// }

int	is_wall(t_cub3d *main, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = (x + 2.0) / main->mini_map->map_img_size_x;
	new_y = (y + 2.0) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sol_üst\n");
		return (1);
	}
		new_x = ((x - 2.0) + main->mini_map->map_img_size_x) / main->mini_map->map_img_size_x;
		new_y = (y + 2.0) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sağ_üst\n");
		return (2);
	}
		new_x = (x + 2.0) / main->mini_map->map_img_size_x;
		new_y = ((y - 2.0) + main->mini_map->map_img_size_y) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sol_alt\n");
		return (3);
	}
		new_x = ((x - 2.0) + main->mini_map->map_img_size_x) / main->mini_map->map_img_size_x;
		new_y = ((y - 2.0) + main->mini_map->map_img_size_y) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sağ_alt\n");
		return (4);
	}
	return (0);
}


int	move_loop(t_cub3d *main)
{
	double	x;
	double	y;
	int		status;

	status = 0;
	x = main->player->player_x;
	y = main->player->player_y;
	if (main->player->key_w)
	{
		x += cos(angle_to_radyan(main->player->angle));
		y += -1 * sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y))
			status = 1;
		else
			printf("---_%d_--*\n", is_wall(main, x, y));
	}
	if (main->player->key_a)
	{
		x += -1 * sin(angle_to_radyan(main->player->angle));
		y -= cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y))
			status = 1;
	}
	if (main->player->key_s)
	{
		x += -1 * cos(angle_to_radyan(main->player->angle));
		y += sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y))
			status = 1;
	}
	if (main->player->key_d)
	{
		x += sin(angle_to_radyan(main->player->angle));
		y += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y))
			status = 1;
	}
	if (main->player->dir_left)
			main->player->angle += MOVE_ANGLE;
	if (main->player->dir_right)
		main->player->angle -= MOVE_ANGLE;
	if (status == 1)
	{
		main->player->player_x = x;
		main->player->player_y = y;
		status = 0;
	}
	game_mini_map_paint(main);
	game_put_player(main);
	printf("x:%0.2f\ty:%0.2f\tAng:%0.2f\n", main->player->player_x, main->player->player_y, main->player->angle);
	//printf("x:%d y:%d MX:%0.2f MY:%0.2f\n", x, y, main->player->player_x, main->player->player_y);
	return (0);
}

int	ft_key_press(int key_code, t_cub3d *main)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_A)
		main->player->key_a = true;
	if (key_code == KEY_S)
		main->player->key_s = true;
	if (key_code == KEY_D)
		main->player->key_d = true;
	if (key_code == KEY_W)
		main->player->key_w = true;
	if (key_code == KEY_RIGHT)
		main->player->dir_right = true;
	if (key_code == KEY_LEFT)
		main->player->dir_left = true;
	return (0);
}

int	ft_key_release(int key_code, t_cub3d *main)
{
	if (key_code == KEY_A)
		main->player->key_a = false;
	if (key_code == KEY_S)
		main->player->key_s = false;
	if (key_code == KEY_D)
		main->player->key_d = false;
	if (key_code == KEY_W)
		main->player->key_w = false;
	if (key_code == KEY_RIGHT)
		main->player->dir_right = false;
	if (key_code == KEY_LEFT)
		main->player->dir_left = false;
	return (0);
}

