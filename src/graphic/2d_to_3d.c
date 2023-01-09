/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_to_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:17 by uercan            #+#    #+#             */
/*   Updated: 2023/01/09 17:57:45 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	put_to_3d(t_cub3d *main, int dis, int ray)
{
	(void)main;
	int	wh;
	int	draw_loc;

	draw_loc = ((SCREEN_WIDTH * (SCREEN_HEIGHT / 2) + (SCREEN_WIDTH - 1)) - ray);
	wh = SCREEN_HEIGHT / dis;
	//printf("dis:%d draw_loc:%d ray:%d\n", dis, draw_loc, ray);
	int x = dis;
	int y = wh;
	//y = draw_loc;
		//main->game_img_adress[draw_loc] = 0xffff00;

	int i;
	int k;
	
	i = -1;
	while (++i < wh)
	{
		k = -1;
		while (++k < wh)
		{
			main->game_img_adress[] =  0xffff00;
		}
	}
}