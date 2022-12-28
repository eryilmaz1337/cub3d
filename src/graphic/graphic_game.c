/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:30 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 20:52:50 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
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
