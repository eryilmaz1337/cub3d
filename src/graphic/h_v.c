/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_v.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:09:02 by uercan            #+#    #+#             */
/*   Updated: 2023/02/11 18:34:24 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	if_check_v(t_cub3d *main, double y, double x, double angle)
{
	double	vdx;
	double	vdy;

	if (x == -1)
		vdx = main->player->def_p_x - floor(main->player->def_p_x);
	else
		vdx = ceil(main->player->def_p_x) - main->player->def_p_x;
	vdy = fabs(tan(angle_to_radyan(angle)) * vdx);
	if ((int)(main->player->def_p_y + vdy * y) >= 0
			&& (int)(main->player->def_p_y + vdy * y) < main->map->map_lines_num
			&& (int)(main->player->def_p_x + vdx * x) >= 0 &&
			(int)(main->player->def_p_x + vdx * x) < main->map->map_max_line)
		return (0);
	return (1);
}

int	if_check_h(t_cub3d *main, double y, double x, double angle)
{
	double	hdx;
	double	hdy;

	if (y == -1)
		hdy = main->player->def_p_y - floor(main->player->def_p_y);
	else
		hdy = ceil(main->player->def_p_y) - main->player->def_p_y;
	hdx = fabs(hdy / tan(angle_to_radyan(angle)));
	if ((int)(main->player->def_p_y + hdy * y) >= 0 &&
		(int)(main->player->def_p_y + hdy * y) < main->map->map_lines_num &&
		(int)(main->player->def_p_x + hdx * x) >= 0 &&
		(int)(main->player->def_p_x + hdx * x) < main->map->map_max_line
		)
		return (0);
	return (1);
}