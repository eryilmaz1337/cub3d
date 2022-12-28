/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:58:03 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 16:52:04 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	ft_close(void)// şimdilik kapatmak için
{
	exit (0);
	return (0);
}

int	is_wall(t_cub3d *main, double x, double y, char c)
{
	x /= main->mini_map->map_img_size_x;
	y /= main->mini_map->map_img_size_y;
	// if (main->map->map[y][x] != c)
	// 	if (main->map->map[y][x + (int)((double)MINI_MAP_WIDTH / (double)(main->map->map_max_line))] != c)
	// 		if (main->map->map[y + (int)((double)MINI_MAP_HEIGHT / (double)main->map->map_lines_num)][x] != c)
	// 			if (main->map->map[y + (int)((double)MINI_MAP_HEIGHT / (double)main->map->map_lines_num)][x + (int)((double)MINI_MAP_WIDTH / (double)(main->map->map_max_line))] != c)
	// 				return (0);
	printf("x:%d y:%d MX:%0.2f MY:%0.2f\n", (int)x, (int)y, main->player->player_x, main->player->player_y);
	//printf("%c\n", main->map->map[y + p_y][x + p_x]);
	if (main->map->map[(int)y][(int)x] == c)
	{
		printf("WHTYUk\n");
		return (1);
	}
	return (0);
}

int	loop_test(t_cub3d *main)
{
	double	x;
	double	y;
	int		status;

	status = 1;
	x = main->player->player_x;
	y = main->player->player_y;

	if (main->player->key_w)
	{
		x += cos(angle_to_radyan(main->player->angle));
		y += -1 * sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y, '1'))
			status = 0;
	}
	if (main->player->key_a)
	{
		x += -1 * sin(angle_to_radyan(main->player->angle));
		y -= cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y, '1'))
			status = 0;
	}
	if (main->player->key_s)
	{
		x += -1 * cos(angle_to_radyan(main->player->angle));
		y += sin(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y, '1'))
			status = 0;
	}
	if (main->player->key_d)
	{
		x += sin(angle_to_radyan(main->player->angle));
		y += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, y, '1'))
			status = 0;
	}
	if (main->player->dir_left)
		main->player->angle += MOVE_ANGLE;
	if (main->player->dir_right)
		main->player->angle -= MOVE_ANGLE;
	if (status == 0)
	{
		main->player->player_x = x;
		main->player->player_y = y;
	}
	game_mini_map_paint(main);
	game_put_player(main);
	//printf("x:%0.2f\ty:%0.2f\tAng:%0.2f\n", main->player->player_x, main->player->player_y, main->player->angle);
	//printf("x:%d y:%d MX:%0.2f MY:%0.2f\n", x, y, main->player->player_x, main->player->player_y);
	return (0);
}

void loop_window_and_game(t_cub3d *main)
{
	main_game_img_paint(main);
	game_mini_map_paint(main);
	mlx_hook(main->mlx_window, 2, 1L<<0, &ft_key_press, main);
	mlx_hook(main->mlx_window, 3, 1L<<1, &ft_key_release, main);
	mlx_hook(main->mlx_window, 17, (0L), ft_close, main);
	mlx_loop_hook(main->mlx, loop_test, main);//for loop test
	mlx_loop(main->mlx);
}


int main(int argc, char **argv)
{
	t_cub3d *main;

	main = (t_cub3d *)malloc(sizeof(t_cub3d));
	if(!main)
		exit_free(main, MALLOC_ERROR);
	main->map = (t_cub3d_map *)malloc(sizeof(t_cub3d_map));
	if(!main->map)
		exit_free(main, MALLOC_ERROR);
	map_full_check(argc, argv, main);
	game_window(main);
	loop_window_and_game(main);
	return (EXIT_SUCCESS);
}
