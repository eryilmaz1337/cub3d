/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_src.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 17:00:47 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void get_move_value(t_cub3d *main, int value,  int status_axis, int status)
{
	if(status_axis)
	{
		main->player->player_x += value * sin(angle_to_radyan(main->player->angle));
		if(status)
			main->player->player_y += cos(angle_to_radyan(main->player->angle));
		else
			main->player->player_y -= cos(angle_to_radyan(main->player->angle));
	}
	else
	{
		if(status)
		{
			main->player->player_x += cos(angle_to_radyan(main->player->angle));
			main->player->player_y += -1 * sin(angle_to_radyan(main->player->angle));
		}
		else
		{
			main->player->player_x += -1 * cos(angle_to_radyan(main->player->angle));
			main->player->player_y += sin(angle_to_radyan(main->player->angle));
		}
	}
}

int	move_loop(t_cub3d *main)
{
	//printf("%d %d", main->player->key_a, main->mini_map->dir_left);
	if (main->player->key_a)
		get_move_value(main, -1, 1, 0);
	if (main->player->key_d)
		get_move_value(main, 1, 1, 1);
	if (main->player->key_w)
		get_move_value(main, 0, 0, 1);
	if (main->player->key_s)
		get_move_value(main, 0, 0, 0);
	if (main->player->dir_left)
		main->player->angle += MOVE_ANGLE;
	if (main->player->dir_right)
		main->player->angle -= MOVE_ANGLE;
	game_mini_map_paint(main);
	//game_put_player(main);
	printf("x:%0.2f\ty:%0.2f\tAng:%0.2f\n", main->player->player_x, main->player->player_y, main->player->angle);
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

