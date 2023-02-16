/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:28:49 by uercan            #+#    #+#             */
/*   Updated: 2023/02/13 14:21:44 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	set_last_hit_v(t_cub3d *main, double dx, double dy)
{
	main->ray.lh_y = main->map->map[(int)(main->player->def_p_y + dy)]
	[(int)(main->player->def_p_x + dx)];
	door_control(main, main->player->def_p_x + dx, main->player->def_p_y + dy);
}

void	set_last_hit_h(t_cub3d *main, double dx, double dy)
{
	main->ray.lh_x = main->map->map[(int)(main->player->def_p_y + dy)]
	[(int)(main->player->def_p_x + dx)];
	door_control(main, main->player->def_p_x + dx, main->player->def_p_y + dy);
}
