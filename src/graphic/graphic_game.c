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
	main->mini_map->ray_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	main->mini_map->ray_addr = (int *)mlx_get_data_addr(main->mini_map->ray_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	while (k != MINI_MAP_HEIGHT)
	{
		i = -1;
		while (++i != MINI_MAP_WIDTH)
			main->mini_map->ray_addr[MINI_MAP_WIDTH * k + i] = rgb_to_hex(255,0,0,0);
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

void	draw_ray(t_cub3d *main, int i, int k)
{
	double ray_run_distance;
	int angle_tmp;
	int status;
	int tmp_x;
	int tmp_y;
	int tmp_next_y;
	int tmp_next_x;

	ray_run_distance = 0;
	angle_tmp = main->player->angle;
	status = 0;
	tmp_y = main->player->player_y + (main->mini_map->map_img_size_y / 2);
	tmp_x = main->player->player_x + (main->mini_map->map_img_size_x / 2);
	while (k != MINI_MAP_HEIGHT)
	{
		i = -1;
		while (++i != MINI_MAP_WIDTH)
			main->mini_map->ray_addr[MINI_MAP_WIDTH * k + i] = rgb_to_hex(255, 0, 0, 0);
		k++;
	}
	i = 0;
	k = 0;
	while (i <= ROT_ANGLE_USER)
	{
		ray_run_distance = 0;
		status = 0;
		while (status == 0)
		{
			tmp_next_y = ((tmp_y - (int)(sin(angle_to_radyan(angle_tmp)) * (double)ray_run_distance))) / main->mini_map->map_img_size_y;
			tmp_next_x = ((tmp_x + (int)(cos(angle_to_radyan(angle_tmp)) * (double)ray_run_distance))) / main->mini_map->map_img_size_x;
			if (main->map->map[tmp_next_y][tmp_next_x] != '1')
				main->mini_map->ray_addr[(((tmp_y - (int)(sin(angle_to_radyan(angle_tmp)) * (double)ray_run_distance))) * MINI_MAP_WIDTH) + ((tmp_x + (int)(cos(angle_to_radyan(angle_tmp)) * (double)ray_run_distance)))] = 0x00ff00;
			else
				status = 1;
			//printf("%d\n",tmp_next_x);
			//printf("%d\n",tmp_next_y);
			ray_run_distance++;
		}
		//printf("%d %d\n", tmp_next_x, tmp_next_y);
		angle_tmp++;
		i++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map->ray_img, 0, 0);
}
