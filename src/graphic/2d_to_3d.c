/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_to_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:17 by uercan            #+#    #+#             */
/*   Updated: 2023/01/12 18:05:23 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	put_to_3d(t_cub3d *main, double dis, int ray, int loc, double angle)
{
	//(void)main;
	int	wh;
	int	draw_loc;
	int i;
	int	color;

	i = 0;
	wh = (SCREEN_WIDTH / dis) * 2;
	draw_loc = ((SCREEN_WIDTH * main->mini_map->screen_focus + (SCREEN_WIDTH)) - ray);
	//color = 0xeeeeee * dis;//mid
	//color = 0x654321 * dis;//big
	//color = 0xfff000 * dis / 2;//small
	// if (0xffff00 * dis <= MAX_INT && dis > 5)
	// 	color = 0xffff00;
	// else
		color = 0xffff00;
	//printf("%d\n", ray);
	//write(1, ft_itoa(dis), ft_strlen(ft_itoa(dis)));
	//write (1, "\n", 1);
	//printf("dis:%d ray:%d loc:%d ang:%0.2f\n", dis, ray, loc, angle);
	(void)loc;
	(void)angle;
	while (i < wh)
	{
		main->game_img_adress[draw_loc - (SCREEN_WIDTH * i)] = color;
		main->game_img_adress[draw_loc + (SCREEN_WIDTH * i)] = color;
	// 	if (angle > 0 && angle < 180)
	// 	{
			
	// 	}
		i++;
	}
		//main->game_img_adress[draw_loc - (SCREEN_WIDTH * i++)] = mlx_get_data_addr(main->mlx, main->map->NO_texture_addr, 0, 0);
	
	
}