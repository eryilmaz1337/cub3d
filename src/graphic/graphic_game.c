/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/06 19:15:06 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	create_ray_image(t_cub3d *main)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	main->mini_map->ray_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	main->mini_map->ray_addr = (int *)mlx_get_data_addr(main->mini_map->ray_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	while (k != SCREEN_HEIGHT)
	{
		i = -1;
		while (++i != SCREEN_WIDTH)
			main->mini_map->ray_addr[SCREEN_WIDTH * k + i] = rgb_to_hex(255,0,0,0);
		k++;
	}
}

void game_window(t_cub3d *main)
{
	int	a = SCREEN_WIDTH;
	int b = SCREEN_HEIGHT;
	main->mlx = mlx_init();
	if (!main->mlx)
		exit_free(main, MLX_ERROR_INIT);
	main->mlx_window = mlx_new_window(main->mlx, a, b, "CUB3D");
	if (!main->mlx_window)
		exit_free(main, MLX_ERROR_WINDOW);
	main->game_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!main->game_img)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	if (!main->mini_map_img)
		exit_free(main, MLX_ERROR_IMG);
	main->game_img_adress = (int *)mlx_get_data_addr(main->game_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->game_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img_adress = (int *)mlx_get_data_addr(main->mini_map_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->mini_map_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	create_ray_image(main);
}

void main_game_img_paint(t_cub3d *main)
{
	int i;
	int k;
	int sky;
	k = 0;
	i = 0;
	sky = SCREEN_HEIGHT / 2;
	while (k != SCREEN_HEIGHT)
	{
		i = -1;
		while (++i != SCREEN_WIDTH && k != sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->C_rgb_code;
		i = -1;
		while (++i != SCREEN_WIDTH && k >= sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->F_rgb_code;
		k++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->game_img, 0, 0);
}

/*
void	draw_ray(t_cub3d *main)
{
	int	new_x;
	int	new_y;
	int	i;
	int	k;
	int	per_pixel;
	int	ray_r;
	int	l;

	l = 0;
	ray_r = 10;
	per_pixel = 2;
	//i = (SCREEN_HEIGHT / 2) + (main->mini_map->map_img_size_y / 2);
	//k = (SCREEN_WIDTH / 2) + (main->mini_map->map_img_size_x / 2);
	i = main->player->player_y;
	k = main->player->player_x;
	new_x = (main->player->player_x - ((SCREEN_WIDTH / 2)));
	new_y = (main->player->player_y - ((SCREEN_HEIGHT / 2)));
	//printf("%d %d\n", new_x, new_y);
	printf("%d\n", (int)main->mini_map->ray_img);
	//SCREEN_WIDTH / MINI_MAP_WIDTH_RATION
	//SCREEN_HEIGHT / MINI_MAP_HEIGHT_RATION
	while (l++ < 100)
	{
		while (i >= SCREEN_HEIGHT / 4)
		{
			// k -= ray_r;
			// while (++k <= ray_r)
				main->mini_map->ray_addr[(i * SCREEN_WIDTH) + k] = 0xff00ff;
				main->mini_map->ray_addr[(i * SCREEN_WIDTH) + (SCREEN_WIDTH - k + main->mini_map->map_img_size_x)] = 0xff00ff;
				//if((i / main->mini_map->map_img_size_x) < main->map->map_lines_num && (k / main->mini_map->map_img_size_y) < main->map->map_max_line)
					//printf("x:%d y:%d\n", k, i);
			// ray_r += per_pixel;
			i -= per_pixel;
		}
		i = (SCREEN_HEIGHT / 2) + (main->mini_map->map_img_size_y / 2) - (l * 5);
		k += per_pixel;
	}
	// for (int p = 0; p <1000; p++)
	// {
	// 	main->mini_map->ray_addr[p] = 0x00ff00;
	// }
	
	// i = 0;
	// k = 0;
	// while (i != SCREEN_HEIGHT)
	// {
	// 	k = -1;
	// 	while (++k != SCREEN_WIDTH)
	// 		main->mini_map->ray_addr[SCREEN_WIDTH * i + k] = rgb_to_hex(100,0,255,0);
	// 	i++;
	// }

	//mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, new_x, new_y);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
}
*/

void	draw_ray(t_cub3d *main, int i, int k)
{
	int	new_x;
	int	new_y;
	int	l2;
	int	l;

	int angle = main->player->angle;
	int status = 0;
	int i2;
	int k2;
	double angle2;

	angle2 = (double)angle;
	l = 0;
	l2 = 1;
	while (k != MINI_MAP_HEIGHT)
	{
		i = -1;
		while (++i != MINI_MAP_WIDTH)
			main->mini_map->ray_addr[MINI_MAP_WIDTH * k + i] = rgb_to_hex(255,0,0,0);//1234567890
		k++;
	}
	i = main->player->player_y + (main->mini_map->map_img_size_y / 2);
	k = main->player->player_x + (main->mini_map->map_img_size_x / 2);
	new_x = (main->player->player_x - ((SCREEN_WIDTH / 2)));
	new_y = (main->player->player_y - ((SCREEN_HEIGHT / 2)));

	while (status == 0)
	{
		//if (main->map->map[((i - ((int)sin(angle_to_radyan(main->player->angle)) * l))) / main->mini_map->map_img_size_y][((k + ((int)cos(angle_to_radyan(main->player->angle)) * l))) / main->mini_map->map_img_size_x] != '1')
		l2 = 0;
		angle = main->player->angle;
		while (l2++ < 45 && status == 0)
		{
			i2 = ((i - (int)(sin(angle_to_radyan(angle)) * (double)l))) / main->mini_map->map_img_size_y;
			k2 = ((k + (int)(cos(angle_to_radyan(angle)) * (double)l))) / main->mini_map->map_img_size_x;
			if (i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
			{
				if (main->map->map[i2][k2] != '1' && i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
				{
					main->mini_map->ray_addr[(((i - (int)(sin(angle_to_radyan(angle)) * (double)l))) * SCREEN_WIDTH) + ((k + (int)(cos(angle_to_radyan(angle)) * (double)l)))] = 0x00ff00;
					//DONT! main->mini_map->ray_addr[(int)((((double)i - (sin(angle_to_radyan(main->player->angle)) * l))) * SCREEN_WIDTH) + (int)((double)k + (cos(angle_to_radyan(main->player->angle)) * l))] = 0x00ff00;
					//printf("i:%d k:%d\n", (int)((((double)i - (sin(angle_to_radyan(main->player->angle)) * l))) * SCREEN_WIDTH), (int)((double)k + (cos(angle_to_radyan(main->player->angle)) * l)));
				}
				else
				{
					printf("1/l:%d ANG:%d %d %d\n", l2, angle, i2, k2);
					status = 1;
				}
			}
			i2 = ((i - (int)(sin(angle_to_radyan(angle - 45)) * (double)l))) / main->mini_map->map_img_size_y;
			k2 = ((k + (int)(cos(angle_to_radyan(angle - 45)) * (double)l))) / main->mini_map->map_img_size_x;
			if (i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
			{
				if (main->map->map[i2][k2] != '1')
				{
					main->mini_map->ray_addr[(((i - (int)(sin(angle_to_radyan(angle - 45)) * (double)l))) * SCREEN_WIDTH) + ((k + (int)(cos(angle_to_radyan(angle - 45)) * (double)l)))] = 0x00ff00;
					//DONT! main->mini_map->ray_addr[(int)((((double)i - (sin(angle_to_radyan(main->player->angle)) * l))) * SCREEN_WIDTH) + (int)((double)k + (cos(angle_to_radyan(main->player->angle)) * l))] = 0x00ff00;
					//printf("i:%d k:%d\n", (int)((((double)i - (sin(angle_to_radyan(main->player->angle)) * l))) * SCREEN_WIDTH), (int)((double)k + (cos(angle_to_radyan(main->player->angle)) * l)));
				}
				else
				{
					printf("2/l:%d ANG:%d %d %d\n", l2, angle, i2, k2);
					status = 1;
				}
			}
			//------------------
			angle2 = (double)angle;
			angle2 -= 0.5;
			i2 = ((i - (int)(sin(angle_to_radyan(angle2)) * (double)l))) / main->mini_map->map_img_size_y;
			k2 = ((k + (int)(cos(angle_to_radyan(angle2)) * (double)l))) / main->mini_map->map_img_size_x;
			if (i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
			{
				if (main->map->map[i2][k2] != '1' && i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
					main->mini_map->ray_addr[(((i - (int)(sin(angle_to_radyan(angle2)) * (double)l))) * SCREEN_WIDTH) + ((k + (int)(cos(angle_to_radyan(angle2)) * (double)l)))] = 0x0f0ff0;
				else
				{
					printf("3/l:%d ANG:%d %d %d\n", l2, angle, i2, k2);
					status = 1;
				}
			}
			//------------------
			//------------------
			angle2 = (double)angle;
			angle2 -= 44.5;
			i2 = ((i - (int)(sin(angle_to_radyan(angle2)) * (double)l))) / main->mini_map->map_img_size_y;
			k2 = ((k + (int)(cos(angle_to_radyan(angle2)) * (double)l))) / main->mini_map->map_img_size_x;
			if (i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
			{
				if (main->map->map[i2][k2] != '1' && i2 < main->map->map_lines_num && k2 < main->map->map_max_line)
					main->mini_map->ray_addr[(((i - (int)(sin(angle_to_radyan(angle2)) * (double)l))) * SCREEN_WIDTH) + ((k + (int)(cos(angle_to_radyan(angle2)) * (double)l)))] = 0xff0fff;
				else
				{
					printf("4/l:%d ANG:%d %d %d\n", l2, angle, i2, k2);
					status = 1;
				}
			}
			//------------------
			angle += 1;
		}
		l++;
	}


	
	//printf("(*x:%d *y:%d)(#x:%d #y:%d)\n", k, i, (k / main->mini_map->map_img_size_x), (i / main->mini_map->map_img_size_y));
	// for (int p = 0; p <1000; p++)
	// {
	// 	main->mini_map->ray_addr[p] = 0x00ff00;
	// }
	
	// i = 0;
	// k = 0;
	// while (i != SCREEN_HEIGHT)
	// {
	// 	k = -1;
	// 	while (++k != SCREEN_WIDTH)
	// 		main->mini_map->ray_addr[SCREEN_WIDTH * i + k] = rgb_to_hex(100,0,255,0);
	// 	i++;
	// }

	//mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, new_x, new_y);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
}