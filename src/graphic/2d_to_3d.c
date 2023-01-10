/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_to_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:17 by uercan            #+#    #+#             */
/*   Updated: 2023/01/10 15:55:01 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	put_to_3d(t_cub3d *main, int dis, int ray)
{
	//(void)main;
	int	wh;
	int	draw_loc;
	int i;
	int	mid;

	i = 0;
	mid = SCREEN_HEIGHT / 2;
	wh = (SCREEN_WIDTH / dis) * 2;

	draw_loc = ((SCREEN_WIDTH * mid + (SCREEN_WIDTH)) - ray);
	//if (ray == 0)
	//	printf("dis:%d draw_loc:%d ray:%d\n", dis, draw_loc, ray);
	while (i < wh)
	{
		main->game_img_adress[draw_loc - (SCREEN_WIDTH * i)] = 0xffff00 * dis;
		main->game_img_adress[draw_loc + (SCREEN_WIDTH * i)] = 0xffff00 * dis;
		i++;
	}
		//main->game_img_adress[draw_loc - (SCREEN_WIDTH * i++)] = mlx_get_data_addr(main->mlx, main->map->NO_texture_addr, 0, 0);
	
	
}