/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_v.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:09:02 by uercan            #+#    #+#             */
/*   Updated: 2023/02/13 14:03:33 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	if_check_v(t_cub3d *main, double vdy, double vdx)
{
	if ((int)(main->player->def_p_y + vdy) >= 0
			&& (int)(main->player->def_p_y + vdy) < main->map->map_lines_num
			&& (int)(main->player->def_p_x + vdx) >= 0 &&
			(int)(main->player->def_p_x + vdx) < main->map->map_max_line)
		return (0);
	return (1);
}

int	while_check_v(t_cub3d *main, double vdx, double vdy)
{
	if (main->player->def_p_x + vdx - 0.0001 >= 0
		&& main->player->def_p_x + vdx - 0.0001 <= main->map->map_max_line
		&& main->player->def_p_y + vdy >= 0
		&& main->player->def_p_y + vdy <= main->map->map_lines_num)
		return (0);
	return (1);
}

int	if_check_h(t_cub3d *main, double hdy, double hdx)
{
	if ((int)(main->player->def_p_y + hdy) >= 0 &&
		(int)(main->player->def_p_y + hdy) < main->map->map_lines_num &&
		(int)(main->player->def_p_x + hdx) >= 0 &&
		(int)(main->player->def_p_x + hdx) < main->map->map_max_line
		)
		return (0);
	return (1);
}

int	while_check_h(t_cub3d *main, double vdx, double vdy)
{
	if (main->player->def_p_x + vdx >= 0
		&& main->player->def_p_x + vdx <= main->map->map_max_line
		&& main->player->def_p_y + vdy - 0.0001 >= 0
		&& main->player->def_p_y + vdy - 0.0001 <= main->map->map_lines_num)
		return (0);
	return (1);
}
