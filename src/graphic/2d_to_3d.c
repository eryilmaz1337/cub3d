/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_to_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:17 by uercan            #+#    #+#             */
/*   Updated: 2023/01/13 07:55:46 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	put_to_3d(t_cub3d *main, double dis, int ray, int loc, double angle)
{
	//(void)main;
	int	wh;
	int	draw_loc;
	int	i;
	int	direction;
	i = 0;
	wh = (SCREEN_HEIGHT / dis) * 3;
	draw_loc = ((SCREEN_WIDTH * main->mini_map->screen_focus + (SCREEN_WIDTH)) - ray);

	int	pic_loc;
	int	j;

	j = 0;
	while (ray > 64)
		ray -= 64;
	pic_loc = ((64 * 32) - ray);
	//oran = 1 + (wh * 2);
	//color = 0xeeeeee * dis;//mid
	// color = 0x654321 * dis;//big
	//color = 0xfff000 * dis / 2;//small
	
	// if (0xffff00 * dis <= MAX_INT && dis > 5)
	// 	color = 0xffff00 * dis;
	// else
	 //	color = 0x000000;
	//printf("%d\n", ray);
	//write(1, ft_itoa(dis), ft_strlen(ft_itoa(dis)));
	//write (1, "\n", 1);
	//printf("dis:%d ray:%d loc:%d ang:%0.2f\n", dis, ray, loc, angle);
	//(void)angle;
	//printf("!%d ?%d\n", main->mini_map_img_adress[loc], main->mini_map_img_adress[loc - 1]);

	// NO	loc != loc - SCREEN_WIDTH	270
	// SO	loc != loc + SCREEN_WIDTH	90
	// EA	loc != loc +1				180
	// WE	loc != loc -1				0-360

	// if (angle == 0 || angle == 360)
	// 	color = 0xff0000;
	// else if (angle == 90)
	// 	color = 0xffff00;
	// else if (angle == 180)
	// 	color = 0xffffff;
	// else if (angle == 270)
	// 	color = 0x0000ff;


	int *images[4];

	images[0] = main->map->WE_texture_addr;
	images[1] = main->map->EA_texture_addr;
	images[2] = main->map->SO_texture_addr;
	images[3] = main->map->NO_texture_addr;

	
	if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc - 1] || angle == 0.0 || angle == 360.0)//W
		direction = 0;//color = 0xff0000;
	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc + 1] || angle == 180.0)//E
		direction = 1;//color = 0x00ff00;
	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc + SCREEN_WIDTH] || angle == 90.0)//S
		direction = 2;//color = 0x0000ff;
	else if (main->mini_map_img_adress[loc] != main->mini_map_img_adress[loc - SCREEN_WIDTH] || angle == 270.0)//N
		direction = 3;//color = 0xffffff;
	else
		direction = 4;
	while (i < wh)
	{
		// if (angle < 90)
		// {
		// 	if (main->mini_map_img_adress[(SCREEN_WIDTH * y2) + x2])
		// }
		if (direction == 4)
			break;
		main->game_img_adress[draw_loc - (SCREEN_WIDTH * i)] = images[direction][pic_loc - (i * 64)];//(int)&color * M_PI / color;
		main->game_img_adress[draw_loc + (SCREEN_WIDTH * i)] = images[direction][pic_loc - (i * 64)];
	// 	if (angle > 0 && angle < 180)
	// 	{
			
	// 	}
		i++;
	}
		//main->game_img_adress[draw_loc - (SCREEN_WIDTH * i++)] = mlx_get_data_addr(main->mlx, main->map->NO_texture_addr, 0, 0);
	
	
}