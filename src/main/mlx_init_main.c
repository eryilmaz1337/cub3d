/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:19:17 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/14 18:10:36 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_window_and_game(t_cub3d *main)
{
	

	// mlx_mouse_hide();
	// mlx_mouse_move(main->mlx_window, MOVE_MOUSE_CENTER, MOVE_MOUSE_CENTER);
	put_backscreen(main);
	map_paint(main);
	mlx_hook(main->mlx_window, 2, 1L << 0, &ft_key_press, main);
	mlx_hook(main->mlx_window, 3, 1L << 1, &ft_key_release, main);
	// mlx_hook(main->mlx_window, 6, 0L, &mouse_cursor, main);
	mlx_hook(main->mlx_window, 17, (0L), ft_close, main);
	mlx_loop_hook(main->mlx, move_loop, main);
	mlx_loop(main->mlx);
}

void	mlx_inits(t_cub3d *main)
{
	mlx_variable_init_value(main);
	main->mlx = mlx_init();
	if (!main->mlx)
		exit_free(main, MLX_ERROR_INIT);
	main->mlx_window = mlx_new_window(main->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	if (!main->mlx_window)
		exit_free(main, MLX_ERROR_WINDOW);
	mlx_img_init(main);
	mlx_img_addr_init(main);
	img_colors(main->mini_map_img_adress,
		MINI_MAP_HEIGHT, MINI_MAP_WIDTH, color_assignment(255, 0, 0, 0));
	img_colors(main->player->player_addr,
		main->mini_map->map_img_size_y,
		main->mini_map->map_img_size_x, color_assignment(0, 255, 0, 0));
}
