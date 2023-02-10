/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:27:04 by uercan            #+#    #+#             */
/*   Updated: 2023/02/09 16:49:39 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_key_w(t_cub3d *main, double x, double y)
{
	int	hit_x;
	int	hit_y;

	hit_x = 0;
	hit_y = 0;
	if (main->player->key_w)
	{
		x += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, main->player->player_y, 0.0, 0.0))
			hit_x = 1;
		y += -1 * sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y, 0.0, 0.0))
			hit_y = 1;
	}
	if (hit_x == 1)
	{
		main->player->player_x = x;
		hit_x = 0;
	}
	if (hit_y == 1)
	{
		main->player->player_y = y;
		hit_y = 0;
	}
}

void	move_key_a(t_cub3d *main, double x, double y)
{
	int	hit_x;
	int	hit_y;

	hit_x = 0;
	hit_y = 0;
	if (main->player->key_a)
	{
		x += -1 * sin(angle_to_radyan(main->player->angle));
		
		if (!is_wall(main, x, main->player->player_y, 0.0, 0.0))
			hit_x = 1;
		y -= cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y, 0.0, 0.0))
			hit_y = 1;
	}
	if (hit_x == 1)
	{
		main->player->player_x = x;
		hit_x = 0;
	}
	if (hit_y == 1)
	{
		main->player->player_y = y;
		hit_y = 0;
	}
}

void	move_key_s(t_cub3d *main, double x, double y)
{
	int	hit_x;
	int	hit_y;

	hit_x = 0;
	hit_y = 0;
	if (main->player->key_s)
	{
		x += -1 * cos(angle_to_radyan(main->player->angle));
		
		if (!is_wall(main, x, main->player->player_y, 0.0, 0.0))
			hit_x = 1;
		y += sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y, 0.0, 0.0))
			hit_y = 1;
	}
	if (hit_x == 1)
	{
		main->player->player_x = x;
		hit_x = 0;
	}
	if (hit_y == 1)
	{
		main->player->player_y = y;
		hit_y = 0;
	}
}

void	move_key_d(t_cub3d *main, double x, double y)
{
	int	hit_x;
	int	hit_y;

	hit_x = 0;
	hit_y = 0;
	if (main->player->key_d)
	{
		x += sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, main->player->player_y, 0.0, 0.0))
			hit_x = 1;
		y += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y, 0.0, 0.0))
			hit_y = 1;
	}
	if (hit_x == 1)
	{
		main->player->player_x = x;
		hit_x = 0;
	}
	if (hit_y == 1)
	{
		main->player->player_y = y;
		hit_y = 0;
	}
}

void	keys(t_cub3d *main)
{
	move_key_w(main, main->player->player_x, main->player->player_y);
	move_key_a(main, main->player->player_x, main->player->player_y);
	move_key_s(main, main->player->player_x, main->player->player_y);
	move_key_d(main, main->player->player_x, main->player->player_y);
}
