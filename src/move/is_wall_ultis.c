/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall_ultis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:18:25 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/11 14:18:25 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	is_wall_functions(t_cub3d *main, double x, double y)
{
	double	new_x;
	double	new_y;
	char	c;

	new_x = (x + (main->mini_map->map_img_size_x / 2))
		/ main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2))
		/ main->mini_map->map_img_size_y;
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
