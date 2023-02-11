/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:27:04 by uercan            #+#    #+#             */
/*   Updated: 2023/02/10 18:17:56 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_key_w(t_cub3d *main, double x, double y)
{
	if (main->player->key_w)
	{
		x += cos(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, x, main->player->player_y) == 0)
			main->player->player_x = x;
		y += -1 * sin(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, main->player->player_x, y) == 0)
			main->player->player_y = y;
	}
}

void	move_key_a(t_cub3d *main, double x, double y)
{
	if (main->player->key_a)
	{
		x += -1 * sin(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, x, main->player->player_y) == 0)
			main->player->player_x = x;
		y -= cos(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, main->player->player_x, y) == 0)
			main->player->player_y = y;
	}
}

void	move_key_s(t_cub3d *main, double x, double y)
{
	if (main->player->key_s)
	{
		x += -1 * cos(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, x, main->player->player_y) == 0)
			main->player->player_x = x;
		y += sin(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, main->player->player_x, y) == 0)
			main->player->player_y = y;
	}
}

void	move_key_d(t_cub3d *main, double x, double y)
{
	if (main->player->key_d)
	{
		x += sin(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, x, main->player->player_y) == 0)
			main->player->player_x = x;
		y += cos(angle_to_radyan(main->player->angle))
			* main->player->move_speed;
		if (is_wall_functions(main, main->player->player_x, y) == 0)
			main->player->player_y = y;
	}
}

void	key(t_cub3d *main)
{
	move_key_w(main, main->player->player_x, main->player->player_y);
	move_key_a(main, main->player->player_x, main->player->player_y);
	move_key_s(main, main->player->player_x, main->player->player_y);
	move_key_d(main, main->player->player_x, main->player->player_y);
}
