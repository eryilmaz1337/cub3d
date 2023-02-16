/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_main_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:45:59 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 18:02:18 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

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
	main->mini_map->map_img_size_y = \
	main->mh / main->map->map_lines_num;
	main->mini_map->map_img_size_x = \
	main->mw / main->map->map_max_line;
}

static void	error_chack_img_addr(t_cub3d *main)
{
	if (!main->game_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->mini_map->ray_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->player->player_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->no_texture_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->so_texture_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->we_texture_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->ea_texture_addr)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->door_addr)
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
	if (!main->map->no_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->so_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->we_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->ea_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	if (!main->map->door_img)
		exit_free(main, MLX_ERROR_IMG);
}

void	mlx_img_init(t_cub3d *main)
{
	main->game_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	main->mini_map_img = mlx_new_image(main->mlx,
			main->mw, main->mh);
	main->mini_map->ray_img = mlx_new_image(main->mlx, main->mw,
			main->mh);
	main->player->player_img = mlx_new_image(main->mlx, main->mini_map
			->map_img_size_x, main->mini_map->map_img_size_y);
	main->map->no_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->no_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->so_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->so_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->we_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->we_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	main->map->ea_texture_img = mlx_xpm_file_to_image(main->mlx,
			main->map->ea_texture_path, &main->tmp_img_x, &main->tmp_img_y);
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
	main->map->no_texture_addr = (int *)mlx_get_data_addr(main->map
			->no_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->so_texture_addr = (int *)mlx_get_data_addr(main->map
			->so_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->we_texture_addr = (int *)mlx_get_data_addr(main->map
			->we_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->ea_texture_addr = (int *)mlx_get_data_addr(main->map
			->ea_texture_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	main->map->door_addr = (int *)mlx_get_data_addr(main->map
			->door_img, &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	error_chack_img_addr(main);
}
