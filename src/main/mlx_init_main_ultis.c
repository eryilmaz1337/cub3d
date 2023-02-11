/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_main_ultis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:45:59 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/11 14:46:00 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_variable_init_value(t_cub3d *main)
{
	main->player->dir_down = false;
	main->player->dir_up = false;
	main->player->dir_left = false;
	main->player->dir_right = false;
	main->player->key_a = false;
	main->player->key_s = false;
	main->player->key_d = false;
	main->player->key_w = false;
	main->player->key_e = false;
	main->player->key_shift = false;
	main->player->p_last_x = main->player->player_x;
	main->player->p_last_y = main->player->player_y;
	main->mini_map->screen_focus = SCREEN_HEIGHT / 2;
	main->mini_map->map_img_size_y = MINI_MAP_HEIGHT / main->map->map_lines_num;
	main->mini_map->map_img_size_x = MINI_MAP_WIDTH / main->map->map_max_line;
}

static void	error_chack_img_addr(t_cub3d *main)
{
	if (!main->game_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map->ray_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->player->player_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->NO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->SO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->WE_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->EA_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->door_img)
		exit_free(main, MLX_ERROR_IMG);
}

static void	error_chack_img(t_cub3d *main)
{
	if (!main->game_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map->ray_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->player->player_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->NO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->SO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->WE_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->EA_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->door_img)
		exit_free(main, MLX_ERROR_IMG);
}

void	mlx_img_init(t_cub3d *main)
{
	main->game_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	main->mini_map_img = mlx_new_image(main->mlx,
			MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	main->mini_map->ray_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH,
			MINI_MAP_HEIGHT);
	main->player->player_img = mlx_new_image(main->mlx, main->mini_map
			->map_img_size_x, main->mini_map->map_img_size_y);
	main->map->NO_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->NO_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->SO_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->SO_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->WE_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->WE_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->EA_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->EA_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->door_img = mlx_xpm_file_to_image(main->mlx,
			"./texture/wood.xpm", &main->tmp_img_x, &main->tmp_img_y);
	error_chack_img(main);
}

void	mlx_img_addr_init(t_cub3d *main)
{
	main->game_img_adress = (int *)mlx_get_data_addr(main->game_img,
			&main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	main->mini_map_img_adress = (int *)mlx_get_data_addr(main->mini_map_img,
			&main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	main->mini_map->ray_addr = (int *)mlx_get_data_addr(main->mini_map->ray_img,
			&main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	main->player->player_addr = (int *)mlx_get_data_addr(main->player
			->player_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	main->map->NO_texture_addr = (int *)mlx_get_data_addr(main->map
			->NO_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->SO_texture_addr = (int *)mlx_get_data_addr(main->map
			->SO_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->WE_texture_addr = (int *)mlx_get_data_addr(main->map
			->WE_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->EA_texture_addr = (int *)mlx_get_data_addr(main->map
			->EA_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->door_addr = (int *)mlx_get_data_addr(main->map
			->door_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	error_chack_img_addr(main);
}
