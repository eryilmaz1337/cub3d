/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:19:17 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/16 12:19:18 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void loop_window_and_game(t_cub3d *main)
{
	main->player->dir_down = false;
	mlx_mouse_move(main->mlx_window, MOVE_MOUSE_CENTER, MOVE_MOUSE_CENTER);
	put_backscreen(main);
	map_paint(main);
	// mlx_mouse_hide();
	mlx_hook(main->mlx_window, 2, 1L<<0, &ft_key_press, main);
	mlx_hook(main->mlx_window, 3, 1L<<1, &ft_key_release, main);
	// mlx_hook(main->mlx_window, 6, 0L, &mouse_cursor, main);
	mlx_hook(main->mlx_window, 17, (0L), ft_close, main);
	mlx_loop_hook(main->mlx, move_loop, main);
	mlx_loop(main->mlx);
}

void mlx_img_init(t_cub3d *main)
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

	printf("%d ", main->mini_map->map_img_size_y);
	printf("%d\n", main->mini_map->map_img_size_x);
	main->game_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!main->game_img)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	if (!main->mini_map_img)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map->ray_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	if (!main->mini_map->ray_img)
		exit_free(main, MLX_ERROR_IMG);
	main->player->player_img = mlx_new_image(main->mlx, main->mini_map->map_img_size_y, main->mini_map->map_img_size_x);
	if (!main->player->player_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->NO_texture_img = mlx_xpm_file_to_image(main->mlx, main->map->NO_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	if(!main->map->NO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->SO_texture_img = mlx_xpm_file_to_image(main->mlx, main->map->SO_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	if(!main->map->SO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->WE_texture_img = mlx_xpm_file_to_image(main->mlx, main->map->WE_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	if(!main->map->WE_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->EA_texture_img = mlx_xpm_file_to_image(main->mlx, main->map->EA_texture_path, &main->tmp_img_x, &main->tmp_img_y);
	if(!main->map->EA_texture_img)
		exit_free(main, MLX_ERROR_IMG);
}

void mlx_img_addr_init(t_cub3d *main)
{
	main->game_img_adress = (int *)mlx_get_data_addr(main->game_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->game_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img_adress = (int *)mlx_get_data_addr(main->mini_map_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->mini_map_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map->ray_addr = (int *)mlx_get_data_addr(main->mini_map->ray_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->mini_map->ray_addr)
		exit_free(main, MLX_ERROR_IMG);
	main->player->player_addr = (int *)mlx_get_data_addr(main->player->player_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if(!main->player->player_addr)
		exit_free(main, MLX_ERROR_IMG);
	main->map->NO_texture_addr = (int *)mlx_get_data_addr(main->map->NO_texture_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if(!main->map->NO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->SO_texture_addr = (int *)mlx_get_data_addr(main->map->SO_texture_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if(!main->map->SO_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->WE_texture_addr = (int *)mlx_get_data_addr(main->map->WE_texture_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if(!main->map->WE_texture_img)
		exit_free(main, MLX_ERROR_IMG);
	main->map->EA_texture_addr = (int *)mlx_get_data_addr(main->map->EA_texture_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if(!main->map->EA_texture_img)
		exit_free(main, MLX_ERROR_IMG);
}

unsigned long	rgb_to_hex_1(int transparent ,int r, int g, int b)//0x_00_00_ff
{
	return ((transparent << 24)+(r << 16) + (g << 8) + (b));
}

void mlx_inits(t_cub3d *main)
{
	main->mini_map->screen_focus = SCREEN_HEIGHT / 2;
	main->mini_map->map_img_size_y = MINI_MAP_HEIGHT / main->map->map_lines_num;
	main->mini_map->map_img_size_x = MINI_MAP_WIDTH / main->map->map_max_line;
	main->mlx = mlx_init();
	if (!main->mlx)
		exit_free(main, MLX_ERROR_INIT);
	main->mlx_window = mlx_new_window(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	if (!main->mlx_window)
		exit_free(main, MLX_ERROR_WINDOW);
	mlx_img_init(main);
	mlx_img_addr_init(main);
	img_colors(main->mini_map_img_adress, MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
	img_colors(main->player->player_addr,main->mini_map->map_img_size_y, main->mini_map->map_img_size_x, color_assignment(0, 255, 0, 0));
}
